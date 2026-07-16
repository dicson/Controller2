#include <lvgl.h>
#include <Preferences.h>
#include "constants.h"
#include "ui/screens.h"

#define RW_MODE false
#define RO_MODE true

uint32_t GFX_BL_VALUE, GFX_BL_TIME;     // яркость, время подсветки экрана
uint32_t dw_time[PUMP_AMOUNT];          // время полива грязной водой
uint32_t pump_timers[PUMP_AMOUNT];      // таймеры зон
bool pump_state[PUMP_AMOUNT];           // состояние помпы
bool pump_finished[PUMP_AMOUNT];        // зона уже полита
uint32_t water_pause;                   // пауза между зонами
uint32_t zoneTimer;                     // таймер паузы
bool now_pumping = false;               // идет полив
bool dryState = true;                   // какой клапан открыт. true - dry(грязная) false - чистая
uint32_t k_dw_time = DEFAULT_K_DW_TIME; // коэффициент
uint32_t pump_active_pct;               // процент работы насоса
int minutes = DEFAULT_MINUTES;          // отладка
int ROTATION = 0;                       // поворот экрана
bool use_pult, use_pump_sensor, lora, esp_now, plant_food;
extern void update_zone_list();

Preferences settings;

void setup_settings()
{
    settings.begin("Settings", RO_MODE);
    bool tpInit = settings.isKey("nvsInit");

    if (!tpInit)
    {
        settings.end();
        settings.begin("Settings", RW_MODE);

        settings.putInt("ROTATION", 0);
        settings.putLong("GFX_BL_VALUE", DEFAULT_GFX_BL_VALUE);
        settings.putLong("GFX_BL_TIME", DEFAULT_GFX_BL_TIME);
        settings.putLong("water_pause", DEFAULT_WATER_PAUSE);
        settings.putLong("k_dw_time", DEFAULT_K_DW_TIME);

        // Обнуление глобальных массивов и их сохранение
        memset(dw_time, 0, sizeof(dw_time));

        settings.putBytes("dw_time", dw_time, sizeof(dw_time));
        settings.putBool("use_pult", false);
        settings.putBool("lora", false);
        settings.putBool("esp_now", true);

        settings.putBool("nvsInit", true);
        settings.end();
        settings.begin("Settings", RO_MODE);
    }

    ROTATION = settings.getInt("ROTATION");
    water_pause = settings.getLong("water_pause");
    GFX_BL_VALUE = settings.getLong("GFX_BL_VALUE");
    GFX_BL_TIME = settings.getLong("GFX_BL_TIME");
    k_dw_time = settings.getLong("k_dw_time");
    pump_active_pct = settings.getLong("pump_active_pct", DEFAULT_PUMP_ACTIVE_PCT);
    use_pult = settings.getBool("use_pult");
    use_pump_sensor = settings.getBool("use_pump_sensor");
    lora = settings.getBool("lora");
    esp_now = settings.getBool("esp_now");
    plant_food = settings.getBool("plant_food");

    settings.getBytes("dw_time", dw_time, sizeof(dw_time));
    settings.end();
}

void fill_widgets()
{
    /* Расширение области нажатия с помощью констант */
    lv_obj_set_ext_click_area(objects.pult, EXT_CLICK_AREA_SMALL);
    lv_obj_set_ext_click_area(objects.debug, EXT_CLICK_AREA_SMALL);
    lv_obj_set_ext_click_area(objects.bl, EXT_CLICK_AREA_SMALL);
    lv_obj_set_ext_click_area(objects.button_10, EXT_CLICK_AREA_LARGE);
    lv_obj_set_ext_click_area(objects.button_dec, EXT_CLICK_AREA_LARGE);
    lv_obj_set_ext_click_area(objects.button_reset, EXT_CLICK_AREA_LARGE);
    lv_obj_set_ext_click_area(objects.button_inc, EXT_CLICK_AREA_LARGE);
    lv_obj_set_ext_click_area(objects.button10, EXT_CLICK_AREA_LARGE);

    if (use_pult)
    {
        lv_obj_add_state(objects.pult, LV_STATE_CHECKED);
        lv_obj_remove_flag(objects.esp_lora, LV_OBJ_FLAG_HIDDEN);
    }
    if (esp_now)
        lv_obj_add_state(objects.esp_now, LV_STATE_CHECKED);
    lv_obj_set_radio_button(objects.esp_now, true);
    if (lora)
        lv_obj_add_state(objects.lora, LV_STATE_CHECKED);
    if (plant_food)
        lv_obj_add_state(objects.plant_food, LV_STATE_CHECKED);
    lv_obj_set_radio_button(objects.lora, true);
    lv_slider_set_value(objects.bl, GFX_BL_VALUE, LV_ANIM_OFF);
    lv_textarea_set_text(objects.bl_idle, String(GFX_BL_TIME).c_str());
    lv_textarea_set_text(objects.pause, String(water_pause).c_str());
    lv_label_set_text(objects.k_dw_time, String(k_dw_time).c_str());

    for (int i = 0; i < PUMP_AMOUNT; i++)
    {
        lv_obj_t *button = lv_obj_get_child(objects.zone_times, i);

        lv_obj_t *dw = lv_obj_get_child(button, 1);
        lv_label_set_text(dw, String(dw_time[i]).c_str());
        lv_obj_set_ext_click_area(dw, EXT_CLICK_AREA_SMALL);

        if (dw_time[i] != 0)
            lv_obj_set_style_bg_opa(button, FULL_OPACITY, LV_PART_MAIN);
        else
            lv_obj_set_style_bg_opa(button, LOW_OPACITY, LV_PART_MAIN);
    }
    update_zone_list();

    // Настраиваем выравнивание табов в настройках
    lv_obj_t *tab_bar = lv_tabview_get_tab_bar(objects.settings_tv);
    uint32_t i;
    for (i = 0; i < lv_obj_get_child_count(tab_bar); i++)
    {
        lv_obj_t *btn = lv_obj_get_child(tab_bar, i);
        lv_obj_set_flex_align(btn, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
        // Добавляем отступ слева, чтобы текст не прижимался к краю
        lv_obj_set_style_pad_left(btn, 10, 0);
    }
    // Получаем кнопку конкретной вкладки по её индексу (например, индекс 1 — вторая вкладка)
    lv_obj_t *tab_btn = lv_obj_get_child(tab_bar, 2);
    // Скрываем кнопку
    lv_obj_add_flag(tab_btn, LV_OBJ_FLAG_HIDDEN);
    // Получаем контейнер с контентом страниц
    lv_obj_t *tab_content = lv_tabview_get_content(objects.settings_tv);
    // Отключаем скролл для всего контейнера
    lv_obj_remove_flag(tab_content, LV_OBJ_FLAG_SCROLLABLE);

    lv_label_set_text(objects.version, VERSION);
    lv_label_set_text_fmt(objects.pump_pct, "%d%%", pump_active_pct);
}