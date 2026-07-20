#include <Arduino.h>
#include <lvgl.h>
#include "ui/screens.h"
#include "ui/actions.h"
#include "enow.h"
#include "constants.h"
#include <freertos/queue.h>
#include "lora.h"
#include "auto_pumps.h"

int current_zone = 255;
bool pump_water_state;
bool system_error_state = false;
bool is_paused = false;
bool hand_paused = false;
bool tank_empty = true;
float pump_sensor = 0;
uint32_t program_pause_timer;
TaskHandle_t pultTaskHandle = NULL;
const int limitSwitchPin = 18;          // Ваш пин, куда подключен OUT модуля
const unsigned long debounceDelay = 50; // Время фильтрации (мс)

void send_message_to_pult(void *pvParameters);

/**
 * @brief Выводит текстовое сообщение в последовательный порт.
 * @param Message Текст сообщения для логирования.
 */
void MessageToLog(String Message)
{
    Serial.println(Message);
}

/**
 * @brief Выключает указанную зону полива.
 * @param i Индекс зоны (от 0 до PUMP_AMOUNT-1).
 */
void zone_off(int i)
{
    send_command(i, false);
    Serial.printf("выключить зону %d\n", i + 1);
}

/**
 * @brief Включает указанную зону полива.
 * @param i Индекс зоны (от 0 до PUMP_AMOUNT-1).
 */
void zone_on(int i)
{
    send_command(i, true);
    Serial.printf("включить зону %d\n", i + 1);
}

/**
 * @brief Включает водяной насос и отображает иконку в UI.
 */
void pump_on()
{
    pump_water_state = true;
    send_root_command(PUMP_RELAY, true);
    MessageToLog("включить  насос ");
    lv_obj_remove_flag(objects.pump, LV_OBJ_FLAG_HIDDEN);
}

/**
 * @brief Выключает водяной насос и скрывает иконку в UI.
 */
void pump_off()
{
    pump_water_state = false;
    send_root_command(PUMP_RELAY, false);
    MessageToLog("выключить насос ");
    lv_obj_add_flag(objects.pump, LV_OBJ_FLAG_HIDDEN);
}

/**
 * @brief Начальная настройка системы полива. Конфигурирует состояния зон и создает задачу связи с пультом.
 */
void pump_setup()
{
    // --------------------- КОНФИГУРИРУЕМ ПИНЫ ---------------------
    for (byte i = 0; i < PUMP_AMOUNT; i++)
    { // пробегаем по всем помпам
        pump_finished[i] = true;
        pump_state[i] = !SWITCH_LEVEL;
    }
    pump_state[PUMP_RELAY] = !SWITCH_LEVEL; // выкл

    xTaskCreatePinnedToCore(send_message_to_pult /*Функция задачи*/, "SendMessagesToPult" /* Имя*/,
                            2048 /*Размер стека*/, NULL /*Параметры*/, 1 /*Приоритет*/, &pultTaskHandle /*Дескриптор задачи*/, 0);
    // Включаем внутренний подтягивающий резистор ESP32 к 3.3V
    pinMode(limitSwitchPin, INPUT_PULLUP);
    tank_empty = digitalRead(limitSwitchPin);
    if (tank_empty)
        lv_obj_remove_flag(objects.tank_empty, LV_OBJ_FLAG_HIDDEN);
}

/**
 * @brief Рассчитывает длительность фазы грязной воды в миллисекундах.
 */
uint32_t getDirtyWaterDurationMs(int zone)
{
    if (zone < 0 || zone >= PUMP_AMOUNT)
        return 0;
    // Приведение к uint64_t исключает переполнение при больших значениях dw_time и minutes,
    // а единый порядок операций с calculate_program_time() гарантирует совпадение суммы.
    return (uint64_t)dw_time[zone] * MS_PER_SECOND * minutes * k_dw_time / 100;
}

/**
 * @brief Проверяет таймеры и условия для начала полива зон по очереди.
 */
