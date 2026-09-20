#include "display.h"
#include <Arduino.h>

#include <LovyanGFX.hpp>
#include <lgfx_user/LGFX_Sunton_ESP32-8048S070.h>

LGFX lcd;

lv_display_t *disp;
static lv_color_t *disp_draw_buf;

uint32_t millis_cb(void)
{
    return millis();
}

void my_disp_flush(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map)
{
    uint32_t w = lv_area_get_width(area);
    uint32_t h = lv_area_get_height(area);

    // Быстрая пересылка кадра через LovyanGFX
    lcd.pushImageDMA(area->x1, area->y1, w, h, (uint16_t *)px_map);

    lv_display_flush_ready(disp);
}

void my_touchpad_read(lv_indev_t *indev, lv_indev_data_t *data)
{
    int16_t x, y;
    if (lcd.getTouch(&x, &y))
    {
        data->state = LV_INDEV_STATE_PRESSED;
        data->point.x = x;
        data->point.y = y;

        if (lcd.getBrightness() == 0)
        {
            lcd.setBrightness(GFX_BL_VALUE);
            lv_indev_wait_release(indev);
        }
    }
    else
    {
        data->state = LV_INDEV_STATE_RELEASED;
    }
}

void setup_display()
{
    Serial.println("Initializing display...");
    // Получаем указатель на панель и её шину
    auto panel = lcd.getPanel();
    auto bus = (lgfx::Bus_RGB *)panel->getBus();
    // Читаем конфигурацию шины
    auto cfg = bus->config();
    // Меняем частоту (например, снижаем до 9 МГц для стабильности или поднимаем до 80 МГц)
    cfg.freq_write = 8000000;
    // Записываем конфигурацию обратно
    bus->config(cfg);

    lcd.setBrightness(0);
    lcd.init();
    lcd.setRotation(ROTATION);
    lcd.setSwapBytes(true);

    lv_init();
    lv_tick_set_cb(millis_cb);

    uint32_t screenWidth = lcd.width();
    uint32_t screenHeight = lcd.height();

    // Расчет фиксированного размера буфера (в байтах)
    uint32_t bufSizeInBytes = screenWidth * screenHeight * sizeof(lv_color_t);

    disp_draw_buf = (lv_color_t *)heap_caps_aligned_alloc(64, bufSizeInBytes, MALLOC_CAP_SPIRAM);
    if (!disp_draw_buf)
    {
        Serial.println("Failed to allocate display buffer!");
        return;
    }

    disp = lv_display_create(screenWidth, screenHeight);
    lv_display_set_flush_cb(disp, my_disp_flush);
    lv_display_set_buffers(disp, disp_draw_buf, NULL, bufSizeInBytes, LV_DISPLAY_RENDER_MODE_PARTIAL);

    lv_indev_t *indev = lv_indev_create();
    lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
    lv_indev_set_read_cb(indev, my_touchpad_read);
    Serial.println("Display setup complete.");

    ui_init();
    lv_timer_handler(); // Принудительная отрисовка первого кадра
    // Плавное включение подсветки
    for (int duty = 0; duty <= GFX_BL_VALUE; duty++)
    {
        lcd.setBrightness(duty);
        delay(3);
    }
}
void revert_display()
{
    if (ROTATION == 0)
    {
        lcd.setRotation(2);
        ROTATION = 2;
    }
    else
    {
        lcd.setRotation(0);
        ROTATION = 0;
    }
}

void loop_display()
{
    uint32_t time_till_next = lv_timer_handler();
    delay(time_till_next > 5 ? 5 : time_till_next); // Не блокируем процессоры длинными delay

    if (lv_display_get_inactive_time(disp) > GFX_BL_TIME * 1000)
        lcd.setBrightness(0);
}
