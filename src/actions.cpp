#include <lvgl.h>
#include "ui/actions.h"
#include "ui/ui.h"
#include "ui/screens.h"
#include <Arduino.h>
#include <Preferences.h>
#include "auto_pumps.h"
#include "elegantota.h"
#include "constants.h"
#include "enow.h"
#include <freertos/task.h>

#define RW_MODE false
#define RO_MODE true
#define GFX_BL 2

extern Preferences settings;
extern uint32_t GFX_BL_VALUE, GFX_BL_TIME;
extern lv_obj_t *bar_list[PUMP_AMOUNT];
extern int ROTATION;
extern bool is_paused, tank_empty, hand_paused;
extern void revert_display();
extern void program_pause();
extern void program_resume();

uint32_t water_num, start_time, programm_time;
int8_t thisH, thisM, thisS;
// Кнопка выбранной зоны (используется между action_zone_time_clicked и action_input_done)
lv_obj_t *g_selected_zone_btn;

void millis_to_HMS(unsigned long ms)
{
    unsigned long allSeconds = ms / 1000;
    thisH = (allSeconds / 3600) % 24; // Часы
    thisM = (allSeconds / 60) % 60;   // Минуты
    thisS = allSeconds % 60;          // Секунды
}

void hide_k_buttons()
{
    lv_obj_add_flag(objects.button10, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.button_10, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.button_dec, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.button_inc, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.button_reset, LV_OBJ_FLAG_HIDDEN);
}

void show_k_buttons()
{
    lv_obj_remove_flag(objects.button10, LV_OBJ_FLAG_HIDDEN);
    lv_obj_remove_flag(objects.button_10, LV_OBJ_FLAG_HIDDEN);
    lv_obj_remove_flag(objects.button_dec, LV_OBJ_FLAG_HIDDEN);
    lv_obj_remove_flag(objects.button_inc, LV_OBJ_FLAG_HIDDEN);
    lv_obj_remove_flag(objects.button_reset, LV_OBJ_FLAG_HIDDEN);
}

