#include "display.h"
#include <Arduino.h>

// Инициализация объектов
TAMC_GT911 ts(TOUCH_GT911_SDA, TOUCH_GT911_SCL, TOUCH_GT911_INT, TOUCH_GT911_RST,
              max(TOUCH_MAP_X1, TOUCH_MAP_X2), max(TOUCH_MAP_Y1, TOUCH_MAP_Y2));

Arduino_ESP32RGBPanel rgbpanel(
    41 /* DE */, 40 /* VSYNC */, 39 /* HSYNC */, 42 /* PCLK */,
    14 /* R0 */, 21 /* R1 */, 47 /* R2 */, 48 /* R3 */, 45 /* R4 */,
    9 /* G0 */, 46 /* G1 */, 3 /* G2 */, 8 /* G3 */, 16 /* G4 */, 1 /* G5 */,
    15 /* B0 */, 7 /* B1 */, 6 /* B2 */, 5 /* B3 */, 4 /* B4 */,
    0 /* hsync_polarity */, 210 /* hsync_front_porch */, 30 /* hsync_pulse_width */, 16 /* hsync_back_porch */,
    0 /* vsync_polarity */, 22 /* vsync_front_porch */, 13 /* vsync_pulse_width */, 10 /* vsync_back_porch */,
    true /* pclk_active_neg */, 8000000 /* prefer_speed */);

Arduino_RGB_Display gfx(800, 480, &rgbpanel, ROTATION /* поворот */, true);

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
    gfx.draw16bitRGBBitmap(area->x1, area->y1, (uint16_t *)px_map, w, h);
    lv_display_flush_ready(disp);
}

void my_touchpad_read(lv_indev_t *indev, lv_indev_data_t *data)
{
    ts.read();        // Чтение данных о касании
    if (ts.isTouched) // Проверка, коснулись ли экрана
    {
        for (int i = 0; i < ts.touches; i++) // Перебор всех обнаруженных точек касания
        {
            // Можно использовать первое касание (или другую логику для нескольких касаний)
            if (i == 0)
            {
                data->state = LV_INDEV_STATE_PRESSED;
                data->point.x = ts.points[i].x; // Получение координаты X
                data->point.y = ts.points[i].y; // Получение координаты Y
            }
        }
        if (ledcRead(GFX_BL) == 0)
        {
            // ledcWrite(GFX_BL, GFX_BL_VALUE);
            analogWrite(GFX_BL, GFX_BL_VALUE);
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
    gfx.begin(8000000);
    gfx.setRotation(ROTATION);

    ts.begin();
    if (ROTATION == 0)
        ts.setRotation(1);
    else
        ts.setRotation(3);

    lv_init();
    lv_tick_set_cb(millis_cb);

    uint32_t screenWidth = gfx.width();
    uint32_t screenHeight = gfx.height();

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
        analogWrite(GFX_BL, duty);
        delay(3);
    }
}
void revert_display()
{
    if (ROTATION == 0)
    {
        gfx.setRotation(2);
        ts.setRotation(3);
        ROTATION = 2;
    }
    else
    {
        gfx.setRotation(0);
        ts.setRotation(1);
        ROTATION = 0;
    }
}

void loop_display()
{
    lv_task_handler();
    delay(4);
    // Простое управление простоем (требуется проверка согласованности analogRead/Write)
    if (lv_display_get_inactive_time(disp) > GFX_BL_TIME * 1000)
    {
        analogWrite(GFX_BL, 0);
    }
}
