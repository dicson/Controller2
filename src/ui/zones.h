#include <lvgl.h>
#include "constants.h"
#include "screens.h"
#include "styles.h"
#include "actions.h"
#include "lv_cpp_utils.h"

extern uint32_t dw_time[PUMP_AMOUNT]; // время полива грязной водой

void create_zone_bars()
{
    lv_obj_t *parent_obj = objects.bars_panel;
    for (int i = 0; i < PUMP_AMOUNT; i++)
    {
        // bar_0
        lv_obj_t *obj = lv_bar_create(parent_obj);
        lv_obj_set_size(obj, 110, 19);
        lv_obj_set_hidden(obj, true);
        lv_obj_set_style_radius(obj, 3, LV_PART_INDICATOR);
        lv_obj_set_style_radius(obj, 3, LV_STATE_DEFAULT);
        lv_obj_set_style_radius(obj, 3, LV_PART_MAIN);

        lv_obj_set_style_bg_color(obj, lv_color_hex(0x087343), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        {
            lv_obj_t *parent_obj = obj;
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_fmt(obj, "ЗОНА  %d", i + 1);
        }
    }
}

void create_zone_selection()
{
    lv_obj_t *parent_obj = objects.tab_1;
    for (int i = 0; i < PUMP_AMOUNT; i++)
    {
        lv_obj_t *obj = lv_button_create(parent_obj);
        lv_obj_set_size(obj, 185, 45);
        lv_obj_add_event_cb(obj, action_zone_selected, LV_EVENT_RELEASED, (void *)0);
        lv_obj_set_clickable(obj, false);
        add_style_button(obj);
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
                lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_label_set_text_fmt(obj, "%d", i + 1);
            }
            {
                lv_obj_t *obj = lv_checkbox_create(parent_obj);
                lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                lv_checkbox_set_text_static(obj, "поливать");
                lv_obj_set_event_bubble(obj, true);
            }
        }
    }
}

void create_zone_times_buttons()
{

    lv_obj_t *parent_obj = objects.zone_times;
    for (int i = 0; i < PUMP_AMOUNT; i++)
    {
        // zone
        lv_obj_t *obj = lv_button_create(parent_obj);
        // objects.zone1 = obj;
        lv_obj_set_size(obj, 185, 45);
        lv_obj_add_event_cb(obj, action_zone_time_clicked, LV_EVENT_RELEASED, (void *)0);
        lv_obj_set_checkable(obj, false);
        add_style_button(obj);
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
                lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_label_set_text_fmt(obj, "%d", i + 1);
            }
            {
                lv_obj_t *obj = lv_label_create(parent_obj);
                lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                lv_obj_set_event_bubble(obj, true);
                lv_obj_set_clickable(obj, true);
                lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                // lv_obj_set_style_outline_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                // lv_obj_set_style_outline_pad(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_label_set_text_fmt(obj, "%u мин.", dw_time[i]);
                lv_obj_set_ext_click_area(obj, EXT_CLICK_AREA_SMALL);
                if (dw_time[i] != 0)
                    lv_obj_set_style_bg_opa(parent_obj, FULL_OPACITY, LV_PART_MAIN);
                else
                    lv_obj_set_style_bg_opa(parent_obj, LOW_OPACITY, LV_PART_MAIN);
            }
        }
    }
}

void create_zones_widgets()
{
    create_zone_times_buttons();
    create_zone_selection();
    create_zone_bars();
}