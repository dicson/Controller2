#ifndef DISPLAY_H
#define DISPLAY_H

#include <lvgl.h>
#include <Arduino_GFX_Library.h>
#include "TAMC_GT911.h"
#include "ui/ui.h"

// --- Hardware Configuration ---
#define TOUCH_GT911_SCL 20
#define TOUCH_GT911_SDA 19
#define TOUCH_GT911_INT -1
#define TOUCH_GT911_RST 38
#define TOUCH_MAP_X1 800
#define TOUCH_MAP_X2 0
#define TOUCH_MAP_Y1 480
#define TOUCH_MAP_Y2 0
#define CUSTOM_TFT_BL 2
#define GFX_BL 2

// --- External variables (defined in settings or elsewhere) ---
extern uint32_t GFX_BL_VALUE; 
extern uint32_t GFX_BL_TIME; 
extern int ROTATION; 

// --- Function Prototypes ---
void setup_display();
void loop_display();

// --- Hardware Objects (externally accessible if needed) ---
extern Arduino_RGB_Display gfx;
extern TAMC_GT911 ts;

#endif // DISPLAY_H