void update_zone_list()
{
    for (int i = 0; i < PUMP_AMOUNT; i++)
    {
        lv_obj_t *bar = lv_obj_get_child(objects.bars_panel, i);
        lv_obj_t *button = lv_obj_get_child(objects.tab_1, i);
        lv_obj_t *checkbox = lv_obj_get_child(button, 1);

        if (dw_time[i] != 0)
        {
            lv_obj_remove_flag(bar, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_bg_opa(button, FULL_OPACITY, LV_PART_MAIN);
            lv_obj_remove_flag(checkbox, LV_OBJ_FLAG_HIDDEN);
        }
        else
        {
            lv_obj_add_flag(bar, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_bg_opa(button, LOW_OPACITY, LV_PART_MAIN);
            lv_obj_add_flag(checkbox, LV_OBJ_FLAG_HIDDEN);
        }
    }
}

void action_revert_display(lv_event_t *e)
{
    revert_display();
    settings.begin("Settings", RW_MODE);
    settings.putInt("ROTATION", ROTATION);
    settings.end();
    // Полная очистка UI перед сменой ориентации
    lv_obj_clean(lv_screen_active());

    // Обнуляем структуру объектов, так как старые указатели больше не валидны
    memset(&objects, 0, sizeof(objects));

    ui_init();
    for (int i = 0; i < PUMP_AMOUNT; i++)
    {
        lv_obj_t *button = lv_obj_get_child(objects.tab_2, i);

        lv_obj_t *dw = lv_obj_get_child(button, 1);
        lv_label_set_text(dw, String(dw_time[i]).c_str());
        lv_obj_set_ext_click_area(dw, EXT_CLICK_AREA_SMALL);

        if (dw_time[i] != 0)
            lv_obj_set_style_bg_opa(button, FULL_OPACITY, LV_PART_MAIN);
        else
            lv_obj_set_style_bg_opa(button, LOW_OPACITY, LV_PART_MAIN);
    }
    update_zone_list();
}

void action_debug(lv_event_t *e)
{
    if (lv_obj_has_state(objects.debug, LV_STATE_CHECKED))
        minutes = DEBUG_TIME_MINUTES;
    else
        minutes = REAL_TIME_MINUTES;
}

void action_plant_food(lv_event_t *e)
{
    plant_food = lv_obj_has_state(objects.plant_food, LV_STATE_CHECKED);
    // if (plant_food)
    //     lv_obj_remove_flag(objects.esp_lora, LV_OBJ_FLAG_HIDDEN);
    // else
    //     lv_obj_add_flag(objects.esp_lora, LV_OBJ_FLAG_HIDDEN);
    settings.begin("Settings", RW_MODE);
    settings.putBool("plant_food", plant_food);
    settings.end();
}

void action_use_pult(lv_event_t *e)
{
    use_pult = lv_obj_has_state(objects.pult, LV_STATE_CHECKED);
    if (use_pult)
        lv_obj_remove_flag(objects.esp_lora, LV_OBJ_FLAG_HIDDEN);
    else
        lv_obj_add_flag(objects.esp_lora, LV_OBJ_FLAG_HIDDEN);
    settings.begin("Settings", RW_MODE);
    settings.putBool("use_pult", use_pult);
    settings.end();
}

void action_esp_lora_clicked(lv_event_t *e)
{
    esp_now = lv_obj_has_state(objects.esp_now, LV_STATE_CHECKED);
    lora = lv_obj_has_state(objects.lora, LV_STATE_CHECKED);
    settings.begin("Settings", RW_MODE);
    settings.putBool("lora", lora);
    settings.putBool("esp_now", esp_now);
    settings.end();
}

void action_bl_changed(lv_event_t *e)
{
    GFX_BL_VALUE = lv_slider_get_value(objects.bl);
    analogWrite(GFX_BL, GFX_BL_VALUE);
}

void action_bl_released(lv_event_t *e)
{
    GFX_BL_VALUE = lv_slider_get_value(objects.bl);
    settings.begin("Settings", RW_MODE);
    settings.putLong("GFX_BL_VALUE", GFX_BL_VALUE);
    settings.end();
}

void action_idle_time_focused(lv_event_t *e)
{
    lv_keyboard_set_textarea(objects.settings_kb, objects.bl_idle);
    lv_obj_remove_flag(objects.settings_kb, LV_OBJ_FLAG_HIDDEN);
    lv_textarea_set_cursor_pos(objects.bl_idle, LV_TEXTAREA_CURSOR_LAST);
}

void action_pause_released(lv_event_t *e)
{
    lv_keyboard_set_textarea(objects.settings_kb, objects.pause);
    lv_obj_remove_flag(objects.settings_kb, LV_OBJ_FLAG_HIDDEN);
    lv_textarea_set_cursor_pos(objects.pause, LV_TEXTAREA_CURSOR_LAST);
}

void action_pause_ready(lv_event_t *e)
{
    lv_obj_add_flag(objects.settings_kb, LV_OBJ_FLAG_HIDDEN);
    const char *txt = lv_textarea_get_text(objects.pause);
    water_pause = (txt[0] == '\0') ? 0 : atol(txt);
    if (txt[0] == '\0' || water_pause < 10)
    {
        lv_textarea_set_text(objects.pause, "10");
        water_pause = 10;
    }
    settings.begin("Settings", RW_MODE);
    settings.putLong("water_pause", water_pause);
    settings.end();
}

void action_idle_time_unfocused(lv_event_t *e)
{
    lv_obj_add_flag(objects.settings_kb, LV_OBJ_FLAG_HIDDEN);
    const char *txt = lv_textarea_get_text(objects.bl_idle);
    GFX_BL_TIME = (txt[0] == '\0') ? MIN_GFX_BL_TIME : atol(txt);
    if (GFX_BL_TIME < MIN_GFX_BL_TIME || (txt[0] == '\0'))
    {
        GFX_BL_TIME = MIN_GFX_BL_TIME;
        lv_textarea_set_text(objects.bl_idle, String(MIN_GFX_BL_TIME).c_str());
    }
    settings.begin("Settings", RW_MODE);
    settings.putLong("GFX_BL_TIME", GFX_BL_TIME);
    settings.end();
}

// Вспомогательная функция для расчета общего времени программы
void calculate_program_time()
{
    programm_time = 0;
    for (byte i = 0; i < PUMP_AMOUNT; i++)
    {
        if (dw_time[i] > 0 && pump_finished[i] == false)
        {
            programm_time += (uint64_t)dw_time[i] * MS_PER_SECOND * minutes * k_dw_time / 100;
        }
    }
    millis_to_HMS(programm_time > 0 ? (uint32_t)programm_time : 0);
}

void action_start(lv_event_t *e)
{
    if (tank_empty)
        return;
    start_time = millis();
    zoneTimer = millis();
    update_bars(true);

    for (byte i = 0; i < PUMP_AMOUNT; i++)
    {
        pump_finished[i] = false;
        lv_obj_t *bar = lv_obj_get_child(objects.bars_panel, i);
        lv_bar_set_value(bar, 0, LV_ANIM_OFF);
        lv_obj_t *bar_label = lv_obj_get_child(bar, 0);
        lv_obj_set_style_text_color(bar_label, lv_color_hex(0xffffff), LV_PART_MAIN);
    }

    calculate_program_time();
    if (programm_time <= 0)
        return;

    lv_bar_set_range(objects.prog_bar, 0, programm_time);
    lv_obj_remove_flag(objects.prog_bar, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.tab_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.tab_2, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.tab_settings, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.start, LV_OBJ_FLAG_HIDDEN);
    hide_k_buttons();
    lv_obj_add_state(objects.start, LV_STATE_DISABLED);
    lv_obj_remove_flag(objects.stop, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_state(objects.stop, LV_STATE_DISABLED);
    lv_obj_remove_flag(objects.spinner, LV_OBJ_FLAG_HIDDEN);
    lv_obj_remove_flag(objects.pause_btn, LV_OBJ_FLAG_HIDDEN);
    lv_bar_set_value(objects.prog_bar, 0, LV_ANIM_OFF);
}

void action_stop(lv_event_t *e)
{
    handle_messages();
    // Защита от невалидного current_zone (по умолчанию 255) до назначения зоны в periodTick()
    if (current_zone < PUMP_AMOUNT && !pump_finished[current_zone])
        zone_off(current_zone);

    for (byte i = 0; i < PUMP_AMOUNT; i++)
    {
        lv_obj_t *zone_button = lv_obj_get_child(objects.tab_1, i);
        if (!lv_obj_has_flag(zone_button, LV_OBJ_FLAG_CHECKABLE))
        {
            lv_obj_t *check_box = lv_obj_get_child(zone_button, 1);
            lv_obj_add_flag(check_box, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_remove_state(check_box, LV_STATE_CHECKED);
        }
        pump_finished[i] = true;
        if (pump_state[i] == SWITCH_LEVEL)
            pump_state[i] = !SWITCH_LEVEL;
    }
    now_pumping = false;
    lv_obj_add_flag(objects.stop, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_state(objects.stop, LV_STATE_DISABLED);
    lv_obj_remove_flag(objects.start, LV_OBJ_FLAG_HIDDEN);
    show_k_buttons();
    lv_obj_remove_flag(objects.tab_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_remove_flag(objects.tab_2, LV_OBJ_FLAG_HIDDEN);
    lv_obj_remove_flag(objects.tab_settings, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_state(objects.start, LV_STATE_DISABLED);
    lv_obj_add_flag(objects.spinner, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.pause_btn, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.tank, LV_OBJ_FLAG_HIDDEN);
    update_zone_list();
    if (is_paused)
    {
        // Визуализация активного состояния
        lv_label_set_text(objects.pause_btn_label, " Пауза");
        lv_obj_remove_local_style_prop(objects.pause_btn, LV_STYLE_BG_COLOR, LV_PART_MAIN);
        lv_obj_remove_local_style_prop(objects.prog_bar, LV_STYLE_BG_COLOR, LV_PART_INDICATOR);
        is_paused = !is_paused;
    }
}

void action_pause_btn(lv_event_t *e)
{
    if (tank_empty)
        return;
    lv_obj_add_flag(objects.tank, LV_OBJ_FLAG_HIDDEN);
    is_paused = !is_paused;
    if (is_paused)
    {
        hand_paused = true;
        program_pause();
    }
    else
    {
        hand_paused = false;
        program_resume();
    }
}

void save_k_dw_time()
{
    lv_label_set_text(objects.k_dw_time, String(k_dw_time).c_str());
    settings.begin("Settings", RW_MODE);
    settings.putLong("k_dw_time", k_dw_time);
    settings.end();
}

void action_decrement_10(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT)
    {
        if (k_dw_time >= K_DW_STEP + MIN_K_DW_TIME)
            k_dw_time -= K_DW_STEP;
        else
            k_dw_time = MIN_K_DW_TIME;
        save_k_dw_time();
    }
}

void action_spinbox_decrement_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT)
    {
        if (k_dw_time > MIN_K_DW_TIME)
        {
            --k_dw_time;
            save_k_dw_time();
        }
    }
}

void action_increment_10(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT)
    {
        k_dw_time += K_DW_STEP;
        if (k_dw_time > MAX_K_DW_TIME)
            k_dw_time = MAX_K_DW_TIME;
        save_k_dw_time();
    }
}

void action_spinbox_increment_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT)
    {
        if (k_dw_time < MAX_K_DW_TIME)
        {
            ++k_dw_time;
            save_k_dw_time();
        }
    }
}

void action_k_reset(lv_event_t *e)
{
    k_dw_time = DEFAULT_K_DW_TIME;
    save_k_dw_time();
}

void action_pump_pct_dec(lv_event_t *e)
{
    if (pump_active_pct > MIN_PUMP_ACTIVE_PCT)
    {
        --pump_active_pct;
        lv_label_set_text_fmt(objects.pump_pct, "%d%%", pump_active_pct);
        settings.begin("Settings", RW_MODE);
        settings.putLong("pump_active_pct", pump_active_pct);
        settings.end();
    }
}

void action_pump_pct_inc(lv_event_t *e)
{
    if (pump_active_pct < MAX_PUMP_ACTIVE_PCT)
    {
        ++pump_active_pct;
        lv_label_set_text_fmt(objects.pump_pct, "%d%%", pump_active_pct);
        settings.begin("Settings", RW_MODE);
        settings.putLong("pump_active_pct", pump_active_pct);
        settings.end();
    }
}

void action_update_back(lv_event_t *e)
{
    lv_screen_load_anim(objects.main, LV_SCREEN_LOAD_ANIM_OUT_RIGHT, SCREEN_ANIM_DURATION_MS, 0, true);
}

void action_update_relay_back(lv_event_t *e)
{
    lv_screen_load_anim(objects.main, LV_SCREEN_LOAD_ANIM_OUT_RIGHT, SCREEN_ANIM_DURATION_MS, 0, true);
}

void action_update(lv_event_t *e)
{
    create_screen_update_selector();
    loadScreen(SCREEN_ID_UPDATE_SELECTOR);
}

void action_update_display(lv_event_t *e)
{
    ota_mode = true;
    if (pultTaskHandle != NULL)
        vTaskSuspend(pultTaskHandle);
    create_screen_update_display();
    loadScreen(SCREEN_ID_UPDATE_DISPLAY);
    ota_setup();
}

void action_update_relay(lv_event_t *e)
{
    create_screen_update_relay();
    lv_screen_load_anim(objects.update_relay, LV_SCREEN_LOAD_ANIM_NONE, 0, 0, true);
}

void action_update_relay_1(lv_event_t *e)
{
    send_root_command(255, false, 1);
}

void action_update_relay_2(lv_event_t *e)
{
    send_root_command(255, false, 2);
}

void action_zone_selected(lv_event_t *e)
{
    lv_obj_t *zone_button = lv_event_get_current_target_obj(e);
    int32_t zone_num = lv_obj_get_index(zone_button);
    lv_obj_remove_flag(lv_event_get_target_obj(e), LV_OBJ_FLAG_CLICKABLE);

    pump_finished[zone_num] = false;

    if (lv_obj_has_flag(objects.stop, LV_OBJ_FLAG_HIDDEN))
    {
        start_time = millis();
        lv_obj_add_flag(objects.tab_2, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(objects.tab_settings, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(objects.start, LV_OBJ_FLAG_HIDDEN);
        hide_k_buttons();
        lv_obj_add_state(objects.start, LV_STATE_DISABLED);
        lv_obj_remove_flag(objects.stop, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_state(objects.stop, LV_STATE_DISABLED);
        lv_obj_remove_flag(objects.spinner, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_flag(objects.prog_bar, LV_OBJ_FLAG_HIDDEN);

        for (byte i = 0; i < PUMP_AMOUNT; i++)
        {
            lv_obj_t *bar = lv_obj_get_child(objects.bars_panel, i);
            lv_bar_set_value(bar, 0, LV_ANIM_OFF);
        }

        zoneTimer = millis();
    }

    calculate_program_time();

    for (byte i = 0; i < PUMP_AMOUNT; i++)
    {
        lv_obj_t *bar = lv_obj_get_child(objects.bars_panel, i);
        if (dw_time[i] > 0 && pump_finished[i] == false)
        {
            lv_obj_remove_flag(bar, LV_OBJ_FLAG_HIDDEN);
        }
        else
        {
            lv_obj_add_flag(bar, LV_OBJ_FLAG_HIDDEN);
        }
    }

    lv_bar_set_range(objects.prog_bar, 0, programm_time);
}

void action_zone_time_clicked(lv_event_t *e)
{
    g_selected_zone_btn = lv_event_get_current_target_obj(e); // зона
    water_num = lv_obj_get_index(lv_event_get_target_obj(e));
    if (lv_obj_has_flag(objects.keyboard, LV_OBJ_FLAG_HIDDEN))
    {
        lv_obj_remove_flag(objects.keyboard, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_flag(objects.input_area, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_state(objects.input_area, LV_STATE_FOCUSED);
    }
}

void action_input_done(lv_event_t *e)
{
    const char *txt = lv_textarea_get_text(objects.input_area);
    lv_obj_t *ob = lv_obj_get_child(g_selected_zone_btn, water_num);

    if (txt[0] == '\0' || strcmp(txt, "0") == 0 || strcmp(txt, "00") == 0)
    {
        txt = "0";
    }

    lv_obj_add_flag(objects.keyboard, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.input_area, LV_OBJ_FLAG_HIDDEN);

    settings.begin("Settings", RW_MODE);
    int zone_num = (int)lv_obj_get_index(g_selected_zone_btn);

    if (water_num == 1)
    {
        dw_time[zone_num] = atol(txt);
        settings.putBytes("dw_time", dw_time, sizeof(dw_time));
    }
    settings.end();

    lv_label_set_text(ob, txt);
    lv_textarea_set_text(objects.input_area, "");

    if (dw_time[zone_num] == 0)
        lv_obj_set_style_bg_opa(g_selected_zone_btn, LOW_OPACITY, LV_PART_MAIN);
    else
        lv_obj_set_style_bg_opa(g_selected_zone_btn, FULL_OPACITY, LV_PART_MAIN);

    update_zone_list();
}
