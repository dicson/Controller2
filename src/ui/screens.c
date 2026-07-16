#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;

//
// Event handlers
//

lv_obj_t *tick_value_change_obj;

//
// Screens
//

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_text_font(obj, &ui_font_ubuntu_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // tabview
            lv_obj_t *obj = lv_tabview_create(parent_obj);
            objects.tabview = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 480);
            lv_tabview_set_tab_bar_position(obj, LV_DIR_BOTTOM);
            lv_tabview_set_tab_bar_size(obj, 32);
            lv_obj_set_style_text_font(obj, &ui_font_ubuntu_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_FOCUSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // tab_main
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Программа");
                    objects.tab_main = obj;
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_margin_bottom(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_margin_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_margin_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_margin_top(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // prog_bar
                            lv_obj_t *obj = lv_bar_create(parent_obj);
                            objects.prog_bar = obj;
                            lv_obj_set_pos(obj, -20, 381);
                            lv_obj_set_size(obj, 590, 27);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                            lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 10, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // bar_label
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.bar_label = obj;
                                    lv_obj_set_pos(obj, 153, 16);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xeceff0), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "");
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 586, 356);
                            lv_obj_set_size(obj, 184, 57);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_column(obj, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // spinner
                                    lv_obj_t *obj = lv_spinner_create(parent_obj);
                                    objects.spinner = obj;
                                    lv_obj_set_pos(obj, 589, 378);
                                    lv_obj_set_size(obj, 44, 45);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_set_style_arc_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_arc_width(obj, 5, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                }
                                {
                                    // Stop
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.stop = obj;
                                    lv_obj_set_pos(obj, 663, 363);
                                    lv_obj_set_size(obj, 100, 50);
                                    lv_obj_add_event_cb(obj, action_stop, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_add_state(obj, LV_STATE_DISABLED);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xe30029), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "Стоп");
                                        }
                                    }
                                }
                                {
                                    // Start
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.start = obj;
                                    lv_obj_set_pos(obj, 663, 363);
                                    lv_obj_set_size(obj, 100, 50);
                                    lv_obj_add_event_cb(obj, action_start, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x087343), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "Старт");
                                        }
                                    }
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.obj0 = obj;
                            lv_obj_set_pos(obj, 579, -20);
                            lv_obj_set_size(obj, 191, 125);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            add_style_1style(obj);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_row(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, -975, 13);
                                    lv_obj_set_size(obj, 189, 30);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            // plant_food
                                            lv_obj_t *obj = lv_switch_create(parent_obj);
                                            objects.plant_food = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, 50, 25);
                                            lv_obj_add_event_cb(obj, action_plant_food, LV_EVENT_VALUE_CHANGED, (void *)0);
                                        }
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text_static(obj, "Подкормка");
                                        }
                                        {
                                            // pump
                                            lv_obj_t *obj = lv_led_create(parent_obj);
                                            objects.pump = obj;
                                            lv_obj_set_pos(obj, 148, 0);
                                            lv_obj_set_size(obj, 23, 22);
                                            lv_led_set_color(obj, lv_color_hex(0x00ff00));
                                            lv_led_set_brightness(obj, 200);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                            lv_obj_set_style_shadow_width(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                    }
                                }
                                {
                                    // tank
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    objects.tank = obj;
                                    lv_obj_set_pos(obj, -51, 0);
                                    lv_obj_set_size(obj, 176, 82);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text_static(obj, "Наполняем бочку");
                                        }
                                        {
                                            // tank_time
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.tank_time = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text_static(obj, "time");
                                        }
                                        {
                                            // pause_bar
                                            lv_obj_t *obj = lv_bar_create(parent_obj);
                                            objects.pause_bar = obj;
                                            lv_obj_set_pos(obj, 38, -79);
                                            lv_obj_set_size(obj, 163, 12);
                                            lv_bar_set_value(obj, 25, LV_ANIM_OFF);
                                        }
                                    }
                                }
                            }
                        }
                        {
                            // bars_panel
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.bars_panel = obj;
                            lv_obj_set_pos(obj, -20, -20);
                            lv_obj_set_size(obj, 590, 395);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC);
                            add_style_1style(obj);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN_WRAP, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_row(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // bar_0
                                    lv_obj_t *obj = lv_bar_create(parent_obj);
                                    objects.bar_0 = obj;
                                    lv_obj_set_pos(obj, 136, -2);
                                    lv_obj_set_size(obj, 110, 19);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x087343), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj1 = obj;
                                            lv_obj_set_pos(obj, 20, -2);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "ЗОНА  1");
                                        }
                                    }
                                }
                                {
                                    // bar_1
                                    lv_obj_t *obj = lv_bar_create(parent_obj);
                                    objects.bar_1 = obj;
                                    lv_obj_set_pos(obj, 136, -2);
                                    lv_obj_set_size(obj, 110, 19);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x087343), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj2 = obj;
                                            lv_obj_set_pos(obj, 20, -2);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "ЗОНА  2");
                                        }
                                    }
                                }
                                {
                                    // bar_2
                                    lv_obj_t *obj = lv_bar_create(parent_obj);
                                    objects.bar_2 = obj;
                                    lv_obj_set_pos(obj, 136, -2);
                                    lv_obj_set_size(obj, 110, 19);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x087343), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj3 = obj;
                                            lv_obj_set_pos(obj, 20, -2);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "ЗОНА  3");
                                        }
                                    }
                                }
                                {
                                    // bar_3
                                    lv_obj_t *obj = lv_bar_create(parent_obj);
                                    objects.bar_3 = obj;
                                    lv_obj_set_pos(obj, 136, -2);
                                    lv_obj_set_size(obj, 110, 19);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x087343), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj4 = obj;
                                            lv_obj_set_pos(obj, 20, -2);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "ЗОНА  4");
                                        }
                                    }
                                }
                                {
                                    // bar_4
                                    lv_obj_t *obj = lv_bar_create(parent_obj);
                                    objects.bar_4 = obj;
                                    lv_obj_set_pos(obj, 136, -2);
                                    lv_obj_set_size(obj, 110, 19);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x087343), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj5 = obj;
                                            lv_obj_set_pos(obj, 20, -2);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "ЗОНА  5");
                                        }
                                    }
                                }
                                {
                                    // bar_5
                                    lv_obj_t *obj = lv_bar_create(parent_obj);
                                    objects.bar_5 = obj;
                                    lv_obj_set_pos(obj, 136, -2);
                                    lv_obj_set_size(obj, 110, 19);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x087343), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj6 = obj;
                                            lv_obj_set_pos(obj, 20, -2);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "ЗОНА  6");
                                        }
                                    }
                                }
                                {
                                    // bar_6
                                    lv_obj_t *obj = lv_bar_create(parent_obj);
                                    objects.bar_6 = obj;
                                    lv_obj_set_pos(obj, 136, -2);
                                    lv_obj_set_size(obj, 110, 19);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x087343), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj7 = obj;
                                            lv_obj_set_pos(obj, 20, -2);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "ЗОНА  7");
                                        }
                                    }
                                }
                                {
                                    // bar_7
                                    lv_obj_t *obj = lv_bar_create(parent_obj);
                                    objects.bar_7 = obj;
                                    lv_obj_set_pos(obj, 136, -2);
                                    lv_obj_set_size(obj, 110, 19);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x087343), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj8 = obj;
                                            lv_obj_set_pos(obj, 20, -2);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "ЗОНА  8");
                                        }
                                    }
                                }
                                {
                                    // bar_8
                                    lv_obj_t *obj = lv_bar_create(parent_obj);
                                    objects.bar_8 = obj;
                                    lv_obj_set_pos(obj, 136, -2);
                                    lv_obj_set_size(obj, 110, 19);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x087343), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj9 = obj;
                                            lv_obj_set_pos(obj, 20, -2);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "ЗОНА  9");
                                        }
                                    }
                                }
                                {
                                    // bar_9
                                    lv_obj_t *obj = lv_bar_create(parent_obj);
                                    objects.bar_9 = obj;
                                    lv_obj_set_pos(obj, 136, -2);
                                    lv_obj_set_size(obj, 110, 19);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x087343), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj10 = obj;
                                            lv_obj_set_pos(obj, 20, -2);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "ЗОНА 10");
                                        }
                                    }
                                }
                                {
                                    // bar_10
                                    lv_obj_t *obj = lv_bar_create(parent_obj);
                                    objects.bar_10 = obj;
                                    lv_obj_set_pos(obj, 136, -2);
                                    lv_obj_set_size(obj, 110, 19);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x087343), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj11 = obj;
                                            lv_obj_set_pos(obj, 20, -2);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "ЗОНА 11");
                                        }
                                    }
                                }
                                {
                                    // bar_11
                                    lv_obj_t *obj = lv_bar_create(parent_obj);
                                    objects.bar_11 = obj;
                                    lv_obj_set_pos(obj, 136, -2);
                                    lv_obj_set_size(obj, 110, 19);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x087343), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj12 = obj;
                                            lv_obj_set_pos(obj, 20, -2);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "ЗОНА 12");
                                        }
                                    }
                                }
                                {
                                    // bar_12
                                    lv_obj_t *obj = lv_bar_create(parent_obj);
                                    objects.bar_12 = obj;
                                    lv_obj_set_pos(obj, 136, -2);
                                    lv_obj_set_size(obj, 110, 19);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x087343), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj13 = obj;
                                            lv_obj_set_pos(obj, 20, -2);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "ЗОНА 13");
                                        }
                                    }
                                }
                                {
                                    // bar_13
                                    lv_obj_t *obj = lv_bar_create(parent_obj);
                                    objects.bar_13 = obj;
                                    lv_obj_set_pos(obj, 136, -2);
                                    lv_obj_set_size(obj, 110, 19);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x087343), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj14 = obj;
                                            lv_obj_set_pos(obj, 20, -2);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "ЗОНА 14");
                                        }
                                    }
                                }
                                {
                                    // bar_14
                                    lv_obj_t *obj = lv_bar_create(parent_obj);
                                    objects.bar_14 = obj;
                                    lv_obj_set_pos(obj, 136, -2);
                                    lv_obj_set_size(obj, 110, 19);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x087343), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj15 = obj;
                                            lv_obj_set_pos(obj, 20, -2);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "ЗОНА 15");
                                        }
                                    }
                                }
                                {
                                    // bar_15
                                    lv_obj_t *obj = lv_bar_create(parent_obj);
                                    objects.bar_15 = obj;
                                    lv_obj_set_pos(obj, 136, -2);
                                    lv_obj_set_size(obj, 110, 19);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x087343), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj16 = obj;
                                            lv_obj_set_pos(obj, 20, -2);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "ЗОНА 16");
                                        }
                                    }
                                }
                                {
                                    // bar_16
                                    lv_obj_t *obj = lv_bar_create(parent_obj);
                                    objects.bar_16 = obj;
                                    lv_obj_set_pos(obj, 136, -2);
                                    lv_obj_set_size(obj, 110, 19);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x087343), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj17 = obj;
                                            lv_obj_set_pos(obj, 20, -2);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "ЗОНА 17");
                                        }
                                    }
                                }
                                {
                                    // bar_17
                                    lv_obj_t *obj = lv_bar_create(parent_obj);
                                    objects.bar_17 = obj;
                                    lv_obj_set_pos(obj, 136, -2);
                                    lv_obj_set_size(obj, 110, 19);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x087343), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj18 = obj;
                                            lv_obj_set_pos(obj, 20, -2);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "ЗОНА 18");
                                        }
                                    }
                                }
                                {
                                    // bar_18
                                    lv_obj_t *obj = lv_bar_create(parent_obj);
                                    objects.bar_18 = obj;
                                    lv_obj_set_pos(obj, 136, -2);
                                    lv_obj_set_size(obj, 110, 19);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x087343), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj19 = obj;
                                            lv_obj_set_pos(obj, 20, -2);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "ЗОНА 19");
                                        }
                                    }
                                }
                                {
                                    // bar_19
                                    lv_obj_t *obj = lv_bar_create(parent_obj);
                                    objects.bar_19 = obj;
                                    lv_obj_set_pos(obj, 136, -2);
                                    lv_obj_set_size(obj, 110, 19);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x087343), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj20 = obj;
                                            lv_obj_set_pos(obj, 20, -2);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "ЗОНА 20");
                                        }
                                    }
                                }
                                {
                                    // bar_20
                                    lv_obj_t *obj = lv_bar_create(parent_obj);
                                    objects.bar_20 = obj;
                                    lv_obj_set_pos(obj, 136, -2);
                                    lv_obj_set_size(obj, 110, 19);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x087343), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj21 = obj;
                                            lv_obj_set_pos(obj, 20, -2);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "ЗОНА 21");
                                        }
                                    }
                                }
                                {
                                    // bar_21
                                    lv_obj_t *obj = lv_bar_create(parent_obj);
                                    objects.bar_21 = obj;
                                    lv_obj_set_pos(obj, 136, -2);
                                    lv_obj_set_size(obj, 110, 19);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x087343), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj22 = obj;
                                            lv_obj_set_pos(obj, 20, -2);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "ЗОНА 22");
                                        }
                                    }
                                }
                                {
                                    // bar_22
                                    lv_obj_t *obj = lv_bar_create(parent_obj);
                                    objects.bar_22 = obj;
                                    lv_obj_set_pos(obj, 136, -2);
                                    lv_obj_set_size(obj, 110, 19);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x087343), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj23 = obj;
                                            lv_obj_set_pos(obj, 20, -2);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "ЗОНА 23");
                                        }
                                    }
                                }
                                {
                                    // bar_23
                                    lv_obj_t *obj = lv_bar_create(parent_obj);
                                    objects.bar_23 = obj;
                                    lv_obj_set_pos(obj, 136, -2);
                                    lv_obj_set_size(obj, 110, 19);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x087343), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj24 = obj;
                                            lv_obj_set_pos(obj, 20, -2);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "ЗОНА 24");
                                        }
                                    }
                                }
                                {
                                    // bar_24
                                    lv_obj_t *obj = lv_bar_create(parent_obj);
                                    objects.bar_24 = obj;
                                    lv_obj_set_pos(obj, 136, -2);
                                    lv_obj_set_size(obj, 110, 19);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x087343), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj25 = obj;
                                            lv_obj_set_pos(obj, 20, -2);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "ЗОНА 25");
                                        }
                                    }
                                }
                                {
                                    // bar_25
                                    lv_obj_t *obj = lv_bar_create(parent_obj);
                                    objects.bar_25 = obj;
                                    lv_obj_set_pos(obj, 136, -2);
                                    lv_obj_set_size(obj, 110, 19);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x087343), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj26 = obj;
                                            lv_obj_set_pos(obj, 20, -2);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "ЗОНА 26");
                                        }
                                    }
                                }
                                {
                                    // bar_26
                                    lv_obj_t *obj = lv_bar_create(parent_obj);
                                    objects.bar_26 = obj;
                                    lv_obj_set_pos(obj, 136, -2);
                                    lv_obj_set_size(obj, 110, 19);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x087343), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj27 = obj;
                                            lv_obj_set_pos(obj, 20, -2);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "ЗОНА 27");
                                        }
                                    }
                                }
                                {
                                    // bar_27
                                    lv_obj_t *obj = lv_bar_create(parent_obj);
                                    objects.bar_27 = obj;
                                    lv_obj_set_pos(obj, 136, -2);
                                    lv_obj_set_size(obj, 110, 19);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x087343), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj28 = obj;
                                            lv_obj_set_pos(obj, 20, -2);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "ЗОНА 28");
                                        }
                                    }
                                }
                                {
                                    // bar_28
                                    lv_obj_t *obj = lv_bar_create(parent_obj);
                                    objects.bar_28 = obj;
                                    lv_obj_set_pos(obj, 136, -2);
                                    lv_obj_set_size(obj, 110, 19);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x087343), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj29 = obj;
                                            lv_obj_set_pos(obj, 20, -2);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "ЗОНА 29");
                                        }
                                    }
                                }
                                {
                                    // bar_29
                                    lv_obj_t *obj = lv_bar_create(parent_obj);
                                    objects.bar_29 = obj;
                                    lv_obj_set_pos(obj, 136, -2);
                                    lv_obj_set_size(obj, 110, 19);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x087343), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj30 = obj;
                                            lv_obj_set_pos(obj, 20, -2);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "ЗОНА 30");
                                        }
                                    }
                                }
                                {
                                    // bar_30
                                    lv_obj_t *obj = lv_bar_create(parent_obj);
                                    objects.bar_30 = obj;
                                    lv_obj_set_pos(obj, 136, -2);
                                    lv_obj_set_size(obj, 110, 19);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
                                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x087343), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj31 = obj;
                                            lv_obj_set_pos(obj, 20, -2);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "ЗОНА 31");
                                        }
                                    }
                                }
                            }
                        }
                        {
                            // message_box
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.message_box = obj;
                            lv_obj_set_pos(obj, 140, 133);
                            lv_obj_set_size(obj, 271, 165);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                            add_style_1style(obj);
                            lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 1, 3);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text_static(obj, "");
                                }
                            }
                        }
                        {
                            // k_panel
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.k_panel = obj;
                            lv_obj_set_pos(obj, 579, 112);
                            lv_obj_set_size(obj, 191, 175);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            add_style_1style(obj);
                            lv_obj_set_style_pad_top(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 49, 6);
                                    lv_obj_set_size(obj, 68, 69);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN_REVERSE, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 6216, 3);
                                            lv_obj_set_size(obj, 60, 29);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_row(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_column(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    // k_dw_time
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.k_dw_time = obj;
                                                    lv_obj_set_pos(obj, 17, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_label_set_text_static(obj, "100");
                                                }
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    lv_obj_set_pos(obj, 53, 4);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_label_set_text_static(obj, "%");
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text_static(obj, "Коэфф.");
                                        }
                                    }
                                }
                            }
                        }
                        {
                            // button_10
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.button_10 = obj;
                            lv_obj_set_pos(obj, 586, 128);
                            lv_obj_set_size(obj, 45, 50);
                            lv_obj_add_event_cb(obj, action_decrement_10, LV_EVENT_SHORT_CLICKED, (void *)0);
                            lv_obj_add_event_cb(obj, action_decrement_10, LV_EVENT_LONG_PRESSED_REPEAT, (void *)0);
                            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj32 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "-10");
                                }
                            }
                        }
                        {
                            // button_dec
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.button_dec = obj;
                            lv_obj_set_pos(obj, 586, 225);
                            lv_obj_set_size(obj, 45, 50);
                            lv_obj_add_event_cb(obj, action_spinbox_decrement_event_cb, LV_EVENT_SHORT_CLICKED, (void *)0);
                            lv_obj_add_event_cb(obj, action_spinbox_decrement_event_cb, LV_EVENT_LONG_PRESSED_REPEAT, (void *)0);
                            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj33 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "-1");
                                }
                            }
                        }
                        {
                            // button_reset
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.button_reset = obj;
                            lv_obj_set_pos(obj, 644, 235);
                            lv_obj_set_size(obj, 62, 40);
                            lv_obj_add_event_cb(obj, action_k_reset, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_image_create(parent_obj);
                                    lv_obj_set_pos(obj, -10, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_image_set_src(obj, &img_revers);
                                    lv_image_set_inner_align(obj, LV_IMAGE_ALIGN_DEFAULT);
                                }
                                {
                                    // k_reset
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.k_reset = obj;
                                    lv_obj_set_pos(obj, 7, 1);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "100");
                                }
                            }
                        }
                        {
                            // button_inc
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.button_inc = obj;
                            lv_obj_set_pos(obj, 720, 225);
                            lv_obj_set_size(obj, 45, 50);
                            lv_obj_add_event_cb(obj, action_spinbox_increment_event_cb, LV_EVENT_SHORT_CLICKED, (void *)0);
                            lv_obj_add_event_cb(obj, action_spinbox_increment_event_cb, LV_EVENT_LONG_PRESSED_REPEAT, (void *)0);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLL_CHAIN_HOR);
                            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj34 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "+1");
                                }
                            }
                        }
                        {
                            // button10
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.button10 = obj;
                            lv_obj_set_pos(obj, 720, 128);
                            lv_obj_set_size(obj, 45, 50);
                            lv_obj_add_event_cb(obj, action_increment_10, LV_EVENT_SHORT_CLICKED, (void *)0);
                            lv_obj_add_event_cb(obj, action_increment_10, LV_EVENT_LONG_PRESSED_REPEAT, (void *)0);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLL_CHAIN_HOR);
                            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj35 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "+10");
                                }
                            }
                        }
                        {
                            // pause_btn
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.pause_btn = obj;
                            lv_obj_set_pos(obj, 670, 300);
                            lv_obj_set_size(obj, 100, 50);
                            lv_obj_add_event_cb(obj, action_pause_btn, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // pause_btn_label
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.pause_btn_label = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "Пауза");
                                }
                            }
                        }
                        {
                            // tank_empty
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.tank_empty = obj;
                            lv_obj_set_pos(obj, 375, 133);
                            lv_obj_set_size(obj, 186, 128);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            add_style_1style(obj);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 51, 31);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text_static(obj, "Бочка пуста!");
                                }
                            }
                        }
                    }
                }
                {
                    // tab_1
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Выбрать и полить");
                    objects.tab_1 = obj;
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        static lv_coord_t dsc[] = {0, LV_GRID_TEMPLATE_LAST};
                        lv_obj_set_style_grid_row_dsc_array(obj, dsc, LV_PART_MAIN | LV_STATE_DEFAULT);
                    }
                    {
                        static lv_coord_t dsc[] = {0, LV_GRID_TEMPLATE_LAST};
                        lv_obj_set_style_grid_column_dsc_array(obj, dsc, LV_PART_MAIN | LV_STATE_DEFAULT);
                    }
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN_WRAP, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_column(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_row(obj, 9, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.obj36 = obj;
                            lv_obj_set_pos(obj, -3, -8);
                            lv_obj_set_size(obj, 185, 45);
                            lv_obj_add_event_cb(obj, action_zone_selected, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_max_width(obj, 536870911, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "1");
                                }
                                {
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    lv_obj_set_pos(obj, 112, 53);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text_static(obj, "поливать");
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.obj37 = obj;
                            lv_obj_set_pos(obj, -12, 44);
                            lv_obj_set_size(obj, 185, 45);
                            lv_obj_add_event_cb(obj, action_zone_selected, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "2");
                                }
                                {
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    lv_obj_set_pos(obj, 119, 43);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text_static(obj, "поливать");
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.obj38 = obj;
                            lv_obj_set_pos(obj, -12, 99);
                            lv_obj_set_size(obj, 185, 45);
                            lv_obj_add_event_cb(obj, action_zone_selected, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "3");
                                }
                                {
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    lv_obj_set_pos(obj, 109, 45);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text_static(obj, "поливать");
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.obj39 = obj;
                            lv_obj_set_pos(obj, -12, 154);
                            lv_obj_set_size(obj, 185, 45);
                            lv_obj_add_event_cb(obj, action_zone_selected, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "4");
                                }
                                {
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    lv_obj_set_pos(obj, 114, 39);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text_static(obj, "поливать");
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.obj40 = obj;
                            lv_obj_set_pos(obj, -12, 210);
                            lv_obj_set_size(obj, 185, 45);
                            lv_obj_add_event_cb(obj, action_zone_selected, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_max_width(obj, 536870911, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "5");
                                }
                                {
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    lv_obj_set_pos(obj, 112, 53);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text_static(obj, "поливать");
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.obj41 = obj;
                            lv_obj_set_pos(obj, -12, 265);
                            lv_obj_set_size(obj, 185, 45);
                            lv_obj_add_event_cb(obj, action_zone_selected, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_max_width(obj, 536870911, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "6");
                                }
                                {
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    lv_obj_set_pos(obj, 112, 53);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text_static(obj, "поливать");
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.obj42 = obj;
                            lv_obj_set_pos(obj, -12, 320);
                            lv_obj_set_size(obj, 185, 45);
                            lv_obj_add_event_cb(obj, action_zone_selected, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_max_width(obj, 536870911, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "7");
                                }
                                {
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    lv_obj_set_pos(obj, 112, 53);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text_static(obj, "поливать");
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.obj43 = obj;
                            lv_obj_set_pos(obj, -12, 375);
                            lv_obj_set_size(obj, 185, 45);
                            lv_obj_add_event_cb(obj, action_zone_selected, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_max_width(obj, 536870911, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "8\n");
                                }
                                {
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    lv_obj_set_pos(obj, 112, 53);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text_static(obj, "поливать");
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                }
                            }
                        }
                        {
                            // _9
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects._9 = obj;
                            lv_obj_set_pos(obj, 192, -8);
                            lv_obj_set_size(obj, 185, 45);
                            lv_obj_add_event_cb(obj, action_zone_selected, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_max_width(obj, 536870911, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "9");
                                }
                                {
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    lv_obj_set_pos(obj, 112, 53);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text_static(obj, "поливать");
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.obj44 = obj;
                            lv_obj_set_pos(obj, 181, 44);
                            lv_obj_set_size(obj, 185, 45);
                            lv_obj_add_event_cb(obj, action_zone_selected, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "10");
                                }
                                {
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    lv_obj_set_pos(obj, 119, 43);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text_static(obj, "поливать");
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.obj45 = obj;
                            lv_obj_set_pos(obj, 181, 99);
                            lv_obj_set_size(obj, 185, 45);
                            lv_obj_add_event_cb(obj, action_zone_selected, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "11");
                                }
                                {
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    lv_obj_set_pos(obj, 109, 45);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text_static(obj, "поливать");
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.obj46 = obj;
                            lv_obj_set_pos(obj, 181, 154);
                            lv_obj_set_size(obj, 185, 45);
                            lv_obj_add_event_cb(obj, action_zone_selected, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "12");
                                }
                                {
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    lv_obj_set_pos(obj, 114, 39);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text_static(obj, "поливать");
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.obj47 = obj;
                            lv_obj_set_pos(obj, 181, 210);
                            lv_obj_set_size(obj, 185, 45);
                            lv_obj_add_event_cb(obj, action_zone_selected, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_max_width(obj, 536870911, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "13");
                                }
                                {
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    lv_obj_set_pos(obj, 112, 53);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text_static(obj, "поливать");
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.obj48 = obj;
                            lv_obj_set_pos(obj, 181, 265);
                            lv_obj_set_size(obj, 185, 45);
                            lv_obj_add_event_cb(obj, action_zone_selected, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_max_width(obj, 536870911, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "14");
                                }
                                {
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    lv_obj_set_pos(obj, 112, 53);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text_static(obj, "поливать");
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.obj49 = obj;
                            lv_obj_set_pos(obj, 181, 320);
                            lv_obj_set_size(obj, 185, 45);
                            lv_obj_add_event_cb(obj, action_zone_selected, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_max_width(obj, 536870911, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "15");
                                }
                                {
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    lv_obj_set_pos(obj, 112, 53);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text_static(obj, "поливать");
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.obj50 = obj;
                            lv_obj_set_pos(obj, 181, 375);
                            lv_obj_set_size(obj, 185, 45);
                            lv_obj_add_event_cb(obj, action_zone_selected, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_max_width(obj, 536870911, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "16");
                                }
                                {
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    lv_obj_set_pos(obj, 104, 23);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text_static(obj, "поливать");
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                }
                            }
                        }
                        {
                            // _9_1
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects._9_1 = obj;
                            lv_obj_set_pos(obj, 388, -8);
                            lv_obj_set_size(obj, 185, 45);
                            lv_obj_add_event_cb(obj, action_zone_selected, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_max_width(obj, 536870911, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "17");
                                }
                                {
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    lv_obj_set_pos(obj, 112, 53);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text_static(obj, "поливать");
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.obj51 = obj;
                            lv_obj_set_pos(obj, 372, 44);
                            lv_obj_set_size(obj, 185, 45);
                            lv_obj_add_event_cb(obj, action_zone_selected, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "18");
                                }
                                {
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    lv_obj_set_pos(obj, 119, 43);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text_static(obj, "поливать");
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.obj52 = obj;
                            lv_obj_set_pos(obj, 372, 99);
                            lv_obj_set_size(obj, 185, 45);
                            lv_obj_add_event_cb(obj, action_zone_selected, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "19");
                                }
                                {
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    lv_obj_set_pos(obj, 109, 45);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text_static(obj, "поливать");
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.obj53 = obj;
                            lv_obj_set_pos(obj, 372, 154);
                            lv_obj_set_size(obj, 185, 45);
                            lv_obj_add_event_cb(obj, action_zone_selected, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "20");
                                }
                                {
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    lv_obj_set_pos(obj, 114, 39);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text_static(obj, "поливать");
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.obj54 = obj;
                            lv_obj_set_pos(obj, 372, 210);
                            lv_obj_set_size(obj, 185, 45);
                            lv_obj_add_event_cb(obj, action_zone_selected, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_max_width(obj, 536870911, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "21");
                                }
                                {
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    lv_obj_set_pos(obj, 112, 53);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text_static(obj, "поливать");
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.obj55 = obj;
                            lv_obj_set_pos(obj, 372, 265);
                            lv_obj_set_size(obj, 185, 45);
                            lv_obj_add_event_cb(obj, action_zone_selected, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_max_width(obj, 536870911, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "22");
                                }
                                {
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    lv_obj_set_pos(obj, 112, 53);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text_static(obj, "поливать");
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.obj56 = obj;
                            lv_obj_set_pos(obj, 372, 320);
                            lv_obj_set_size(obj, 185, 45);
                            lv_obj_add_event_cb(obj, action_zone_selected, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_max_width(obj, 536870911, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "23");
                                }
                                {
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    lv_obj_set_pos(obj, 112, 53);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text_static(obj, "поливать");
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.obj57 = obj;
                            lv_obj_set_pos(obj, 372, 375);
                            lv_obj_set_size(obj, 185, 45);
                            lv_obj_add_event_cb(obj, action_zone_selected, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_max_width(obj, 536870911, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "24");
                                }
                                {
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    lv_obj_set_pos(obj, 104, 23);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text_static(obj, "поливать");
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                }
                            }
                        }
                        {
                            // _25
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects._25 = obj;
                            lv_obj_set_pos(obj, 583, -8);
                            lv_obj_set_size(obj, 185, 45);
                            lv_obj_add_event_cb(obj, action_zone_selected, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_max_width(obj, 536870911, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "25");
                                }
                                {
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    lv_obj_set_pos(obj, 104, 23);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text_static(obj, "поливать");
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.obj58 = obj;
                            lv_obj_set_pos(obj, 574, 46);
                            lv_obj_set_size(obj, 185, 45);
                            lv_obj_add_event_cb(obj, action_zone_selected, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_max_width(obj, 536870911, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "26");
                                }
                                {
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    lv_obj_set_pos(obj, 104, 23);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text_static(obj, "поливать");
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.obj59 = obj;
                            lv_obj_set_pos(obj, 574, 100);
                            lv_obj_set_size(obj, 185, 45);
                            lv_obj_add_event_cb(obj, action_zone_selected, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_max_width(obj, 536870911, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "27");
                                }
                                {
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    lv_obj_set_pos(obj, 104, 23);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text_static(obj, "поливать");
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.obj60 = obj;
                            lv_obj_set_pos(obj, 574, 154);
                            lv_obj_set_size(obj, 185, 45);
                            lv_obj_add_event_cb(obj, action_zone_selected, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_max_width(obj, 536870911, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "28");
                                }
                                {
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    lv_obj_set_pos(obj, 104, 23);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text_static(obj, "поливать");
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.obj61 = obj;
                            lv_obj_set_pos(obj, 574, 209);
                            lv_obj_set_size(obj, 185, 45);
                            lv_obj_add_event_cb(obj, action_zone_selected, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_max_width(obj, 536870911, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "29");
                                }
                                {
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    lv_obj_set_pos(obj, 104, 23);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text_static(obj, "поливать");
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.obj62 = obj;
                            lv_obj_set_pos(obj, 574, 263);
                            lv_obj_set_size(obj, 185, 45);
                            lv_obj_add_event_cb(obj, action_zone_selected, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_max_width(obj, 536870911, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "30");
                                }
                                {
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    lv_obj_set_pos(obj, 104, 23);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text_static(obj, "поливать");
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.obj63 = obj;
                            lv_obj_set_pos(obj, 574, 317);
                            lv_obj_set_size(obj, 185, 45);
                            lv_obj_add_event_cb(obj, action_zone_selected, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_max_width(obj, 536870911, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "31");
                                }
                                {
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    lv_obj_set_pos(obj, 104, 23);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text_static(obj, "поливать");
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.obj64 = obj;
                            lv_obj_set_pos(obj, 574, 371);
                            lv_obj_set_size(obj, 185, 45);
                            lv_obj_add_event_cb(obj, action_zone_selected, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_max_width(obj, 536870911, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "32");
                                }
                                {
                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                    lv_obj_set_pos(obj, 104, 23);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_checkbox_set_text_static(obj, "поливать");
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                }
                            }
                        }
                    }
                }
                {
                    // tab_2
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Настройка зон");
                    objects.tab_2 = obj;
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // zone_times
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.zone_times = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 790, 428);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN_WRAP, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_row(obj, 9, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_column(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // zone1
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.zone1 = obj;
                                    lv_obj_set_pos(obj, -12, -11);
                                    lv_obj_set_size(obj, 185, 45);
                                    lv_obj_add_event_cb(obj, action_zone_time_clicked, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "1");
                                        }
                                        {
                                            // d_4
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.d_4 = obj;
                                            lv_obj_set_pos(obj, -6, -6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0");
                                        }
                                        {
                                            // c_4
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.c_4 = obj;
                                            lv_obj_set_pos(obj, 2, 23);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_color(obj, lv_color_hex(0x0b16cd), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "25");
                                        }
                                    }
                                }
                                {
                                    // zone2
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.zone2 = obj;
                                    lv_obj_set_pos(obj, -12, 45);
                                    lv_obj_set_size(obj, 185, 45);
                                    lv_obj_add_event_cb(obj, action_zone_time_clicked, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "2");
                                        }
                                        {
                                            // d_2
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.d_2 = obj;
                                            lv_obj_set_pos(obj, -6, -6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0");
                                        }
                                        {
                                            // c_2
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.c_2 = obj;
                                            lv_obj_set_pos(obj, 2, 23);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_color(obj, lv_color_hex(0x0b16cd), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "25");
                                        }
                                    }
                                }
                                {
                                    // zone3
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.zone3 = obj;
                                    lv_obj_set_pos(obj, -12, 100);
                                    lv_obj_set_size(obj, 185, 45);
                                    lv_obj_add_event_cb(obj, action_zone_time_clicked, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "3");
                                        }
                                        {
                                            // d_3
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.d_3 = obj;
                                            lv_obj_set_pos(obj, -6, -6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0");
                                        }
                                        {
                                            // c_3
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.c_3 = obj;
                                            lv_obj_set_pos(obj, 2, 23);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_color(obj, lv_color_hex(0x0b16cd), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "25");
                                        }
                                    }
                                }
                                {
                                    // zone4
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.zone4 = obj;
                                    lv_obj_set_pos(obj, -12, 156);
                                    lv_obj_set_size(obj, 185, 45);
                                    lv_obj_add_event_cb(obj, action_zone_time_clicked, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "4");
                                        }
                                        {
                                            // d_5
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.d_5 = obj;
                                            lv_obj_set_pos(obj, -6, -6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0");
                                        }
                                        {
                                            // c_5
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.c_5 = obj;
                                            lv_obj_set_pos(obj, 2, 23);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_color(obj, lv_color_hex(0x0b16cd), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "25");
                                        }
                                    }
                                }
                                {
                                    // zone5
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.zone5 = obj;
                                    lv_obj_set_pos(obj, -12, 211);
                                    lv_obj_set_size(obj, 185, 45);
                                    lv_obj_add_event_cb(obj, action_zone_time_clicked, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "5");
                                        }
                                        {
                                            // d_6
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.d_6 = obj;
                                            lv_obj_set_pos(obj, -6, -6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0");
                                        }
                                        {
                                            // c_6
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.c_6 = obj;
                                            lv_obj_set_pos(obj, 2, 23);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_color(obj, lv_color_hex(0x0b16cd), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "25");
                                        }
                                    }
                                }
                                {
                                    // zone6
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.zone6 = obj;
                                    lv_obj_set_pos(obj, -12, 267);
                                    lv_obj_set_size(obj, 185, 45);
                                    lv_obj_add_event_cb(obj, action_zone_time_clicked, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "6");
                                        }
                                        {
                                            // d_7
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.d_7 = obj;
                                            lv_obj_set_pos(obj, -6, -6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0");
                                        }
                                        {
                                            // c_7
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.c_7 = obj;
                                            lv_obj_set_pos(obj, 2, 23);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_color(obj, lv_color_hex(0x0b16cd), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "25");
                                        }
                                    }
                                }
                                {
                                    // zone7
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.zone7 = obj;
                                    lv_obj_set_pos(obj, -12, 322);
                                    lv_obj_set_size(obj, 185, 45);
                                    lv_obj_add_event_cb(obj, action_zone_time_clicked, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "7");
                                        }
                                        {
                                            // d_8
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.d_8 = obj;
                                            lv_obj_set_pos(obj, -6, -6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0");
                                        }
                                        {
                                            // c_8
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.c_8 = obj;
                                            lv_obj_set_pos(obj, 2, 23);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_color(obj, lv_color_hex(0x0b16cd), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "25");
                                        }
                                    }
                                }
                                {
                                    // zone8
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.zone8 = obj;
                                    lv_obj_set_pos(obj, -12, 378);
                                    lv_obj_set_size(obj, 185, 45);
                                    lv_obj_add_event_cb(obj, action_zone_time_clicked, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "8");
                                        }
                                        {
                                            // d_9
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.d_9 = obj;
                                            lv_obj_set_pos(obj, -6, -6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0");
                                        }
                                        {
                                            // c_9
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.c_9 = obj;
                                            lv_obj_set_pos(obj, 2, 23);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_color(obj, lv_color_hex(0x0b16cd), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "25");
                                        }
                                    }
                                }
                                {
                                    // zone9
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.zone9 = obj;
                                    lv_obj_set_pos(obj, 180, -11);
                                    lv_obj_set_size(obj, 185, 45);
                                    lv_obj_add_event_cb(obj, action_zone_time_clicked, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "9");
                                        }
                                        {
                                            // d_10
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.d_10 = obj;
                                            lv_obj_set_pos(obj, -6, -6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0");
                                        }
                                        {
                                            // c_10
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.c_10 = obj;
                                            lv_obj_set_pos(obj, 2, 23);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_color(obj, lv_color_hex(0x0b16cd), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "25");
                                        }
                                    }
                                }
                                {
                                    // zone10
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.zone10 = obj;
                                    lv_obj_set_pos(obj, 180, 45);
                                    lv_obj_set_size(obj, 185, 45);
                                    lv_obj_add_event_cb(obj, action_zone_time_clicked, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "10");
                                        }
                                        {
                                            // d_11
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.d_11 = obj;
                                            lv_obj_set_pos(obj, -6, -6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0");
                                        }
                                        {
                                            // c_11
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.c_11 = obj;
                                            lv_obj_set_pos(obj, 2, 23);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_color(obj, lv_color_hex(0x0b16cd), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "25");
                                        }
                                    }
                                }
                                {
                                    // zone11
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.zone11 = obj;
                                    lv_obj_set_pos(obj, 180, 100);
                                    lv_obj_set_size(obj, 185, 45);
                                    lv_obj_add_event_cb(obj, action_zone_time_clicked, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "11");
                                        }
                                        {
                                            // d_12
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.d_12 = obj;
                                            lv_obj_set_pos(obj, -6, -6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0");
                                        }
                                        {
                                            // c_12
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.c_12 = obj;
                                            lv_obj_set_pos(obj, 2, 23);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_color(obj, lv_color_hex(0x0b16cd), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "25");
                                        }
                                    }
                                }
                                {
                                    // zone12
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.zone12 = obj;
                                    lv_obj_set_pos(obj, 180, 156);
                                    lv_obj_set_size(obj, 185, 45);
                                    lv_obj_add_event_cb(obj, action_zone_time_clicked, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "12");
                                        }
                                        {
                                            // d_13
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.d_13 = obj;
                                            lv_obj_set_pos(obj, -6, -6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0");
                                        }
                                        {
                                            // c_13
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.c_13 = obj;
                                            lv_obj_set_pos(obj, 2, 23);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_color(obj, lv_color_hex(0x0b16cd), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "25");
                                        }
                                    }
                                }
                                {
                                    // zone13
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.zone13 = obj;
                                    lv_obj_set_pos(obj, 180, 211);
                                    lv_obj_set_size(obj, 185, 45);
                                    lv_obj_add_event_cb(obj, action_zone_time_clicked, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "13");
                                        }
                                        {
                                            // d_14
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.d_14 = obj;
                                            lv_obj_set_pos(obj, -6, -6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0");
                                        }
                                        {
                                            // c_14
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.c_14 = obj;
                                            lv_obj_set_pos(obj, 2, 23);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_color(obj, lv_color_hex(0x0b16cd), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "25");
                                        }
                                    }
                                }
                                {
                                    // zone14
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.zone14 = obj;
                                    lv_obj_set_pos(obj, 180, 267);
                                    lv_obj_set_size(obj, 185, 45);
                                    lv_obj_add_event_cb(obj, action_zone_time_clicked, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "14");
                                        }
                                        {
                                            // d_15
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.d_15 = obj;
                                            lv_obj_set_pos(obj, -6, -6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0");
                                        }
                                        {
                                            // c_15
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.c_15 = obj;
                                            lv_obj_set_pos(obj, 2, 23);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_color(obj, lv_color_hex(0x0b16cd), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "25");
                                        }
                                    }
                                }
                                {
                                    // zone15
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.zone15 = obj;
                                    lv_obj_set_pos(obj, 180, 322);
                                    lv_obj_set_size(obj, 185, 45);
                                    lv_obj_add_event_cb(obj, action_zone_time_clicked, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "15");
                                        }
                                        {
                                            // d_16
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.d_16 = obj;
                                            lv_obj_set_pos(obj, -6, -6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0");
                                        }
                                        {
                                            // c_16
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.c_16 = obj;
                                            lv_obj_set_pos(obj, 2, 23);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_color(obj, lv_color_hex(0x0b16cd), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "25");
                                        }
                                    }
                                }
                                {
                                    // zone16
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.zone16 = obj;
                                    lv_obj_set_pos(obj, 180, 378);
                                    lv_obj_set_size(obj, 185, 45);
                                    lv_obj_add_event_cb(obj, action_zone_time_clicked, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "16");
                                        }
                                        {
                                            // d_17
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.d_17 = obj;
                                            lv_obj_set_pos(obj, -6, -6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0");
                                        }
                                        {
                                            // c_17
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.c_17 = obj;
                                            lv_obj_set_pos(obj, 2, 23);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_color(obj, lv_color_hex(0x0b16cd), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "25");
                                        }
                                    }
                                }
                                {
                                    // zone16_1
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.zone16_1 = obj;
                                    lv_obj_set_pos(obj, 311, 368);
                                    lv_obj_set_size(obj, 185, 45);
                                    lv_obj_add_event_cb(obj, action_zone_time_clicked, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "17");
                                        }
                                        {
                                            // d_18
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.d_18 = obj;
                                            lv_obj_set_pos(obj, -6, -6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0");
                                        }
                                        {
                                            // c_18
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.c_18 = obj;
                                            lv_obj_set_pos(obj, 2, 23);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_color(obj, lv_color_hex(0x0b16cd), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "25");
                                        }
                                    }
                                }
                                {
                                    // zone16_2
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.zone16_2 = obj;
                                    lv_obj_set_pos(obj, 180, 378);
                                    lv_obj_set_size(obj, 185, 45);
                                    lv_obj_add_event_cb(obj, action_zone_time_clicked, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "18");
                                        }
                                        {
                                            // d_19
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.d_19 = obj;
                                            lv_obj_set_pos(obj, -6, -6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0");
                                        }
                                        {
                                            // c_19
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.c_19 = obj;
                                            lv_obj_set_pos(obj, 2, 23);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_color(obj, lv_color_hex(0x0b16cd), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "25");
                                        }
                                    }
                                }
                                {
                                    // zone16_3
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.zone16_3 = obj;
                                    lv_obj_set_pos(obj, 180, 378);
                                    lv_obj_set_size(obj, 185, 45);
                                    lv_obj_add_event_cb(obj, action_zone_time_clicked, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "19");
                                        }
                                        {
                                            // d_20
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.d_20 = obj;
                                            lv_obj_set_pos(obj, -6, -6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0");
                                        }
                                        {
                                            // c_20
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.c_20 = obj;
                                            lv_obj_set_pos(obj, 2, 23);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_color(obj, lv_color_hex(0x0b16cd), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "25");
                                        }
                                    }
                                }
                                {
                                    // zone16_4
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.zone16_4 = obj;
                                    lv_obj_set_pos(obj, 180, 378);
                                    lv_obj_set_size(obj, 185, 45);
                                    lv_obj_add_event_cb(obj, action_zone_time_clicked, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "20");
                                        }
                                        {
                                            // d_21
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.d_21 = obj;
                                            lv_obj_set_pos(obj, -6, -6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0");
                                        }
                                        {
                                            // c_21
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.c_21 = obj;
                                            lv_obj_set_pos(obj, 2, 23);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_color(obj, lv_color_hex(0x0b16cd), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "25");
                                        }
                                    }
                                }
                                {
                                    // zone16_5
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.zone16_5 = obj;
                                    lv_obj_set_pos(obj, 180, 378);
                                    lv_obj_set_size(obj, 185, 45);
                                    lv_obj_add_event_cb(obj, action_zone_time_clicked, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "21");
                                        }
                                        {
                                            // d_22
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.d_22 = obj;
                                            lv_obj_set_pos(obj, -6, -6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0");
                                        }
                                        {
                                            // c_22
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.c_22 = obj;
                                            lv_obj_set_pos(obj, 2, 23);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_color(obj, lv_color_hex(0x0b16cd), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "25");
                                        }
                                    }
                                }
                                {
                                    // zone16_6
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.zone16_6 = obj;
                                    lv_obj_set_pos(obj, 180, 378);
                                    lv_obj_set_size(obj, 185, 45);
                                    lv_obj_add_event_cb(obj, action_zone_time_clicked, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "22");
                                        }
                                        {
                                            // d_23
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.d_23 = obj;
                                            lv_obj_set_pos(obj, -6, -6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0");
                                        }
                                        {
                                            // c_23
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.c_23 = obj;
                                            lv_obj_set_pos(obj, 2, 23);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_color(obj, lv_color_hex(0x0b16cd), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "25");
                                        }
                                    }
                                }
                                {
                                    // zone16_7
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.zone16_7 = obj;
                                    lv_obj_set_pos(obj, 180, 378);
                                    lv_obj_set_size(obj, 185, 45);
                                    lv_obj_add_event_cb(obj, action_zone_time_clicked, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "23");
                                        }
                                        {
                                            // d_24
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.d_24 = obj;
                                            lv_obj_set_pos(obj, -6, -6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0");
                                        }
                                        {
                                            // c_24
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.c_24 = obj;
                                            lv_obj_set_pos(obj, 2, 23);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_color(obj, lv_color_hex(0x0b16cd), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "25");
                                        }
                                    }
                                }
                                {
                                    // zone16_8
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.zone16_8 = obj;
                                    lv_obj_set_pos(obj, 180, 378);
                                    lv_obj_set_size(obj, 185, 45);
                                    lv_obj_add_event_cb(obj, action_zone_time_clicked, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "24");
                                        }
                                        {
                                            // d_25
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.d_25 = obj;
                                            lv_obj_set_pos(obj, -6, -6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0");
                                        }
                                        {
                                            // c_25
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.c_25 = obj;
                                            lv_obj_set_pos(obj, 2, 23);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_color(obj, lv_color_hex(0x0b16cd), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "25");
                                        }
                                    }
                                }
                                {
                                    // zone16_9
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.zone16_9 = obj;
                                    lv_obj_set_pos(obj, 180, 378);
                                    lv_obj_set_size(obj, 185, 45);
                                    lv_obj_add_event_cb(obj, action_zone_time_clicked, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "25");
                                        }
                                        {
                                            // d_26
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.d_26 = obj;
                                            lv_obj_set_pos(obj, -6, -6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0");
                                        }
                                        {
                                            // c_26
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.c_26 = obj;
                                            lv_obj_set_pos(obj, 2, 23);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_color(obj, lv_color_hex(0x0b16cd), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "25");
                                        }
                                    }
                                }
                                {
                                    // zone16_10
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.zone16_10 = obj;
                                    lv_obj_set_pos(obj, 180, 378);
                                    lv_obj_set_size(obj, 185, 45);
                                    lv_obj_add_event_cb(obj, action_zone_time_clicked, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "26");
                                        }
                                        {
                                            // d_27
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.d_27 = obj;
                                            lv_obj_set_pos(obj, -6, -6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0");
                                        }
                                        {
                                            // c_27
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.c_27 = obj;
                                            lv_obj_set_pos(obj, 2, 23);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_color(obj, lv_color_hex(0x0b16cd), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "25");
                                        }
                                    }
                                }
                                {
                                    // zone16_11
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.zone16_11 = obj;
                                    lv_obj_set_pos(obj, 180, 378);
                                    lv_obj_set_size(obj, 185, 45);
                                    lv_obj_add_event_cb(obj, action_zone_time_clicked, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "27");
                                        }
                                        {
                                            // d_28
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.d_28 = obj;
                                            lv_obj_set_pos(obj, -6, -6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0");
                                        }
                                        {
                                            // c_28
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.c_28 = obj;
                                            lv_obj_set_pos(obj, 2, 23);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_color(obj, lv_color_hex(0x0b16cd), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "25");
                                        }
                                    }
                                }
                                {
                                    // zone16_12
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.zone16_12 = obj;
                                    lv_obj_set_pos(obj, 180, 378);
                                    lv_obj_set_size(obj, 185, 45);
                                    lv_obj_add_event_cb(obj, action_zone_time_clicked, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "28");
                                        }
                                        {
                                            // d_29
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.d_29 = obj;
                                            lv_obj_set_pos(obj, -6, -6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0");
                                        }
                                        {
                                            // c_29
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.c_29 = obj;
                                            lv_obj_set_pos(obj, 2, 23);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_color(obj, lv_color_hex(0x0b16cd), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "25");
                                        }
                                    }
                                }
                                {
                                    // zone16_13
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.zone16_13 = obj;
                                    lv_obj_set_pos(obj, 180, 378);
                                    lv_obj_set_size(obj, 185, 45);
                                    lv_obj_add_event_cb(obj, action_zone_time_clicked, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "29");
                                        }
                                        {
                                            // d_30
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.d_30 = obj;
                                            lv_obj_set_pos(obj, -6, -6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0");
                                        }
                                        {
                                            // c_30
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.c_30 = obj;
                                            lv_obj_set_pos(obj, 2, 23);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_color(obj, lv_color_hex(0x0b16cd), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "25");
                                        }
                                    }
                                }
                                {
                                    // zone16_14
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.zone16_14 = obj;
                                    lv_obj_set_pos(obj, 180, 378);
                                    lv_obj_set_size(obj, 185, 45);
                                    lv_obj_add_event_cb(obj, action_zone_time_clicked, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "30");
                                        }
                                        {
                                            // d_31
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.d_31 = obj;
                                            lv_obj_set_pos(obj, -6, -6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0");
                                        }
                                        {
                                            // c_31
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.c_31 = obj;
                                            lv_obj_set_pos(obj, 2, 23);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_color(obj, lv_color_hex(0x0b16cd), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "25");
                                        }
                                    }
                                }
                                {
                                    // zone16_15
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.zone16_15 = obj;
                                    lv_obj_set_pos(obj, 591, 324);
                                    lv_obj_set_size(obj, 185, 45);
                                    lv_obj_add_event_cb(obj, action_zone_time_clicked, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "31");
                                        }
                                        {
                                            // d_32
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.d_32 = obj;
                                            lv_obj_set_pos(obj, -6, -6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0");
                                        }
                                        {
                                            // c_32
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.c_32 = obj;
                                            lv_obj_set_pos(obj, 2, 23);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_color(obj, lv_color_hex(0x0b16cd), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "25");
                                        }
                                    }
                                }
                                {
                                    // zone16_16
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.zone16_16 = obj;
                                    lv_obj_set_pos(obj, 180, 378);
                                    lv_obj_set_size(obj, 185, 45);
                                    lv_obj_add_event_cb(obj, action_zone_time_clicked, LV_EVENT_RELEASED, (void *)0);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c6a44), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "32");
                                        }
                                        {
                                            // d_33
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.d_33 = obj;
                                            lv_obj_set_pos(obj, -6, -6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0");
                                        }
                                        {
                                            // c_33
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.c_33 = obj;
                                            lv_obj_set_pos(obj, 2, 23);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_color(obj, lv_color_hex(0x0b16cd), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "25");
                                        }
                                    }
                                }
                            }
                        }
                        {
                            // input_area
                            lv_obj_t *obj = lv_textarea_create(parent_obj);
                            objects.input_area = obj;
                            lv_obj_set_pos(obj, 465, 185);
                            lv_obj_set_size(obj, 40, 36);
                            lv_textarea_set_accepted_chars(obj, "0123456789");
                            lv_textarea_set_max_length(obj, 2);
                            lv_textarea_set_placeholder_text(obj, "минут");
                            lv_textarea_set_one_line(obj, true);
                            lv_textarea_set_password_mode(obj, false);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                            lv_obj_set_style_pad_top(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_row(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_column(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // keyboard
                            lv_obj_t *obj = lv_keyboard_create(parent_obj);
                            objects.keyboard = obj;
                            lv_obj_set_pos(obj, 451, 227);
                            lv_obj_set_size(obj, 292, 193);
                            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
                            lv_obj_add_event_cb(obj, action_input_done, LV_EVENT_READY, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // tab_settings
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Настройки");
                    objects.tab_settings = obj;
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // settings_tv
                            lv_obj_t *obj = lv_tabview_create(parent_obj);
                            objects.settings_tv = obj;
                            lv_obj_set_pos(obj, -20, -20);
                            lv_obj_set_size(obj, 800, 448);
                            lv_tabview_set_tab_bar_position(obj, LV_DIR_LEFT);
                            lv_tabview_set_tab_bar_size(obj, 130);
                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR);
                            lv_obj_set_style_text_font(obj, &ui_font_ubuntu_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Пауза");
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 1, 7);
                                            lv_obj_set_size(obj, 583, 31);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW_WRAP, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_row(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_column(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                static lv_coord_t dsc[] = {0, LV_GRID_TEMPLATE_LAST};
                                                lv_obj_set_style_grid_row_dsc_array(obj, dsc, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            }
                                            {
                                                static lv_coord_t dsc[] = {0, LV_GRID_TEMPLATE_LAST};
                                                lv_obj_set_style_grid_column_dsc_array(obj, dsc, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            }
                                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    lv_obj_set_pos(obj, -4, -2);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_label_set_text_static(obj, "Пауза для набора воды в бочку ");
                                                }
                                                {
                                                    // pause
                                                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                                                    objects.pause = obj;
                                                    lv_obj_set_pos(obj, 539, -18);
                                                    lv_obj_set_size(obj, 35, 26);
                                                    lv_textarea_set_accepted_chars(obj, "0123456789");
                                                    lv_textarea_set_max_length(obj, 3);
                                                    lv_textarea_set_text(obj, "10");
                                                    lv_textarea_set_one_line(obj, true);
                                                    lv_textarea_set_password_mode(obj, false);
                                                    lv_obj_add_event_cb(obj, action_pause_ready, LV_EVENT_READY, (void *)0);
                                                    lv_obj_add_event_cb(obj, action_pause_released, LV_EVENT_RELEASED, (void *)0);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_row(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_column(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                }
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    lv_obj_set_pos(obj, 253, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_label_set_text_static(obj, "мин.");
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, -14, 373);
                                            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(10));
                                            lv_label_set_text_static(obj, "Пауза  для наполнения бака. Устанавливается в минутах. Выключаются все клапана зон.");
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Экран");
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            // brightness
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            objects.brightness = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, 609, 66);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN_REVERSE, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    // bl
                                                    lv_obj_t *obj = lv_slider_create(parent_obj);
                                                    objects.bl = obj;
                                                    lv_obj_set_pos(obj, 4838, 90);
                                                    lv_obj_set_size(obj, 560, 10);
                                                    lv_slider_set_range(obj, 50, 253);
                                                    lv_slider_set_value(obj, 200, LV_ANIM_ON);
                                                    lv_obj_add_event_cb(obj, action_bl_released, LV_EVENT_RELEASED, (void *)0);
                                                    lv_obj_add_event_cb(obj, action_bl_changed, LV_EVENT_VALUE_CHANGED, (void *)0);
                                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                }
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_label_set_text_static(obj, "Яркость экрана");
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 95);
                                            lv_obj_set_size(obj, 309, 32);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW_WRAP, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_row(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_column(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    lv_obj_set_pos(obj, -4, -2);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_label_set_text_static(obj, "Автовыключение экрана ");
                                                }
                                                {
                                                    // bl_idle
                                                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                                                    objects.bl_idle = obj;
                                                    lv_obj_set_pos(obj, 222, -2);
                                                    lv_obj_set_size(obj, 30, 26);
                                                    lv_textarea_set_accepted_chars(obj, "0123456789");
                                                    lv_textarea_set_max_length(obj, 2);
                                                    lv_textarea_set_text(obj, "10");
                                                    lv_textarea_set_one_line(obj, true);
                                                    lv_textarea_set_password_mode(obj, false);
                                                    lv_obj_add_event_cb(obj, action_idle_time_unfocused, LV_EVENT_READY, (void *)0);
                                                    lv_obj_add_event_cb(obj, action_idle_time_focused, LV_EVENT_RELEASED, (void *)0);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_row(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_column(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                }
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    lv_obj_set_pos(obj, 253, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_label_set_text_static(obj, "сек.");
                                                }
                                            }
                                        }
                                        {
                                            // r_display
                                            lv_obj_t *obj = lv_button_create(parent_obj);
                                            objects.r_display = obj;
                                            lv_obj_set_pos(obj, 0, 147);
                                            lv_obj_set_size(obj, 300, 32);
                                            lv_obj_add_event_cb(obj, action_revert_display, LV_EVENT_RELEASED, (void *)0);
                                            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj65 = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Перевернуть экран");
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 395);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text_static(obj, "Автовыключение экрана можно установить от 10 до 99 секунд.");
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Пульт");
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 54, 3);
                                            lv_obj_set_size(obj, 352, 40);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    // pult
                                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                                    objects.pult = obj;
                                                    lv_obj_set_pos(obj, 0, 2);
                                                    lv_obj_set_size(obj, 50, 25);
                                                    lv_obj_add_event_cb(obj, action_use_pult, LV_EVENT_VALUE_CHANGED, (void *)0);
                                                }
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    lv_obj_set_pos(obj, 61, 3);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_label_set_text_static(obj, "Взаимодействовать с пультом");
                                                }
                                            }
                                        }
                                        {
                                            // esp_lora
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            objects.esp_lora = obj;
                                            lv_obj_set_pos(obj, 54, 55);
                                            lv_obj_set_size(obj, 331, 40);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_add_event_cb(obj, action_esp_lora_clicked, LV_EVENT_VALUE_CHANGED, (void *)0);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    // esp_now
                                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                                    objects.esp_now = obj;
                                                    lv_obj_set_pos(obj, -96, 4);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_checkbox_set_text_static(obj, "ESP-NOW");
                                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                                }
                                                {
                                                    // lora
                                                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                                    objects.lora = obj;
                                                    lv_obj_set_pos(obj, 110, 3);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_checkbox_set_text_static(obj, "LoRa");
                                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, -5, 328);
                                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                            lv_label_set_text_static(obj, "Пульт может работать по Lora или ESP-NOW.\nESP-NOW работает на частоте WiFi на небольшие растояния,\nLoRa работет на частоте 868MHz(разрешенный диапазон) на расстояние до нескольких километров.");
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Подкормка");
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                    {
                                        static lv_coord_t dsc[] = {0, LV_GRID_TEMPLATE_LAST};
                                        lv_obj_set_style_grid_row_dsc_array(obj, dsc, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    }
                                    {
                                        static lv_coord_t dsc[] = {0, LV_GRID_TEMPLATE_LAST};
                                        lv_obj_set_style_grid_column_dsc_array(obj, dsc, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    }
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            objects.obj66 = obj;
                                            lv_obj_set_pos(obj, 141, 150);
                                            lv_obj_set_size(obj, 349, 104);
                                            lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                            add_style_1style(obj);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_add_event_cb(obj, action_pump_pct_dec, LV_EVENT_CLICKED, (void *)0);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.obj67 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_text_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "-");
                                                        }
                                                    }
                                                }
                                                {
                                                    // pump_pct
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.pump_pct = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_label_set_text_static(obj, "33%");
                                                }
                                                {
                                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_add_event_cb(obj, action_pump_pct_inc, LV_EVENT_CLICKED, (void *)0);
                                                    {
                                                        static lv_coord_t dsc[] = {0, LV_GRID_TEMPLATE_LAST};
                                                        lv_obj_set_style_grid_row_dsc_array(obj, dsc, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    }
                                                    {
                                                        static lv_coord_t dsc[] = {0, LV_GRID_TEMPLATE_LAST};
                                                        lv_obj_set_style_grid_column_dsc_array(obj, dsc, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    }
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.obj68 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_text_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "+");
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 9, 368);
                                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                            lv_label_set_text_static(obj, "Время работы насоса подачи подкормки в процентах от времени полива зоны. Возможно установить от 20 до 50 процентов.");
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Обновление");
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_button_create(parent_obj);
                                            lv_obj_set_pos(obj, -9, 293);
                                            lv_obj_set_size(obj, 300, 32);
                                            lv_obj_add_event_cb(obj, action_update, LV_EVENT_RELEASED, (void *)0);
                                            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    // update
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.update = obj;
                                                    lv_obj_set_pos(obj, 0, -1);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Обновление прошивок");
                                                }
                                            }
                                        }
                                        {
                                            // version
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.version = obj;
                                            lv_obj_set_pos(obj, -9, 394);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text_static(obj, "Текущая версия прошивки 0,0");
                                        }
                                        {
                                            lv_obj_t *obj = lv_qrcode_create(parent_obj);
                                            objects.obj69 = obj;
                                            lv_obj_set_pos(obj, 434, 229);
                                            lv_obj_set_size(obj, 160, 160);
                                            lv_qrcode_set_size(obj, 160);
                                            lv_qrcode_set_dark_color(obj, lv_color_hex(0x20429f));
                                            lv_qrcode_set_light_color(obj, lv_color_hex(0xe2f5fe));
                                            lv_qrcode_update(obj, "https://github.com/dicson/Pumps-lsd-controller/releases/latest", 62);
                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                        }
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 424, 400);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text_static(obj, "Прошивка на Github");
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Отладка");
                                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 237, 184);
                                            lv_obj_set_size(obj, 157, 40);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    // debug
                                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                                    objects.debug = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 50, 25);
                                                    lv_obj_add_event_cb(obj, action_debug, LV_EVENT_VALUE_CHANGED, (void *)0);
                                                }
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    lv_obj_set_pos(obj, 61, 4);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_label_set_text_static(obj, "Отладка");
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 370);
                                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                            lv_label_set_text_static(obj, "Ускоренное в 60 раз выполнение программы с игнорированием ошибок связи с реле,пультом,контроллером тока.");
                                        }
                                    }
                                }
                            }
                        }
                        {
                            // settings_kb
                            lv_obj_t *obj = lv_keyboard_create(parent_obj);
                            objects.settings_kb = obj;
                            lv_obj_set_pos(obj, 464, 174);
                            lv_obj_set_size(obj, 300, 204);
                            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_spinner_create(parent_obj);
            lv_obj_set_pos(obj, 17, -49);
            lv_obj_set_size(obj, 40, 33);
        }
    }
    lv_keyboard_set_textarea(objects.keyboard, objects.input_area);
    
    tick_screen_main();
}

