#include <Arduino.h>
#include <HardwareSerial.h>
#include <cstring>
#include "ui/actions.h"
#include "enow.h"
#include "lora.h"

#define RX2_PIN 17
#define TX2_PIN 18

HardwareSerial LoraSerial(1); // Используем UART1

#define MAX_BUF 64    // Максимальная длина команды
char buffer[MAX_BUF]; // Массив для хранения байтов
int pos = 0;          // Текущая позиция в массиве

void processCommand(char *cmd)
{
    Serial.print("Получено через LoRa: ");
    Serial.println(cmd);

    // Сравнение строк
    if (strcmp(cmd, "START") == 0)
    {
        Serial.println("Команда: START");
        action_start(NULL);
        return;
    }

    if (strcmp(cmd, "STOP") == 0)
    {
        Serial.println("Команда: STOP");
        action_stop(NULL);
        return;
    }

    // Парсинг команд вида "K <значение>"
    char *spacePtr = strchr(cmd, ' ');
    if (spacePtr != NULL)
    {
        *spacePtr = '\0'; // Временно разделяем строку
        if (strcmp(cmd, "K") == 0)
        {
            Serial.print("Значение K: ");
            Serial.println(spacePtr + 1);
            const char *myString = (spacePtr + 1);
            k_dw_time = strtoul(myString, NULL, 10); // 10 - основание системы счисления (десятичная)
            save_k_dw_time();
        }
        *spacePtr = ' '; // Восстанавливаем строку (опционально)
    }
}

void lora_setup()
{
    LoraSerial.begin(9600, SERIAL_8N1, RX2_PIN, TX2_PIN);
    while (LoraSerial.available())
        LoraSerial.read(); // Очистка буфера от мусора при старте
    Serial.printf("LoRa инициализирована. UART на пинах RX:%d, TX:%d, 9600 бод.\n", RX2_PIN, TX2_PIN);
}

void lora_loop()
{
    if (!lora || !use_pult)
        return;
    while (LoraSerial.available() > 0)
    {
        char inChar = (char)LoraSerial.read();

        // Обработка конца строки (\n или \r)
        if (inChar == '\n' || inChar == '\r')
        {
            if (pos > 0)
            {
                buffer[pos] = '\0';
                processCommand(buffer);
                pos = 0;
            }
        }
        // Добавление символа в буфер с защитой от переполнения
        else if (pos < MAX_BUF - 1)
        {
            buffer[pos] = inChar;
            pos++;
        }
        else
        {
            // Буфер переполнен - сбрасываем, чтобы не застрять в невалидном состоянии
            Serial.println("Ошибка: Буфер LoRa переполнен!");
            pos = 0;
        }
    }
}

// Функция для заполнения и отправки структуры
void lora_send_status(const struct_message_pult &toPult)
{
    // Отправка структуры как набора байтов
    LoraSerial.write((uint8_t *)&toPult, sizeof(toPult));
    LoraSerial.flush(); // Дожидаемся окончания отправки
}
