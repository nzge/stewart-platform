#ifndef FNS_H 
#define FNS_H

#include <Arduino.h>
#include "constants.h"

inline int angleToPWM(int angle) {
  if (angle < 0) angle = 0;
  if (angle > 180) angle = 180;

  // Perform floating-point calculation for pulse_min and pulse_max
  float pulse_min = ((float)SERVO_MIN / PWM_PERIOD) * 4096;
  float pulse_max = ((float)SERVO_MAX / PWM_PERIOD) * 4096;
  
  // Now ensure that map function works with the calculated pulse_min and pulse_max
  int PWM = map(angle, 0, 180, (int)pulse_min, (int)pulse_max);
  return PWM;
}

#endif