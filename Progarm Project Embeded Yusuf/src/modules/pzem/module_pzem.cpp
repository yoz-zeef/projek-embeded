#include "module_pzem.h"

#if USE_SOFTWARE_SERIAL
  SoftwareSerial pzemSerial(PZEM_RX_PIN, PZEM_TX_PIN);
  PZEM004Tv30 pzem(pzemSerial);
#else
  PZEM004Tv30 pzem(Serial2, PZEM_RX_PIN, PZEM_TX_PIN);
#endif

void initPZEM() {
#if USE_PZEM
  SERIAL_PRINTLN("[PZEM] Initialized with RX:" + String(PZEM_RX_PIN) + " TX:" + String(PZEM_TX_PIN));
#endif
}

void readPZEMData() {
#if USE_PZEM
  float voltage = pzem.voltage();
  float current = pzem.current();
  float power   = pzem.power();
  float energy  = pzem.energy();

  SERIAL_PRINT("[PZEM] V:"); SERIAL_PRINT(voltage);
  SERIAL_PRINT("V  I:"); SERIAL_PRINT(current);
  SERIAL_PRINT("A  P:"); SERIAL_PRINT(power);
  SERIAL_PRINT("W  E:"); SERIAL_PRINTLN(energy);
#endif
}
