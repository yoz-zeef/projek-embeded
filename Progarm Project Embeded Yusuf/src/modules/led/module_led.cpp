#include "module_led.h"

void initLED(int pin) {
#if USE_LED
  pinMode(pin, OUTPUT);
  SERIAL_PRINTLN("[LED] Initialized on pin " + String(pin));
#endif
}