void delete_screen_main() {
    lv_obj_delete(objects.main);
    objects.main = 0;
    objects.tabview = 0;
    objects.tab_main = 0;
    objects.prog_bar = 0;
    objects.bar_label = 0;
    objects.spinner = 0;
    objects.stop = 0;
    objects.start = 0;
    objects.obj0 = 0;
    objects.plant_food = 0;
    objects.pump = 0;
    objects.tank = 0;
    objects.tank_time = 0;
    objects.pause_bar = 0;
    objects.bars_panel = 0;
    objects.bar_0 = 0;
    objects.obj1 = 0;
    objects.bar_1 = 0;
    objects.obj2 = 0;
    objects.bar_2 = 0;
    objects.obj3 = 0;
    objects.bar_3 = 0;
    objects.obj4 = 0;
    objects.bar_4 = 0;
    objects.obj5 = 0;
    objects.bar_5 = 0;
    objects.obj6 = 0;
    objects.bar_6 = 0;
    objects.obj7 = 0;
    objects.bar_7 = 0;
    objects.obj8 = 0;
    objects.bar_8 = 0;
    objects.obj9 = 0;
    objects.bar_9 = 0;
    objects.obj10 = 0;
    objects.bar_10 = 0;
    objects.obj11 = 0;
    objects.bar_11 = 0;
    objects.obj12 = 0;
    objects.bar_12 = 0;
    objects.obj13 = 0;
    objects.bar_13 = 0;
    objects.obj14 = 0;
    objects.bar_14 = 0;
    objects.obj15 = 0;
    objects.bar_15 = 0;
    objects.obj16 = 0;
    objects.bar_16 = 0;
    objects.obj17 = 0;
    objects.bar_17 = 0;
    objects.obj18 = 0;
    objects.bar_18 = 0;
    objects.obj19 = 0;
    objects.bar_19 = 0;
    objects.obj20 = 0;
    objects.bar_20 = 0;
    objects.obj21 = 0;
    objects.bar_21 = 0;
    objects.obj22 = 0;
    objects.bar_22 = 0;
    objects.obj23 = 0;
    objects.bar_23 = 0;
    objects.obj24 = 0;
    objects.bar_24 = 0;
    objects.obj25 = 0;
    objects.bar_25 = 0;
    objects.obj26 = 0;
    objects.bar_26 = 0;
    objects.obj27 = 0;
    objects.bar_27 = 0;
    objects.obj28 = 0;
    objects.bar_28 = 0;
    objects.obj29 = 0;
    objects.bar_29 = 0;
    objects.obj30 = 0;
    objects.bar_30 = 0;
    objects.obj31 = 0;
    objects.message_box = 0;
    objects.k_panel = 0;
    objects.k_dw_time = 0;
    objects.button_10 = 0;
    objects.obj32 = 0;
    objects.button_dec = 0;
    objects.obj33 = 0;
    objects.button_reset = 0;
    objects.k_reset = 0;
    objects.button_inc = 0;
    objects.obj34 = 0;
    objects.button10 = 0;
    objects.obj35 = 0;
    objects.pause_btn = 0;
    objects.pause_btn_label = 0;
    objects.tank_empty = 0;
    objects.tab_1 = 0;
    objects.obj36 = 0;
    objects.obj37 = 0;
    objects.obj38 = 0;
    objects.obj39 = 0;
    objects.obj40 = 0;
    objects.obj41 = 0;
    objects.obj42 = 0;
    objects.obj43 = 0;
    objects._9 = 0;
    objects.obj44 = 0;
    objects.obj45 = 0;
    objects.obj46 = 0;
    objects.obj47 = 0;
    objects.obj48 = 0;
    objects.obj49 = 0;
    objects.obj50 = 0;
    objects._9_1 = 0;
    objects.obj51 = 0;
    objects.obj52 = 0;
    objects.obj53 = 0;
    objects.obj54 = 0;
    objects.obj55 = 0;
    objects.obj56 = 0;
    objects.obj57 = 0;
    objects._25 = 0;
    objects.obj58 = 0;
    objects.obj59 = 0;
    objects.obj60 = 0;
    objects.obj61 = 0;
    objects.obj62 = 0;
    objects.obj63 = 0;
    objects.obj64 = 0;
    objects.tab_2 = 0;
    objects.zone_times = 0;
    objects.zone1 = 0;
    objects.d_4 = 0;
    objects.c_4 = 0;
    objects.zone2 = 0;
    objects.d_2 = 0;
    objects.c_2 = 0;
    objects.zone3 = 0;
    objects.d_3 = 0;
    objects.c_3 = 0;
    objects.zone4 = 0;
    objects.d_5 = 0;
    objects.c_5 = 0;
    objects.zone5 = 0;
    objects.d_6 = 0;
    objects.c_6 = 0;
    objects.zone6 = 0;
    objects.d_7 = 0;
    objects.c_7 = 0;
    objects.zone7 = 0;
    objects.d_8 = 0;
    objects.c_8 = 0;
    objects.zone8 = 0;
    objects.d_9 = 0;
    objects.c_9 = 0;
    objects.zone9 = 0;
    objects.d_10 = 0;
    objects.c_10 = 0;
    objects.zone10 = 0;
    objects.d_11 = 0;
    objects.c_11 = 0;
    objects.zone11 = 0;
    objects.d_12 = 0;
    objects.c_12 = 0;
    objects.zone12 = 0;
    objects.d_13 = 0;
    objects.c_13 = 0;
    objects.zone13 = 0;
    objects.d_14 = 0;
    objects.c_14 = 0;
    objects.zone14 = 0;
    objects.d_15 = 0;
    objects.c_15 = 0;
    objects.zone15 = 0;
    objects.d_16 = 0;
    objects.c_16 = 0;
    objects.zone16 = 0;
    objects.d_17 = 0;
    objects.c_17 = 0;
    objects.zone16_1 = 0;
    objects.d_18 = 0;
    objects.c_18 = 0;
    objects.zone16_2 = 0;
    objects.d_19 = 0;
    objects.c_19 = 0;
    objects.zone16_3 = 0;
    objects.d_20 = 0;
    objects.c_20 = 0;
    objects.zone16_4 = 0;
    objects.d_21 = 0;
    objects.c_21 = 0;
    objects.zone16_5 = 0;
    objects.d_22 = 0;
    objects.c_22 = 0;
    objects.zone16_6 = 0;
    objects.d_23 = 0;
    objects.c_23 = 0;
    objects.zone16_7 = 0;
    objects.d_24 = 0;
    objects.c_24 = 0;
    objects.zone16_8 = 0;
    objects.d_25 = 0;
    objects.c_25 = 0;
    objects.zone16_9 = 0;
    objects.d_26 = 0;
    objects.c_26 = 0;
    objects.zone16_10 = 0;
    objects.d_27 = 0;
    objects.c_27 = 0;
    objects.zone16_11 = 0;
    objects.d_28 = 0;
    objects.c_28 = 0;
    objects.zone16_12 = 0;
    objects.d_29 = 0;
    objects.c_29 = 0;
    objects.zone16_13 = 0;
    objects.d_30 = 0;
    objects.c_30 = 0;
    objects.zone16_14 = 0;
    objects.d_31 = 0;
    objects.c_31 = 0;
    objects.zone16_15 = 0;
    objects.d_32 = 0;
    objects.c_32 = 0;
    objects.zone16_16 = 0;
    objects.d_33 = 0;
    objects.c_33 = 0;
    objects.input_area = 0;
    objects.keyboard = 0;
    objects.tab_settings = 0;
    objects.settings_tv = 0;
    objects.pause = 0;
    objects.brightness = 0;
    objects.bl = 0;
    objects.bl_idle = 0;
    objects.r_display = 0;
    objects.obj65 = 0;
    objects.pult = 0;
    objects.esp_lora = 0;
    objects.esp_now = 0;
    objects.lora = 0;
    objects.obj66 = 0;
    objects.obj67 = 0;
    objects.pump_pct = 0;
    objects.obj68 = 0;
    objects.update = 0;
    objects.version = 0;
    objects.obj69 = 0;
    objects.debug = 0;
    objects.settings_kb = 0;
}

