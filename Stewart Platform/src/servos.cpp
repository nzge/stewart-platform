#include "servos.h"

Servos::Servos() {
  pca9685 = Adafruit_PWMServoDriver();
  servo_count = NUM_SERVOS;
}

void Servos::setup() {
  // Initialize the PCA9685
  pca9685.begin();
  pca9685.setOscillatorFrequency(27000000);
  pca9685.setPWMFreq(50);  // This is the maximum PWM frequency
}

void Servos::setServoAngle(uint8_t channel, uint16_t angle) {
  // Convert the angle to a pulse width
  int pulse = map(angle, 0, 180, SERVO_MIN, SERVO_MAX);
  // Set the PWM signal on the specified channel
  pca9685.setPWM(channel, 0, pulse);
}

void Servos::setServoAngles(angles[]) {
  for (uint8_t i = 0; i < servo_num; i++) {
    setServoAngle(i, angles[i]);
  }
}