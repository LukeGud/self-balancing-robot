#include <Arduino.h>
#include <Wire.h>
#include "test_mpu.h"

const int MPU_ADDR = 0x68;

void setupMpuTest() {
  Serial.begin(115200);
  Wire.begin(21, 22);

  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.println("MPU-6050 gestartet");
}

void loopMpuTest() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom((uint8_t)MPU_ADDR, (size_t)6, true);

  int16_t acX = Wire.read() << 8 | Wire.read();
  int16_t acY = Wire.read() << 8 | Wire.read();
  int16_t acZ = Wire.read() << 8 | Wire.read();

  Serial.print("Neigung X: "); Serial.print(acX);
  Serial.print(" | Y: "); Serial.print(acY);
  Serial.print(" | Z: "); Serial.println(acZ);
  delay(200);
}