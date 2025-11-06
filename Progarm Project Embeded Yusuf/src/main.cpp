#include "submain.h"

unsigned long lastRead = 0;

void setup() {
    setupModules();
}

void loop() {
#if USE_PZEM
    if (millis() - lastRead > 3000) {
        lastRead = millis();
        readPZEMData();
    }
#endif
}