void tick_screen_main() {
}

void create_screen_update_display() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.update_display = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj70 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 480);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            add_style_1style(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj71 = obj;
                    lv_obj_set_pos(obj, -22, -22);
                    lv_obj_set_size(obj, 800, 480);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        static lv_coord_t dsc[] = {0, LV_GRID_TEMPLATE_LAST};
                        lv_obj_set_style_grid_row_dsc_array(obj, dsc, LV_PART_MAIN | LV_STATE_DEFAULT);
                    }
                    {
                        static lv_coord_t dsc[] = {0, LV_GRID_TEMPLATE_LAST};
                        lv_obj_set_style_grid_column_dsc_array(obj, dsc, LV_PART_MAIN | LV_STATE_DEFAULT);
                    }
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.obj72 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 383, 281);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                static lv_coord_t dsc[] = {0, LV_GRID_TEMPLATE_LAST};
                                lv_obj_set_style_grid_row_dsc_array(obj, dsc, LV_PART_MAIN | LV_STATE_DEFAULT);
                            }
                            {
                                static lv_coord_t dsc[] = {0, LV_GRID_TEMPLATE_LAST};
                                lv_obj_set_style_grid_column_dsc_array(obj, dsc, LV_PART_MAIN | LV_STATE_DEFAULT);
                            }
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                                    objects.obj73 = obj;
                                    lv_obj_set_pos(obj, -1185, 11);
                                    lv_obj_set_size(obj, 369, 71);
                                    lv_textarea_set_max_length(obj, 128);
                                    lv_textarea_set_text(obj, "WiFi сеть  (SSID): Pump_controller\nПароль Wi-Fi сети: 80100000");
                                    lv_textarea_set_one_line(obj, false);
                                    lv_textarea_set_password_mode(obj, false);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                                {
                                    lv_obj_t *obj = lv_qrcode_create(parent_obj);
                                    objects.obj74 = obj;
                                    lv_obj_set_pos(obj, 1409, -935);
                                    lv_obj_set_size(obj, 166, 166);
                                    lv_qrcode_set_size(obj, 166);
                                    lv_qrcode_set_dark_color(obj, lv_color_hex(0x20429f));
                                    lv_qrcode_set_light_color(obj, lv_color_hex(0xe2f5fe));
                                    lv_qrcode_update(obj, "WIFI:S:Pump_controller;T:WPA2;P:80100000;;", 42);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.obj75 = obj;
                            lv_obj_set_pos(obj, 523, 0);
                            lv_obj_set_size(obj, 277, 281);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                                    objects.obj76 = obj;
                                    lv_obj_set_pos(obj, 104, -52);
                                    lv_obj_set_size(obj, 268, 76);
                                    lv_textarea_set_max_length(obj, 128);
                                    lv_textarea_set_text(obj, "Перейти на страницу:\nhttp://192.168.4.1/update");
                                    lv_textarea_set_one_line(obj, false);
                                    lv_textarea_set_password_mode(obj, false);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        static lv_coord_t dsc[] = {0, LV_GRID_TEMPLATE_LAST};
                                        lv_obj_set_style_grid_row_dsc_array(obj, dsc, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    }
                                    {
                                        static lv_coord_t dsc[] = {0, LV_GRID_TEMPLATE_LAST};
                                        lv_obj_set_style_grid_column_dsc_array(obj, dsc, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    }
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                                {
                                    lv_obj_t *obj = lv_qrcode_create(parent_obj);
                                    objects.obj77 = obj;
                                    lv_obj_set_pos(obj, -404, 122);
                                    lv_obj_set_size(obj, 166, 166);
                                    lv_qrcode_set_size(obj, 166);
                                    lv_qrcode_set_dark_color(obj, lv_color_hex(0x20429f));
                                    lv_qrcode_set_light_color(obj, lv_color_hex(0xe2f5fe));
                                    lv_qrcode_update(obj, "http://192.168.4.1/update", 25);
                                    lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                }
                            }
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 3, 287);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text_static(obj, " 1. Возьмите телефон или ноутбук и подключитесь к сети:\n  - SSID: Pump_controller - Пароль: 80100000\n 2. Откройте браузер и введите адрес: http://192.168.4.1/update\n  - Нажмите <Choose File>  выберите файл  *.bin\n  - Нажмите <Update> и дождитесь завершения.\n 3. Завершение: Устройство перезагрузится и вернется в обычный режим работы.");
                }
            }
        }
    }
    
    tick_screen_update_display();
}

