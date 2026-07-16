#include <WiFi.h>
#include <esp_wifi.h>
#include <lvgl.h>
#include "ui/screens.h"
#include "enow.h"
#include "constants.h"

// Дескрипторы очередей для обмена данными между задачами и прерываниями
QueueHandle_t esp_now_queue;
QueueHandle_t esp_now_queue_from_pult;
QueueHandle_t esp_now_queue_to_pult;
QueueHandle_t esp_now_queue_from_sensor;

// Флаг: ESP-NOW полностью инициализирован и готов к работе
static bool esp_now_ready = false;

extern void save_k_dw_time();

void OnDataRecv(const esp_now_recv_info_t *info, const uint8_t *incomingData, int len)
{
    if (info == NULL || info->src_addr == NULL || incomingData == NULL)
        return;

    // Проверяем, что данные пришли именно от пульта и пульт разрешен в настройках
    if (memcmp(info->src_addr, pultAddress, 6) == 0 && !use_pult)
        return;

    // Обработка сообщений от датчика насоса
    if (memcmp(info->src_addr, pumpsensorAddress, 6) == 0)
    {
        // Игнорируем, если датчик тока запрещен в настройках
        if (!use_pump_sensor)
            return;

        struct_message_sensor fromSensor;
        if (len != sizeof(fromSensor))
            return;
        memcpy(&fromSensor, incomingData, sizeof(fromSensor));
        QueueSensorMessage qMsg;
        // Команда от датчика насоса (используется спец. номер реле 254)
        if (fromSensor.relay == 254)
        {
            qMsg.type = EnowMessage::PUMP_I;
            qMsg.value = fromSensor.k_value;
            xQueueSendFromISR(esp_now_queue_from_sensor, &qMsg, NULL);
            return;
        }
    }
    struct_message fromPult;
    if (len != sizeof(fromPult))
        return;

    memcpy(&fromPult, incomingData, sizeof(fromPult));

    QueuePultMessage qMsg;
    qMsg.type = EnowMessage::NONE;
    qMsg.value = 0;

    // Команда установки коэффициента K (используется спец. номер реле 255)
    if (fromPult.relay == 255)
    {
        qMsg.type = EnowMessage::SET_K;
        qMsg.value = fromPult.k_value;
        xQueueSendFromISR(esp_now_queue_from_pult, &qMsg, NULL);
        return;
    }

    // Обработка команд СТАРТ и СТОП
    if (fromPult.relay == 0 && fromPult.state == false)
        qMsg.type = EnowMessage::STOP;
    else if (fromPult.relay == 1 && fromPult.state == true)
        qMsg.type = EnowMessage::START;

    if (qMsg.type != EnowMessage::NONE)
        xQueueSendFromISR(esp_now_queue_from_pult, &qMsg, NULL);
}

void OnDataSent(const esp_now_send_info_t *tx_info, esp_now_send_status_t status)
{
    EnowStatusMessage msg;
    msg.status = (status == ESP_NOW_SEND_SUCCESS) ? EnowMessage::OK : EnowMessage::SEND_FAIL;
    if (tx_info != NULL)
    {
        memcpy(msg.mac, tx_info->des_addr, 6);
    }
    else
    {
        memset(msg.mac, 0, 6);
    }
    xQueueSendFromISR(esp_now_queue, &msg, NULL);
}

