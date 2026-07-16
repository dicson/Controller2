#ifndef AUTO_PUMPS_H
#define AUTO_PUMPS_H

#include <Arduino.h>
#include "enow.h"
#include "constants.h"

// Основные функции управления циклом полива
void pump_setup();
void pump_loop();

// Управление состоянием насосов и воды
void pump_on();
void pump_off();
void dry_water_on();
void clear_water_on();
void zone_on(int i);
void zone_off(int i);

// Обработка сообщений и обновление UI
void handle_messages();
void update_bars(bool resetFlag = false);
void send_status_to_pult(struct_message_pult msg = {SYNC_WORD, 0, 0, 0, 0, 0, 0, 0, 0, 0});

// Вспомогательные функции
void MessageToLog(String Message);
uint32_t getDirtyWaterDurationMs(int zone);

// Глобальные переменные состояния (определены в auto_pumps.cpp)
extern bool system_error_state;
extern bool pump_water_state;
extern int current_zone;
extern TaskHandle_t pultTaskHandle;

// Глобальные переменные настроек и таймеров (определены в других файлах, например settings.cpp)
extern uint32_t dw_time[PUMP_AMOUNT], pump_timers[PUMP_AMOUNT];
extern uint32_t water_pause, programm_time, start_time, zoneTimer, k_dw_time, pump_active_pct;
extern bool pump_state[PUMP_AMOUNT], pump_finished[PUMP_AMOUNT], now_pumping, dryState;
extern int8_t thisH, thisM, thisS;
extern bool show_log;
extern int minutes;

// Функции сохранения (определены в actions.cpp или settings.cpp)
void save_k_dw_time();

#endif // AUTO_PUMPS_H
