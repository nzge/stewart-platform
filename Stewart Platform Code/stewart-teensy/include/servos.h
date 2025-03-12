#ifndef SERVOS_H
#define SERVOS_H

#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_PWMServoDriver.h"
#include "constants.h"
#include "fns.h"

class Servos {
public:
  Servos();
  void init();
  void setServoAngles(uint16_t angles[]);
  void setServoAngle(uint8_t channel, uint16_t angle);
private:
  Adafruit_PWMServoDriver pca9685;
  int servo_count;  
};

#endif