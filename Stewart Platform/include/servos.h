#ifndef SERVOS_H
#define SERVOS_H

#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_PWMServoDriver.h"
#include "constants.h"

class Servos {
public:
  void Servos();
  void setup();
  void setServoAngles(uint16_t angles[servo_count]);
  void setServoAngle(uint8_t channel, uint16_t angle);
private:
  Adafruit_PWMServoDriver pca9685;
  int servo_count;  
}

#endif