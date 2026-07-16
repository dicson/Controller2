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
    lv_obj_t *stop;
    lv_obj_t *start;
    lv_obj_t *obj0;
    lv_obj_t *plant_food;
    lv_obj_t *pump;
    lv_obj_t *tank;
    lv_obj_t *tank_time;
    lv_obj_t *pause_bar;
    lv_obj_t *bars_panel;
    lv_obj_t *bar_0;
    lv_obj_t *obj1;
    lv_obj_t *bar_1;
    lv_obj_t *obj2;
    lv_obj_t *bar_2;
    lv_obj_t *obj3;
    lv_obj_t *bar_3;
    lv_obj_t *obj4;
    lv_obj_t *bar_4;
    lv_obj_t *obj5;
    lv_obj_t *bar_5;
    lv_obj_t *obj6;
    lv_obj_t *bar_6;
    lv_obj_t *obj7;
    lv_obj_t *bar_7;
    lv_obj_t *obj8;
    lv_obj_t *bar_8;
    lv_obj_t *obj9;
    lv_obj_t *bar_9;
    lv_obj_t *obj10;
    lv_obj_t *bar_10;
    lv_obj_t *obj11;
    lv_obj_t *bar_11;
    lv_obj_t *obj12;
    lv_obj_t *bar_12;
    lv_obj_t *obj13;
    lv_obj_t *bar_13;
    lv_obj_t *obj14;
    lv_obj_t *bar_14;
    lv_obj_t *obj15;
    lv_obj_t *bar_15;
    lv_obj_t *obj16;
    lv_obj_t *bar_16;
    lv_obj_t *obj17;
    lv_obj_t *bar_17;
    lv_obj_t *obj18;
    lv_obj_t *bar_18;
    lv_obj_t *obj19;
    lv_obj_t *bar_19;
    lv_obj_t *obj20;
    lv_obj_t *bar_20;
    lv_obj_t *obj21;
    lv_obj_t *bar_21;
    lv_obj_t *obj22;
    lv_obj_t *bar_22;
    lv_obj_t *obj23;
    lv_obj_t *bar_23;
    lv_obj_t *obj24;
    lv_obj_t *bar_24;
    lv_obj_t *obj25;
    lv_obj_t *bar_25;
    lv_obj_t *obj26;
    lv_obj_t *bar_26;
    lv_obj_t *obj27;
    lv_obj_t *bar_27;
    lv_obj_t *obj28;
    lv_obj_t *bar_28;
    lv_obj_t *obj29;
    lv_obj_t *bar_29;
    lv_obj_t *obj30;
    lv_obj_t *bar_30;
    lv_obj_t *obj31;
    lv_obj_t *message_box;
    lv_obj_t *k_panel;
    lv_obj_t *k_dw_time;
    lv_obj_t *button_10;
    lv_obj_t *obj32;
    lv_obj_t *button_dec;
    lv_obj_t *obj33;
    lv_obj_t *button_reset;
    lv_obj_t *k_reset;
    lv_obj_t *button_inc;
    lv_obj_t *obj34;
    lv_obj_t *button10;
    lv_obj_t *obj35;
    lv_obj_t *pause_btn;
    lv_obj_t *pause_btn_label;
    lv_obj_t *tank_empty;
    lv_obj_t *tab_1;
    lv_obj_t *obj36;
    lv_obj_t *obj37;
    lv_obj_t *obj38;
    lv_obj_t *obj39;
    lv_obj_t *obj40;
    lv_obj_t *obj41;
    lv_obj_t *obj42;
    lv_obj_t *obj43;
    lv_obj_t *_9;
    lv_obj_t *obj44;
    lv_obj_t *obj45;
    lv_obj_t *obj46;
    lv_obj_t *obj47;
    lv_obj_t *obj48;
    lv_obj_t *obj49;
    lv_obj_t *obj50;
    lv_obj_t *_9_1;
    lv_obj_t *obj51;
    lv_obj_t *obj52;
    lv_obj_t *obj53;
    lv_obj_t *obj54;
    lv_obj_t *obj55;
    lv_obj_t *obj56;
    lv_obj_t *obj57;
    lv_obj_t *_25;
    lv_obj_t *obj58;
    lv_obj_t *obj59;
    lv_obj_t *obj60;
    lv_obj_t *obj61;
    lv_obj_t *obj62;
    lv_obj_t *obj63;
    lv_obj_t *obj64;
    lv_obj_t *tab_2;
    lv_obj_t *zone_times;
    lv_obj_t *zone1;
    lv_obj_t *d_4;
    lv_obj_t *c_4;
    lv_obj_t *zone2;
    lv_obj_t *d_2;
    lv_obj_t *c_2;
    lv_obj_t *zone3;
    lv_obj_t *d_3;
    lv_obj_t *c_3;
    lv_obj_t *zone4;
    lv_obj_t *d_5;
    lv_obj_t *c_5;
    lv_obj_t *zone5;
    lv_obj_t *d_6;
    lv_obj_t *c_6;
    lv_obj_t *zone6;
    lv_obj_t *d_7;
    lv_obj_t *c_7;
    lv_obj_t *zone7;
    lv_obj_t *d_8;
    lv_obj_t *c_8;
    lv_obj_t *zone8;
    lv_obj_t *d_9;
    lv_obj_t *c_9;
    lv_obj_t *zone9;
    lv_obj_t *d_10;
    lv_obj_t *c_10;
    lv_obj_t *zone10;
    lv_obj_t *d_11;
    lv_obj_t *c_11;
    lv_obj_t *zone11;
    lv_obj_t *d_12;
    lv_obj_t *c_12;
    lv_obj_t *zone12;
    lv_obj_t *d_13;
    lv_obj_t *c_13;
    lv_obj_t *zone13;
    lv_obj_t *d_14;
    lv_obj_t *c_14;
    lv_obj_t *zone14;
    lv_obj_t *d_15;
    lv_obj_t *c_15;
    lv_obj_t *zone15;
    lv_obj_t *d_16;
    lv_obj_t *c_16;
    lv_obj_t *zone16;
    lv_obj_t *d_17;
    lv_obj_t *c_17;
    lv_obj_t *zone16_1;
    lv_obj_t *d_18;
    lv_obj_t *c_18;
    lv_obj_t *zone16_2;
    lv_obj_t *d_19;
    lv_obj_t *c_19;
    lv_obj_t *zone16_3;
    lv_obj_t *d_20;
    lv_obj_t *c_20;
    lv_obj_t *zone16_4;
    lv_obj_t *d_21;
    lv_obj_t *c_21;
    lv_obj_t *zone16_5;
    lv_obj_t *d_22;
    lv_obj_t *c_22;
    lv_obj_t *zone16_6;
    lv_obj_t *d_23;
    lv_obj_t *c_23;
    lv_obj_t *zone16_7;
    lv_obj_t *d_24;
    lv_obj_t *c_24;
    lv_obj_t *zone16_8;
    lv_obj_t *d_25;
    lv_obj_t *c_25;
    lv_obj_t *zone16_9;
    lv_obj_t *d_26;
    lv_obj_t *c_26;
    lv_obj_t *zone16_10;
    lv_obj_t *d_27;
    lv_obj_t *c_27;
    lv_obj_t *zone16_11;
    lv_obj_t *d_28;
    lv_obj_t *c_28;
    lv_obj_t *zone16_12;
    lv_obj_t *d_29;
    lv_obj_t *c_29;
    lv_obj_t *zone16_13;
    lv_obj_t *d_30;
    lv_obj_t *c_30;
    lv_obj_t *zone16_14;
    lv_obj_t *d_31;
    lv_obj_t *c_31;
    lv_obj_t *zone16_15;
    lv_obj_t *d_32;
    lv_obj_t *c_32;
    lv_obj_t *zone16_16;
    lv_obj_t *d_33;
    lv_obj_t *c_33;
    lv_obj_t *input_area;
    lv_obj_t *keyboard;
    lv_obj_t *tab_settings;
    lv_obj_t *settings_tv;
    lv_obj_t *pause;
    lv_obj_t *brightness;
    lv_obj_t *bl;
    lv_obj_t *bl_idle;
    lv_obj_t *r_display;
    lv_obj_t *obj65;
    lv_obj_t *pult;
    lv_obj_t *esp_lora;
    lv_obj_t *esp_now;
    lv_obj_t *lora;
    lv_obj_t *obj66;
    lv_obj_t *obj67;
    lv_obj_t *pump_pct;
    lv_obj_t *obj68;
    lv_obj_t *update;
    lv_obj_t *version;
    lv_obj_t *obj69;
    lv_obj_t *debug;
    lv_obj_t *settings_kb;
    lv_obj_t *obj70;
    lv_obj_t *obj71;
    lv_obj_t *obj72;
    lv_obj_t *obj73;
    lv_obj_t *obj74;
    lv_obj_t *obj75;
    lv_obj_t *obj76;
    lv_obj_t *obj77;
    lv_obj_t *obj78;
    lv_obj_t *obj79;
    lv_obj_t *obj80;
    lv_obj_t *obj81;
    lv_obj_t *obj82;
    lv_obj_t *obj83;
    lv_obj_t *obj84;
    lv_obj_t *obj85;
    lv_obj_t *obj86;
    lv_obj_t *obj87;
    lv_obj_t *obj88;
    lv_obj_t *obj89;
    lv_obj_t *update_relay_back;
    lv_obj_t *obj90;
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