void delete_screen_update_display() {
    lv_obj_delete(objects.update_display);
    objects.update_display = 0;
    objects.obj70 = 0;
    objects.obj71 = 0;
    objects.obj72 = 0;
    objects.obj73 = 0;
    objects.obj74 = 0;
    objects.obj75 = 0;
    objects.obj76 = 0;
    objects.obj77 = 0;
}

void tick_screen_update_display() {
}

void create_screen_update_selector() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.update_selector = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj78 = obj;
            lv_obj_set_pos(obj, 0, 165);
            lv_obj_set_size(obj, 800, 150);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_ubuntu_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_button_create(parent_obj);
                    lv_obj_set_pos(obj, 996, 0);
                    lv_obj_set_size(obj, 200, 50);
                    lv_obj_add_event_cb(obj, action_update_display, LV_EVENT_RELEASED, (void *)0);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj79 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text_static(obj, "Обновление дисплея");
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_button_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 200, 50);
                    lv_obj_add_event_cb(obj, action_update_relay, LV_EVENT_RELEASED, (void *)0);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj80 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text_static(obj, "Обновление реле");
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_button_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 100, 50);
                    lv_obj_add_event_cb(obj, action_update_back, LV_EVENT_RELEASED, (void *)0);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj81 = obj;
                            lv_obj_set_pos(obj, 8, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text_static(obj, "Назад");
                        }
                        {
                            lv_obj_t *obj = lv_image_create(parent_obj);
                            lv_obj_set_pos(obj, -9, 5);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_image_set_src(obj, &img_revers);
                        }
                    }
                }
            }
        }
    }
    
    tick_screen_update_selector();
}