void esp_now_setup()
{
    // Создание очередей для межзадачного взаимодействия.
    // Делаем это до любой возможности раннего возврата, иначе задача send_message_to_pult,
    // запущенная в pump_setup(), получит NULL-дескриптор очереди и приведёт к крашу.
    esp_now_queue = xQueueCreate(2, sizeof(EnowStatusMessage));
    esp_now_queue_from_pult = xQueueCreate(2, sizeof(QueuePultMessage));
    esp_now_queue_to_pult = xQueueCreate(2, sizeof(struct_message_pult));
    esp_now_queue_from_sensor = xQueueCreate(2, sizeof(QueueSensorMessage));

    // Настройка устройства как Wi-Fi станции (обязательно для ESP-NOW)
    WiFi.mode(WIFI_STA);
    WiFi.enableAP(false);

    if (esp_now_init() != ESP_OK)
    {
        return;
    }

    //uint8_t newMACAddress[] = {0x98, 0x88, 0xe0, 0x04, 0xe2, 0x48}; // pump-controller
    uint8_t newMACAddress[] = {0x58, 0xe6, 0xc5, 0x71, 0x2d, 0x34}; // controller2 58:e6:c5:71:2d:34
    esp_wifi_set_mac(WIFI_IF_STA, &newMACAddress[0]);

    // Устанавливаем канал 1 для совпадения с другими устройствами
    esp_wifi_set_channel(1, WIFI_SECOND_CHAN_NONE);

    // Регистрация функций обратного вызова
    esp_now_register_recv_cb(OnDataRecv);
    esp_now_register_send_cb(OnDataSent);

    // Регистрация узла реле 1
    esp_now_peer_info_t peerInfo = {};
    memcpy(peerInfo.peer_addr, relay1Address, 6);
    peerInfo.channel = 0;
    peerInfo.encrypt = false;

    esp_now_add_peer(&peerInfo);

    // Регистрация узла реле 2
    memset(&peerInfo, 0, sizeof(peerInfo));
    memcpy(peerInfo.peer_addr, relay2Address, 6);
    peerInfo.channel = 0;
    peerInfo.encrypt = false;

    esp_now_add_peer(&peerInfo);
    // Регистрация конкретного адреса пульта
    memset(&peerInfo, 0, sizeof(peerInfo));
    memcpy(peerInfo.peer_addr, pultAddress, 6);
    peerInfo.channel = 0;
    peerInfo.encrypt = false;

    esp_now_add_peer(&peerInfo);

    // Регистрация общего широковещательного адреса для входящих пакетов
    memset(&peerInfo, 0, sizeof(peerInfo));
    uint8_t broadcast_mac[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    memcpy(peerInfo.peer_addr, broadcast_mac, 6);
    peerInfo.channel = 0;
    peerInfo.encrypt = false;

    esp_now_add_peer(&peerInfo);
    // Регистрация конкретного адреса датчика насоса
    memset(&peerInfo, 0, sizeof(peerInfo));
    memcpy(peerInfo.peer_addr, pumpsensorAddress, 6);
    peerInfo.channel = 0;
    peerInfo.encrypt = false;

    esp_now_add_peer(&peerInfo);

    // Очереди созданы в начале функции, здесь только отмечаем готовность ESP-NOW.
    esp_now_ready = true;
}

void send_root_command(int relay, bool state, int relay_blk)
{
    struct_message myData = {};
    myData.relay = relay;
    myData.state = state;
    if (relay_blk == 2)
        esp_now_send(relay2Address, (uint8_t *)&myData, sizeof(myData));
    else
        esp_now_send(relay1Address, (uint8_t *)&myData, sizeof(myData));
}

void send_command(int relay, bool state)
{
    struct_message myData = {};
    myData.relay = relay;
    myData.state = state;
    if (relay < RELAY_BLOCK_SPLIT)
        esp_now_send(relay1Address, (uint8_t *)&myData, sizeof(myData));
    else
    {
        myData.relay = relay - RELAY2_OFFSET;
        esp_now_send(relay2Address, (uint8_t *)&myData, sizeof(myData));
    }
}

void espnow_send_status(const struct_message_pult &toPult)
{
    if (!esp_now_ready)
    {
        return;
    }

    // Копируем данные в локальный буфер для безопасной отправки
    uint8_t send_buffer[sizeof(toPult)];
    memcpy(send_buffer, &toPult, sizeof(toPult));

    esp_now_send(pultAddress, send_buffer, sizeof(send_buffer));
}
