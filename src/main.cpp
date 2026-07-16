#include "display.h"
#include "auto_pumps.h"
#include "elegantota.h"
#include "enow.h"
#include "lora.h"

extern void setup_settings();
extern void fill_widgets();

void setup()
{
  Serial.begin(115200);
  delay(500); // Короткая задержка для готовности последовательного порта
  setup_settings();
  setup_display();
  fill_widgets();
  esp_now_setup();
  pump_setup();
  //lora_setup();
}

void loop()
{
  // if (ota_mode)
  // {
    ota_loop();
  //   return;
  // }
  loop_display();
  pump_loop();
  //lora_loop();
}
