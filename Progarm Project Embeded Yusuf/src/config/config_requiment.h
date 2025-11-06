#pragma once
#include <stdint.h>
#include <Arduino.h>

// ==========================================================
// Pilih salah satu PROJECT_STUDI dengan cara uncomment
// ==========================================================
#define PROJECT_Yusuf_UNO_PZEM_RELAY   // Arduino UNO: PZEM + Relay
//#define PROJECT_Yusuf_ESP_PZEM_RELAY_LED   // ESP32: PZEM + Relay + LED
// ==========================================================

#if defined(ARDUINO_AVR_UNO)
  #define USE_SOFTWARE_SERIAL 1
#else
  #define USE_SOFTWARE_SERIAL 0
#endif


// ==========================================================
// Automatic Configuration Mapping
// ==========================================================
#if defined(PROJECT_Yusuf_UNO_PZEM_RELAY)        // UNO: PZEM + Relay
  #define TARGET_UNO
  #define USE_PZEM        1
  #define USE_RELAY       1
  #define USE_LED         0
  #define USE_WIFI        0
  #define USE_SERIAL      1
  #define SERIAL_BAUD     9600

  // Pin konfigurasi UNO
  #define PZEM_RX_PIN     4
  #define PZEM_TX_PIN     3
  #define RELAY_PIN       2


#elif defined(PROJECT_Yusuf_ESP_PZEM_RELAY_LED)      // ESP32: PZEM + Relay + LED
  #define TARGET_ESP32
  #define USE_PZEM        1
  #define USE_RELAY       1
  #define USE_LED         1
  #define USE_WIFI        1
  #define USE_SERIAL      0
  #define SERIAL_BAUD     115200

  // Pin konfigurasi ESP32
  #define PZEM_RX_PIN     16
  #define PZEM_TX_PIN     17
  #define RELAY_PIN       34
  #define LED_PIN         33

  #define WIFI_SSID       "admin"
  #define WIFI_PASS       "12345"

#else
  #error "Pilih salah satu PROJECT_STUDI* di config_requiment.h"
#endif


// ==========================================================
// Debug Macro
// ==========================================================
#if USE_SERIAL
  #define SERIAL_PRINT(x)    Serial.print(x)
  #define SERIAL_PRINTLN(x)  Serial.println(x)
#else
  #define SERIAL_PRINT(x)
  #define SERIAL_PRINTLN(x)
#endif
