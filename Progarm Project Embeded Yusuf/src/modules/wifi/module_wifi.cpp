#include "module_wifi.h"
#if USE_WIFI
  #include <WiFi.h>
#endif

void initWiFiConnection() {
#if USE_WIFI && defined(TARGET_ESP32)
  SERIAL_PRINTLN("[WiFi] Connecting to " + String(WIFI_SSID));
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    SERIAL_PRINT(".");
  }
  SERIAL_PRINTLN("\n[WiFi] Connected! IP: " + WiFi.localIP().toString());
#elif defined(TARGET_UNO)
  SERIAL_PRINTLN("[WiFi] Not available on UNO");
#endif
}