void delete_screen_update_selector() {
    lv_obj_delete(objects.update_selector);
    objects.update_selector = 0;
    objects.obj78 = 0;
    objects.obj79 = 0;
    objects.obj80 = 0;
    objects.obj81 = 0;
}

void tick_screen_update_selector() {
}

void create_screen_update_relay() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.update_relay = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_set_style_text_font(obj, &ui_font_ubuntu_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 146);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_margin_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 11, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text_static(obj, "Запустить обновление прошивки на блоке реле:");
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 650, 64);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 144, 50);
                            lv_obj_add_event_cb(obj, action_update_relay_1, LV_EVENT_RELEASED, (void *)0);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj82 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "Блок реле 1");
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 144, 50);
                            lv_obj_add_event_cb(obj, action_update_relay_2, LV_EVENT_RELEASED, (void *)0);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj83 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "Блок реле 2");
                                }
                            }
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj84 = obj;
            lv_obj_set_pos(obj, 0, 171);
            lv_obj_set_size(obj, 330, 281);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                static lv_coord_t dsc[] = {0, LV_GRID_TEMPLATE_LAST};
                lv_obj_set_style_grid_row_dsc_array(obj, dsc, LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                static lv_coord_t dsc[] = {0, LV_GRID_TEMPLATE_LAST};
                lv_obj_set_style_grid_column_dsc_array(obj, dsc, LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.obj85 = obj;
                    lv_obj_set_pos(obj, 0, 36);
                    lv_obj_set_size(obj, 326, 60);
                    lv_textarea_set_max_length(obj, 128);
                    lv_textarea_set_text(obj, "WiFi сеть  (SSID): Relay_module\nПароль Wi-Fi сети: 80100000");
                    lv_textarea_set_one_line(obj, false);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_qrcode_create(parent_obj);
                    objects.obj86 = obj;
                    lv_obj_set_pos(obj, -436, 49);
                    lv_obj_set_size(obj, 166, 164);
                    lv_qrcode_set_size(obj, 164);
                    lv_qrcode_set_dark_color(obj, lv_color_hex(0x20429f));
                    lv_qrcode_set_light_color(obj, lv_color_hex(0xe2f5fe));
                    lv_qrcode_update(obj, "WIFI:S:Relay_module;T:WPA2;P:80100000;;", 39);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj87 = obj;
            lv_obj_set_pos(obj, 477, 171);
            lv_obj_set_size(obj, 314, 281);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.obj88 = obj;
                    lv_obj_set_pos(obj, 104, -52);
                    lv_obj_set_size(obj, 268, 60);
                    lv_textarea_set_max_length(obj, 128);
                    lv_textarea_set_text(obj, "Перейти на страницу:\nhttp://192.168.4.1/update");
                    lv_textarea_set_one_line(obj, false);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_qrcode_create(parent_obj);
                    objects.obj89 = obj;
                    lv_obj_set_pos(obj, -1094, 119);
                    lv_obj_set_size(obj, 166, 164);
                    lv_qrcode_set_size(obj, 164);
                    lv_qrcode_set_dark_color(obj, lv_color_hex(0x20429f));
                    lv_qrcode_set_light_color(obj, lv_color_hex(0xe2f5fe));
                    lv_qrcode_update(obj, "http://192.168.4.1/update", 25);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                }
            }
        }
        {
            // update_relay_back
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.update_relay_back = obj;
            lv_obj_set_pos(obj, 350, 416);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, action_update_relay_back, LV_EVENT_RELEASED, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj90 = obj;
                    lv_obj_set_pos(obj, 9, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Выход");
                }
                {
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    lv_obj_set_pos(obj, -9, 5);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_image_set_src(obj, &img_revers);
                }
            }
        }
    }
    
    tick_screen_update_relay();
}

