#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ElegantOTA.h>
#include "esp_now.h"
#include <lvgl.h>

const char *ssid = "Pump_controller";
const char *password = "80100000";
static bool is_ota_initialized = false;
bool update = false;
bool ota_mode = false;

WebServer server(80);

unsigned long ota_progress_millis = 0;

void onOTAStart()
{
    Serial.println("OTA update started!");
    // Останавливаем обработку LVGL
    lv_deinit();
}

void onOTAProgress(size_t current, size_t final)
{
    if (millis() - ota_progress_millis > 1000)
    {
        ota_progress_millis = millis();
        Serial.printf("OTA Progress Current: %u bytes, Final: %u bytes\n", current, final);
    }
}

void onOTAEnd(bool success)
{
    if (success)
    {
        Serial.println("OTA update finished successfully!");
    }
    else
    {
        Serial.println("There was an error during OTA update!");
    }
}

void ota_setup(void)
{
    if (is_ota_initialized)
    {
        Serial.println("OTA already initialized.");
        return;
    }

    esp_now_deinit();
    Serial.println("Starting OTA setup...");

    // Пытаемся запустить AP
    if (!WiFi.softAP(ssid, password))
    {
        Serial.println("Failed to start SoftAP!");
        return;
    }

    IPAddress myIP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(myIP);

    server.on("/", []()
              { server.send(200, "text/plain", "Hi! This is Pump Controller OTA."); });

    ElegantOTA.begin(&server);
    ElegantOTA.onStart(onOTAStart);
    ElegantOTA.onProgress(onOTAProgress);
    ElegantOTA.onEnd(onOTAEnd);

    server.begin();
    Serial.println("HTTP server started");
    update = true;
    is_ota_initialized = true;
}

void ota_loop(void)
{
    if (update)
    {
        server.handleClient();
        ElegantOTA.loop();
    }
}
