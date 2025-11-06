#pragma once

#include "config/config.h"
#include "modules/serial/module_serial.h"
#include "modules/pzem/module_pzem.h"
#include "modules/relay/module_relay.h"
#include "modules/led/module_led.h"
#include "modules/wifi/module_wifi.h"

void setupModules();

inline void setupModules() {
    initSerial(SERIAL_BAUD);
#if USE_WIFI
    initWiFiConnection();
#endif
#if USE_PZEM
    initPZEM();
#endif
#if USE_RELAY
    initRelay(RELAY_PIN);
#endif
#if USE_LED
    initLED(LED_PIN);
#endif
}