void delete_screen_update_relay() {
    lv_obj_delete(objects.update_relay);
    objects.update_relay = 0;
    objects.obj82 = 0;
    objects.obj83 = 0;
    objects.obj84 = 0;
    objects.obj85 = 0;
    objects.obj86 = 0;
    objects.obj87 = 0;
    objects.obj88 = 0;
    objects.obj89 = 0;
    objects.update_relay_back = 0;
    objects.obj90 = 0;
}

void tick_screen_update_relay() {
}

typedef void (*create_screen_func_t)();
create_screen_func_t create_screen_funcs[] = {
    create_screen_main,
    create_screen_update_display,
    create_screen_update_selector,
    create_screen_update_relay,
};
void create_screen(int screen_index) {
    create_screen_funcs[screen_index]();
}
void create_screen_by_id(enum ScreensEnum screenId) {
    create_screen_funcs[screenId - 1]();
}

typedef void (*delete_screen_func_t)();
delete_screen_func_t delete_screen_funcs[] = {
    delete_screen_main,
    delete_screen_update_display,
    delete_screen_update_selector,
    delete_screen_update_relay,
};
void delete_screen(int screen_index) {
    delete_screen_funcs[screen_index]();
}
void delete_screen_by_id(enum ScreensEnum screenId) {
    delete_screen_funcs[screenId - 1]();
}

typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_update_display,
    tick_screen_update_selector,
    tick_screen_update_relay,
};
void tick_screen(int screen_index) {
    if (screen_index >= 0 && screen_index < 4) {
        tick_screen_funcs[screen_index]();
    }
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen(screenId - 1);
}

//
// Fonts
//

ext_font_desc_t fonts[] = {
    { "ubuntu 20", &ui_font_ubuntu_20 },
#if LV_FONT_MONTSERRAT_8
    { "MONTSERRAT_8", &lv_font_montserrat_8 },
#endif
#if LV_FONT_MONTSERRAT_10
    { "MONTSERRAT_10", &lv_font_montserrat_10 },
#endif
#if LV_FONT_MONTSERRAT_12
    { "MONTSERRAT_12", &lv_font_montserrat_12 },
#endif
#if LV_FONT_MONTSERRAT_14
    { "MONTSERRAT_14", &lv_font_montserrat_14 },
#endif
#if LV_FONT_MONTSERRAT_16
    { "MONTSERRAT_16", &lv_font_montserrat_16 },
#endif
#if LV_FONT_MONTSERRAT_18
    { "MONTSERRAT_18", &lv_font_montserrat_18 },
#endif
#if LV_FONT_MONTSERRAT_20
    { "MONTSERRAT_20", &lv_font_montserrat_20 },
#endif
#if LV_FONT_MONTSERRAT_22
    { "MONTSERRAT_22", &lv_font_montserrat_22 },
#endif
#if LV_FONT_MONTSERRAT_24
    { "MONTSERRAT_24", &lv_font_montserrat_24 },
#endif
#if LV_FONT_MONTSERRAT_26
    { "MONTSERRAT_26", &lv_font_montserrat_26 },
#endif
#if LV_FONT_MONTSERRAT_28
    { "MONTSERRAT_28", &lv_font_montserrat_28 },
#endif
#if LV_FONT_MONTSERRAT_30
    { "MONTSERRAT_30", &lv_font_montserrat_30 },
#endif
#if LV_FONT_MONTSERRAT_32
    { "MONTSERRAT_32", &lv_font_montserrat_32 },
#endif
#if LV_FONT_MONTSERRAT_34
    { "MONTSERRAT_34", &lv_font_montserrat_34 },
#endif
#if LV_FONT_MONTSERRAT_36
    { "MONTSERRAT_36", &lv_font_montserrat_36 },
#endif
#if LV_FONT_MONTSERRAT_38
    { "MONTSERRAT_38", &lv_font_montserrat_38 },
#endif
#if LV_FONT_MONTSERRAT_40
    { "MONTSERRAT_40", &lv_font_montserrat_40 },
#endif
#if LV_FONT_MONTSERRAT_42
    { "MONTSERRAT_42", &lv_font_montserrat_42 },
#endif
#if LV_FONT_MONTSERRAT_44
    { "MONTSERRAT_44", &lv_font_montserrat_44 },
#endif
#if LV_FONT_MONTSERRAT_46
    { "MONTSERRAT_46", &lv_font_montserrat_46 },
#endif
#if LV_FONT_MONTSERRAT_48
    { "MONTSERRAT_48", &lv_font_montserrat_48 },
#endif
};

//
// Color themes
//

uint32_t active_theme_index = 0;

//
//
//

void create_screens() {

// Set default LVGL theme
    lv_display_t *dispp = lv_display_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_display_set_theme(dispp, theme);
    
    // Initialize screens
    // Create screens
    create_screen_main();
}