#ifndef LORA_H
#define LORA_H

#include <stdint.h>
#include "enow.h" // Для доступа к struct_message_pult


extern bool use_pult;
extern void save_k_dw_time();
extern uint32_t k_dw_time;

/**
 * @brief Инициализация модуля LoRa через UART.
 * Настраивает последовательный порт на пинах RX:17, TX:18 со скоростью 9600 бод.
 */
void lora_setup();

/**
 * @brief Основной цикл обработки данных LoRa.
 * Считывает входящие символы из UART, собирает их в команды и передает на обработку.
 * Работает только если активны флаги 'lora' и 'use_pult'.
 */
void lora_loop();

/**
 * @brief Отправляет текущий статус системы на пульт через LoRa.
 * 
 * @param toPult Структура с данными о состоянии системы.
 */
void lora_send_status(const struct_message_pult &toPult);

/**
 * @brief Внутренняя обработка текстовых команд, полученных по LoRa (START, STOP, K <значение>).
 * 
 * @param cmd Указатель на строку с командой.
 */
void processCommand(char *cmd);

#endif // LORA_H
