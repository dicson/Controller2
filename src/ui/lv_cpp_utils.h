// lv_cpp_utils.h
#ifndef LV_CPP_UTILS_H
#define LV_CPP_UTILS_H

#include <lvgl.h>

#if defined(__cplusplus)
constexpr lv_style_selector_t operator|(lv_part_t part, lv_state_t state) {
    return static_cast<lv_style_selector_t>(part) | static_cast<lv_style_selector_t>(state);
}

constexpr lv_style_selector_t operator|(lv_state_t state, lv_part_t part) {
    return static_cast<lv_style_selector_t>(part) | static_cast<lv_style_selector_t>(state);
}
#endif

#endif // LV_CPP_UTILS_H