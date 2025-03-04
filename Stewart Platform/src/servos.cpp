#include "servos.h"

Servos::Servos() {
  pca9685 = Adafruit_PWMServoDriver();
  servo_count = NUM_SERVOS;
}

// Initialize the PCA9685
void Servos::setup() {
  pca9685.begin();
  pca9685.setOscillatorFrequency(27000000);
  pca9685.setPWMFreq(50);  // This is the maximum PWM frequency
}

// Set the PWM signal on the specified channel
void Servos::setServoAngle(uint8_t channel, uint16_t angle) {
  pca9685.setPWM(channel, 0, angleToPulse(angle));
}

void Servos::setServoAngles(uint16_t angles[]) {
  for (uint8_t i = 0; i < servo_count; i++) {
    setServoAngle(i, angles[i]);
  }
}

int angleToPulse(int angle) {
  float pulse_min = (SERVO_MIN/PWM_PERIOD)*4096;
  float pulse_max = (SERVO_MAX/PWM_PERIOD)*4096;
  return map(angle, 0, 180, pulse_min, pulse_max);
}