void periodTick()
{
    for (byte i = 0; i < PUMP_AMOUNT; i++)
    {                            // пробегаем по всем помпам
        if (dw_time[i] > 0       // если грязная вода не ноль
            && !pump_finished[i] // если зона еще не поливалась
            && !now_pumping)     // если никакая зона не включена
        {
            current_zone = i;             //
            pump_state[i] = SWITCH_LEVEL; // зона поливается в данный момент
            pump_timers[i] = millis();    // сброс счетчика полива зоны
            now_pumping = true;           // идет полив
            zone_on(i);
        }
    }
}

/**
 * @brief Контролирует завершение полива зоны и переход к следующей.
 */
void flowTick()
{ // выключение зоны
    for (byte i = 0; i < PUMP_AMOUNT; i++)
    {
        uint32_t dw_t = getDirtyWaterDurationMs(i); // пробегаем по всем помпам
        if (dw_time[i] > 0                          // если время полива больше нуля
            && millis() - pump_timers[i] >= dw_t    // если время полива вышло
            && pump_state[i] == SWITCH_LEVEL)       // если зона поливается в данный момент
        {                                           //
            pump_state[i] = !SWITCH_LEVEL;          // зона не поливается в данный момент                                                    // выключить насос
            zone_off(i);                            // выключить зону
            now_pumping = false;                    // полив остановлен
            zoneTimer = millis();                   // обнуляем таймер паузы между зонами
            pump_finished[i] = true;                // зона помечается политой

            // -----------------------------------------проверка на конец заданий--------------------------------------------
            for (byte n = 0; n < PUMP_AMOUNT; n++)
            {                                            // пробегаем по всем помпам
                if (!pump_finished[n] && dw_time[n] > 0) // если нашли не политую - выходим
                    break;                               //
                if (n == PUMP_AMOUNT - 1)                // если нет не политых
                {
                    lv_bar_set_value(objects.prog_bar, programm_time, LV_ANIM_OFF);
                    lv_label_set_text_fmt(objects.bar_label, "%d:%02d:%02d / %d:%02d:%02d",
                                          thisH, thisM, thisS, thisH, thisM, thisS);
                    update_bars();
                    action_stop(NULL);
                }
            }
            // ---------------------------------------------------------------------------------------------------------------
        }
    }
}

/**
 * @brief Задача FreeRTOS для отправки сообщений на пульт через ESP-NOW или LoRa.
 * @param pvParameters Параметры задачи (не используются).
 */
void send_message_to_pult(void *pvParameters)
{
    struct_message_pult message;

    // Ждём стабилизации WiFi
    vTaskDelay(pdMS_TO_TICKS(3000));

    while (true)
    {
        // Ждем данные из очереди (блокировка до появления данных)
        if (xQueueReceive(esp_now_queue_to_pult, &message, portMAX_DELAY) == pdPASS)
        {
            if (esp_now)
                espnow_send_status(message);
            else
                lora_send_status(message);
        }
    }
}

/**
 * @brief Формирует и отправляет текущий статус системы в очередь для передачи на пульт.
 * @param msg Структура сообщения.
 */
void send_status_to_pult(struct_message_pult msg)
{
    static uint32_t ping_timer;

    if (!use_pult)
        return;
    if (millis() - ping_timer < 1000)
        return;

    // Значения по умолчанию, если функция вызвана без аргументов
    if (msg.sync == SYNC_WORD && msg.time == 0)
    {
        msg.state = false;
        msg.pump_state = pump_water_state;
        msg.osmos_state = !dryState;
        msg.k_dw_time = k_dw_time;
    }

    xQueueSend(esp_now_queue_to_pult, &msg, 0);
    ping_timer = millis();
}

/**
 * @brief Настраивает 3-сегментный градиент индикатора зоны в зависимости от настроек.
 */
