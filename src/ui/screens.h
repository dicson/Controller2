#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Screens

enum ScreensEnum {
    _SCREEN_ID_FIRST = 1,
    SCREEN_ID_MAIN = 1,
    SCREEN_ID_UPDATE_DISPLAY = 2,
    SCREEN_ID_UPDATE_SELECTOR = 3,
    SCREEN_ID_UPDATE_RELAY = 4,
    _SCREEN_ID_LAST = 4
};

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *update_display;
    lv_obj_t *update_selector;
    lv_obj_t *update_relay;
    lv_obj_t *tabview;
    lv_obj_t *tab_main;
    lv_obj_t *prog_bar;
    lv_obj_t *bar_label;
    lv_obj_t *spinner;
    lv_obj_t *start;
    lv_obj_t *stop;
    lv_obj_t *obj0;
    lv_obj_t *plant_food;
    lv_obj_t *pump;
    lv_obj_t *tank;
    lv_obj_t *tank_time;
    lv_obj_t *pause_bar;
    lv_obj_t *bars_panel;
    lv_obj_t *message_box;
    lv_obj_t *k_panel;
    lv_obj_t *obj1;
    lv_obj_t *k_dw_time;
    lv_obj_t *button_10;
    lv_obj_t *button_dec;
    lv_obj_t *button_reset;
    lv_obj_t *obj2;
    lv_obj_t *k_reset;
    lv_obj_t *button_inc;
    lv_obj_t *button10;
    lv_obj_t *pause_btn;
    lv_obj_t *pause_btn_label;
    lv_obj_t *tank_empty;
    lv_obj_t *debug_label;
    lv_obj_t *tab_1;
    lv_obj_t *tab_2;
    lv_obj_t *zone_times;
    lv_obj_t *input_area;
    lv_obj_t *keyboard;
    lv_obj_t *tab_settings;
    lv_obj_t *settings_tv;
    lv_obj_t *pause;
    lv_obj_t *brightness;
    lv_obj_t *bl;
    lv_obj_t *bl_idle;
    lv_obj_t *r_display;
    lv_obj_t *obj3;
    lv_obj_t *pult;
    lv_obj_t *esp_lora;
    lv_obj_t *esp_now;
    lv_obj_t *lora;
    lv_obj_t *obj4;
    lv_obj_t *obj5;
    lv_obj_t *pump_pct;
    lv_obj_t *obj6;
    lv_obj_t *update;
    lv_obj_t *version;
    lv_obj_t *obj7;
    lv_obj_t *debug;
    lv_obj_t *settings_kb;
    lv_obj_t *obj8;
    lv_obj_t *obj9;
    lv_obj_t *obj10;
    lv_obj_t *obj11;
    lv_obj_t *obj12;
    lv_obj_t *obj13;
    lv_obj_t *obj14;
    lv_obj_t *obj15;
    lv_obj_t *obj16;
    lv_obj_t *obj17;
    lv_obj_t *obj18;
    lv_obj_t *obj19;
    lv_obj_t *obj20;
    lv_obj_t *obj21;
    lv_obj_t *obj22;
    lv_obj_t *obj23;
    lv_obj_t *obj24;
    lv_obj_t *obj25;
    lv_obj_t *obj26;
    lv_obj_t *obj27;
    lv_obj_t *update_relay_back;
    lv_obj_t *obj28;
} objects_t;

extern objects_t objects;

void create_screen_main();
void delete_screen_main();
void tick_screen_main();

void create_screen_update_display();
void delete_screen_update_display();
void tick_screen_update_display();

void create_screen_update_selector();
void delete_screen_update_selector();
void tick_screen_update_selector();

void create_screen_update_relay();
void delete_screen_update_relay();
void tick_screen_update_relay();

void create_screen_by_id(enum ScreensEnum screenId);
void delete_screen_by_id(enum ScreensEnum screenId);
void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/