#include "module_serial.h"

void initSerial(int baud) {
#if USE_SERIAL
  Serial.begin(baud);
  delay(500);
  SERIAL_PRINTLN("[Serial] Started at " + String(baud) + " baud");
#endif
}