void update_zone_bar_style(lv_obj_t *bar, int zone)
{
    static lv_grad_dsc_t bars_grads[PUMP_AMOUNT];
    lv_grad_dsc_t *grad = &bars_grads[zone];

    grad->dir = LV_GRAD_DIR_HOR;
    grad->stops_count = 6;

    // Расчет границ сегментов в 255-масштабе LVGL
    uint8_t active_len = (uint8_t)(255 * pump_active_pct / 100);
    uint8_t idle_len = (255 - active_len) / 2;

    uint8_t start_active = idle_len;
    uint8_t end_active = idle_len + active_len;

    // 1-й сегмент: Покой (Blue)
    grad->stops[0].color = lv_color_hex(0x2196F3);
    grad->stops[0].frac = 0;
    grad->stops[0].opa = LV_OPA_COVER;
    grad->stops[1].color = lv_color_hex(0x2196F3);
    grad->stops[1].frac = start_active;
    grad->stops[1].opa = LV_OPA_COVER;

    // 2-й сегмент: Работа насоса (ZONE_BAR_COLOR_DW)
    grad->stops[2].color = lv_color_hex(ZONE_BAR_COLOR_DW);
    grad->stops[2].frac = start_active;
    grad->stops[2].opa = LV_OPA_COVER;
    grad->stops[3].color = lv_color_hex(ZONE_BAR_COLOR_DW);
    grad->stops[3].frac = end_active;
    grad->stops[3].opa = LV_OPA_COVER;

    // 3-й сегмент: Покой (Blue)
    grad->stops[4].color = lv_color_hex(0x2196F3);
    grad->stops[4].frac = end_active;
    grad->stops[4].opa = LV_OPA_COVER;
    grad->stops[5].color = lv_color_hex(0x2196F3);
    grad->stops[5].frac = 255;
    grad->stops[5].opa = LV_OPA_COVER;
    // Применение нового стиля
    lv_obj_set_style_bg_grad(bar, grad, LV_PART_INDICATOR);
    lv_obj_set_style_bg_opa(bar, LV_OPA_COVER, LV_PART_INDICATOR);
}

/**
 * @brief Форматирует и обновляет текстовую метку общего прогресса.
 */
void update_progress_time_label(uint32_t prog_pass_ms)
{
    static uint32_t last_label_update = 0;
    if (millis() - last_label_update < 1000)
        return;
    last_label_update = millis();

    uint32_t allSeconds = prog_pass_ms / 1000;
    int8_t H = (allSeconds / 3600) % 24;
    int8_t M = (allSeconds / 60) % 60;
    int8_t S = allSeconds % 60;

    lv_label_set_text_fmt(objects.bar_label, "%d:%02d:%02d / %d:%02d:%02d",
                          H, M, S, thisH, thisM, thisS);
}

/**
 * @brief Обновляет графические индикаторы (бары) зон и прогресса в UI, а также отправляет статус на пульт.
 */
void update_bars(bool resetFlag)
{
    static int last_zone_styled = -1;
    static uint32_t last_ui_update = 0;

    // Если передан флаг сброса, обнуляем переменную
    if (resetFlag)
    {
        last_zone_styled = -1;
        return;
    }

    // Ограничение частоты обновления UI (20 Гц)
    if (millis() - last_ui_update < 50)
    {
        return;
    }
    last_ui_update = millis();

    if (current_zone >= PUMP_AMOUNT || lv_obj_has_flag(objects.stop, LV_OBJ_FLAG_HIDDEN))
    {
        send_status_to_pult();
        return;
    }

    // 1. Расчет таймингов
    uint32_t prog_pass = millis() - start_time;
    if (prog_pass > programm_time)
        prog_pass = programm_time;

    uint32_t time = getDirtyWaterDurationMs(current_zone);
    uint32_t time_pass = millis() - pump_timers[current_zone] + 50;
    if (time_pass > time)
        time_pass = time;

    // 2. Обновление UI Баров
    lv_obj_t *bar = lv_obj_get_child(objects.bars_panel, current_zone);

    if (current_zone != last_zone_styled && plant_food)
    {
        update_zone_bar_style(bar, current_zone);
        last_zone_styled = current_zone;
    }

    lv_bar_set_value(bar, map(time_pass, 0, time, 0, 100), LV_ANIM_OFF);
    lv_bar_set_value(objects.prog_bar, prog_pass, LV_ANIM_OFF);

    // 3. Текстовая информация и синхронизация
    update_progress_time_label(prog_pass);

    struct_message_pult message1 = {SYNC_WORD, 1, (uint8_t)pump_water_state, (uint8_t)!dryState, (int32_t)current_zone,
                                    time_pass, time, prog_pass, programm_time, k_dw_time};
    send_status_to_pult(message1);
}

