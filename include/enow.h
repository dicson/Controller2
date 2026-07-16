#ifndef ENOW_H
#define ENOW_H
#include <stdint.h>
#include <freertos/FreeRTOS.h>
#include <freertos/queue.h>
#include <esp_now.h>

// constexpr uint8_t relay1Address[] = {0xa4, 0xf0, 0x0f, 0x8d, 0x02, 0xec};     // 5v relay
// constexpr uint8_t relay2Address[] = {0x70, 0x4b, 0xca, 0x8f, 0xaf, 0x28};     // 70:4b:ca:8f:af:28
constexpr uint8_t pultAddress[] = {0x58, 0x8c, 0x81, 0x52, 0xec, 0x84};       // pult
constexpr uint8_t pumpsensorAddress[] = {0x68, 0x25, 0xdd, 0xfd, 0x24, 0x94}; // pump sensor 68:25:dd:fd:24:94
constexpr uint8_t relay1Address[] = {0x8c, 0x94, 0xdf, 0x4f, 0x84, 0xb8};     // 8c:94:df:4f:84:b8 controller2 relay1
constexpr uint8_t relay2Address[] = {0x8c, 0x94, 0xdf, 0x4e, 0xfa, 0xfc};     // 8c:94:df:4e:fa:fc controller2 relay2

/**
 * @brief Функция обратного вызова, которая выполняется после отправки данных.
 * Используется для отслеживания успешности доставки сообщений.
 *
 * @param tx_info Информация о передаче.
 * @param status Статус доставки (ESP_NOW_SEND_SUCCESS или ESP_NOW_SEND_FAIL).
 */
void OnDataSent(const esp_now_send_info_t *tx_info, esp_now_send_status_t status);

/**
 * @brief Функция обратного вызова, которая выполняется при получении данных по протоколу ESP-NOW.
 * Обрабатывает команды, поступающие от пульта управления (START, STOP, SET_K).
 *
 * @param info Информация о отправителе (включая MAC-адрес).
 * @param incomingData Указатель на входящий буфер данных.
 * @param len Длина полученных данных.
 */
void OnDataRecv(const esp_now_recv_info_t *info, const uint8_t *incomingData, int len);

/**
 * @brief Инициализация протокола ESP-NOW.
 * Настраивает WiFi в режиме станции, регистрирует коллбэки и добавляет пиры (узлы) для связи.
 */
void esp_now_setup();

/**
 * @brief Отправляет команду управления конкретным реле (зоной).
 *
 * @param relay Номер реле или индекс зоны.
 * @param state Состояние (true - включить, false - выключить).
 */
void send_command(int relay, bool state);

/**
 * @brief Отправляет команду управления реле насоса(осмоса) или обновления.
 *
 * @param relay Номер реле.
 * @param state Состояние (true - включить, false - выключить).
 * @param relay_blk Номер блока реле  (по умолчанию 1).
 */
void send_root_command(int relay, bool state, int relay_blk = 1);

extern bool use_pult, use_pump_sensor, lora, esp_now, plant_food;

// Queue handles
extern QueueHandle_t esp_now_queue;
extern QueueHandle_t esp_now_queue_from_pult;
extern QueueHandle_t esp_now_queue_to_pult;
extern QueueHandle_t esp_now_queue_from_sensor;

enum class EnowMessage
{
    NONE,
    OK,
    SEND_FAIL,
    START,
    STOP,
    SET_K,
    PUMP_I
};

typedef struct
{
    EnowMessage status;
    uint8_t mac[6];
} EnowStatusMessage;

typedef struct __attribute__((packed))
{
    int32_t relay;    // номер реле (255 = установка K)
    uint8_t state;    // вкл/выкл
    uint32_t k_value; // коэффициент K (используется при relay == 255)
} struct_message;

typedef struct __attribute__((packed))
{
    int32_t relay; // номер реле (254 сила тока насоса)
    uint8_t state; // вкл/выкл
    float k_value; // сила тока
} struct_message_sensor;

typedef struct __attribute__((packed))
{
    EnowMessage type;
    uint32_t value; // payload (e.g. K value)
} QueuePultMessage;

typedef struct __attribute__((packed))
{
    EnowMessage type;
    float value; // payload (e.g. K value)
} QueueSensorMessage;

typedef struct __attribute__((packed))
{
    uint16_t sync;          // Маркер начала (0xABCD)
    uint8_t state;          // вкл/выкл
    uint8_t pump_state;     // вкл/выкл
    uint8_t osmos_state;    // вкл/выкл
    int32_t current_zone;   // номер реле
    uint32_t time_pass;     // прошло полива зоны
    uint32_t time;          // время полива зоны
    uint32_t prog_pass;     // прошло полива зоны
    uint32_t programm_time; // время полива зоны
    uint32_t k_dw_time;     // коэффициент полива зоны
} struct_message_pult;

const uint16_t SYNC_WORD = 0xABCD;

/**
 * @brief Отправляет полный статус системы на пульт управления.
 *
 * @param toPult Структура с данными о состоянии системы (прогресс, активная зона и т.д.).
 */
void espnow_send_status(const struct_message_pult &toPult);

extern uint32_t k_dw_time;

#endif // ENOW_H