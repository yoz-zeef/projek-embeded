#include "module_relay.h"

void initRelay(int pin) {
#if USE_RELAY
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
  SERIAL_PRINTLN("[Relay] Initialized on pin " + String(pin));
#endif
}

void setRelay(bool state) {
#if USE_RELAY
  digitalWrite(RELAY_PIN, state ? HIGH : LOW);
  SERIAL_PRINTLN(String("[Relay] State: ") + (state ? "ON" : "OFF"));
#endif
}