/**
 * @brief Обрабатывает входящие сообщения из очередей ESP-NOW (ошибки передачи и команды с пульта).
 */
void handle_messages()
{
    EnowStatusMessage msg;
    if (xQueueReceive(esp_now_queue, &msg, 0) == pdPASS)
    {
        if (msg.status == EnowMessage::SEND_FAIL)
        {
            // Уходим в ошибку только если не удалось достучаться до реле (игнорируем ошибки связи с пультом)
            bool is_relay1 = (memcmp(msg.mac, relay1Address, 6) == 0);
            bool is_relay2 = (memcmp(msg.mac, relay2Address, 6) == 0);

            if ((is_relay1 || is_relay2) && minutes == REAL_TIME_MINUTES)
            {
                if (!system_error_state)
                {
                    system_error_state = true;
                    analogWrite(2, 70); // Снижаем яркость подсветки

                    // Пытаемся найти метку внутри контейнера message_box и обновить текст
                    lv_obj_t *label = lv_obj_get_child(objects.message_box, 0);
                    if (label)
                    {
                        lv_label_set_text_fmt(label, "Связь потеряна: %s\n\nПерезапустите систему.",
                                              is_relay1 ? "реле 1" : "реле 2");
                    }

                    lv_obj_remove_flag(objects.message_box, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(objects.stop, LV_OBJ_FLAG_HIDDEN);
                    MessageToLog("Ошибка связи с " + String(is_relay1 ? "relay1" : "relay2"));
                }
            }
        }
    }

    QueuePultMessage qpMsg;
    if (xQueueReceive(esp_now_queue_from_pult, &qpMsg, 0) == pdPASS)
    {
        if (esp_now && use_pult)
        {
            if (qpMsg.type == EnowMessage::START)
                action_start(NULL);
            if (qpMsg.type == EnowMessage::STOP)
                action_stop(NULL);
            if (qpMsg.type == EnowMessage::SET_K)
            {
                k_dw_time = qpMsg.value;
                save_k_dw_time();
            }
        }
    }
}

/**
 * @brief Контролирует включение и выключение насоса в зависимости от прогресса полива зоны.
 */
void pump_control_tick()
{
    if (!plant_food || !now_pumping || current_zone < 0 || current_zone >= PUMP_AMOUNT)
    {
        if (pump_water_state)
        {
            pump_off();
        }
        return;
    }

    uint32_t total_t = getDirtyWaterDurationMs(current_zone);
    if (total_t == 0)
    {
        if (pump_water_state)
        {
            pump_off();
        }
        return;
    }

    uint32_t elapsed = millis() - pump_timers[current_zone];

    // Расчет времени работы насоса на основе процента
    uint32_t active_duration = (uint32_t)((uint64_t)total_t * pump_active_pct / 100);
    uint32_t off_duration_total = total_t - active_duration;
    uint32_t start_offset = off_duration_total / 2;

    if (elapsed >= start_offset && elapsed < (start_offset + active_duration))
    {
        if (!pump_water_state)
        {
            pump_on();
        }
    }
    else
    {
        if (pump_water_state)
        {
            pump_off();
        }
    }
}

/**
 * @brief Приостанавливает программу полива.
 */
void program_pause()
{
    if (!now_pumping)
        return;
    lv_label_set_text(objects.pause_btn_label, " Продолжить");
    lv_obj_set_style_bg_color(objects.pause_btn, lv_palette_main(LV_PALETTE_ORANGE), LV_PART_MAIN);
    lv_obj_set_style_bg_color(objects.prog_bar, lv_palette_main(LV_PALETTE_ORANGE), LV_PART_INDICATOR);
    program_pause_timer = millis();
    zone_off(current_zone);
    pump_off();
}

/**
 * @brief Возобновляет программу полива.
 */
void program_resume()
{
    if (!now_pumping)
        return;
    lv_label_set_text(objects.pause_btn_label, " Пауза");
    lv_obj_remove_local_style_prop(objects.pause_btn, LV_STYLE_BG_COLOR, LV_PART_MAIN);
    lv_obj_remove_local_style_prop(objects.prog_bar, LV_STYLE_BG_COLOR, LV_PART_INDICATOR);
    pump_timers[current_zone] = pump_timers[current_zone] + (millis() - program_pause_timer);
    start_time += (millis() - program_pause_timer);
    zone_on(current_zone);
}

/**
 * @brief Опрос датчика уровня воды с антидребезгом.
 * @return true, если бак пуст, иначе false.
 */
bool update_tank_sensor_debounced()
{
    static bool lastState = LOW;
    static bool stableState = HIGH;
    static unsigned long lastDebounceTime = 0;

    bool currentState = digitalRead(limitSwitchPin);

    if (currentState != lastState)
    {
        lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > debounceDelay)
    {
        if (currentState != stableState)
        {
            stableState = currentState;
        }
    }

    lastState = currentState;
    return (stableState == HIGH); // true, если бак пуст
}

/**
 * @brief Обновление UI во время паузы (таймер).
 */
void update_tank_pause_ui(uint32_t pause_ms, uint32_t pause_pass)
{
    static uint32_t last_label_update = 0;
    if (millis() - last_label_update < 1000)
        return;
    last_label_update = millis();

    uint32_t allSeconds = (pause_ms - pause_pass) / 1000;
    int8_t H = (allSeconds / 3600) % 24;
    int8_t M = (allSeconds / 60) % 60;
    int8_t S = allSeconds % 60;
    lv_label_set_text_fmt(objects.tank_time, "%d:%02d:%02d",
                          H, M, S);
    lv_bar_set_value(objects.pause_bar, pause_pass, LV_ANIM_OFF);
}

/**
 * @brief Управление паузой полива при пустом баке.
 * @param tank_is_empty Текущее состояние датчика бака.
 */
void handle_tank_pause(bool tank_is_empty)
{
    if (tank_is_empty)
    {
        if (now_pumping && !is_paused && !hand_paused)
        {
            is_paused = true;
            program_pause();
            lv_obj_remove_flag(objects.tank, LV_OBJ_FLAG_HIDDEN);
            lv_bar_set_range(objects.pause_bar, 0, (uint64_t)water_pause * MS_PER_SECOND * minutes);
        }
    }
    if (is_paused && !hand_paused)
    {
        uint32_t pause_ms = (uint64_t)water_pause * MS_PER_SECOND * minutes;
        uint32_t pause_pass = millis() - program_pause_timer;

        if (pause_pass >= pause_ms)
        {
            is_paused = false;
            program_resume();
            lv_obj_add_flag(objects.tank, LV_OBJ_FLAG_HIDDEN);
        }
        else
            update_tank_pause_ui(pause_ms, pause_pass);
    }
}

/**
 * @brief Основная функция опроса и обработки состояния датчика бака.
 */
void check_tank_sensor()
{
    bool tank_is_empty = update_tank_sensor_debounced();

    // Обновление глобального состояния и UI
    tank_empty = tank_is_empty;
    if (tank_empty)
        lv_obj_remove_flag(objects.tank_empty, LV_OBJ_FLAG_HIDDEN);
    else
        lv_obj_add_flag(objects.tank_empty, LV_OBJ_FLAG_HIDDEN);

    handle_tank_pause(tank_is_empty);
}

/**
 * @brief Основной цикл управления помпами. Выполняет логику полива, обновление UI и обработку сообщений.
 */
void pump_loop()
{
    if (system_error_state)
    {
        // В состоянии ошибки разрешены только обновления интерфейса или критические проверки, логика насоса отключена
        return;
    }
    if (!is_paused)
    {
        periodTick();
        flowTick();
        pump_control_tick();
        update_bars();
    }
    check_tank_sensor();
    handle_messages();
}
