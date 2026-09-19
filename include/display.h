#ifndef DISPLAY_H
#define DISPLAY_H

#include <lvgl.h>
#include "ui/ui.h"

// --- Hardware Configuration ---
#define CUSTOM_TFT_BL 2
#define GFX_BL 2

// --- External variables (defined in settings or elsewhere) ---
extern uint32_t GFX_BL_VALUE;
extern uint32_t GFX_BL_TIME;
extern int ROTATION;

// --- Function Prototypes ---
void setup_display();
void loop_display();
void revert_display();
#endif
