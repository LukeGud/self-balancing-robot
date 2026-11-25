#include <Arduino.h>
#include "test_motor.h"

const int enPin    = 4;   
const int stepR    = 17;  
const int dirR     = 16;
const int stepL    = 19;  
const int dirL     = 18;

const int stepsPerRev = 1600;
const int stepDelayUs = 600;

void setupMotorTest() {
  pinMode(enPin, OUTPUT);
  pinMode(stepR, OUTPUT);
  pinMode(dirR, OUTPUT);
  pinMode(stepL, OUTPUT);
  pinMode(dirL, OUTPUT);
  digitalWrite(enPin, LOW);
}

void spin(int stepPin, int dirPin, bool forward, int steps) {
  digitalWrite(dirPin, forward ? HIGH : LOW);
  for (int i = 0; i < steps; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepDelayUs);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepDelayUs);
  }
}

void loopMotorTest() {
  spin(stepR, dirR, true,  stepsPerRev);
  delay(500);
  spin(stepR, dirR, false, stepsPerRev);
  delay(1000);

  spin(stepL, dirL, true,  stepsPerRev);
  delay(500);
  spin(stepL, dirL, false, stepsPerRev);
  delay(1000);
}