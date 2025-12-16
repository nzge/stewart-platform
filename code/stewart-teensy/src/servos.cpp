#include "servos.h"

Servos::Servos() {
  pca9685 = Adafruit_PWMServoDriver();
  servo_count = NUM_SERVOS;
}

// Initialize the PCA9685
void Servos::init() {
  pca9685.begin();
  pca9685.setOscillatorFrequency(25000000);  // Set to 25 MHz (default)
  pca9685.setPWMFreq(PWM_FREQ);  // Set PWM frequency for servos (50Hz)
  delay(10);
}

// Set the PWM signal on the specified channel
void Servos::setServoAngle(uint8_t channel, uint16_t angle) {
  // Ensure angle is in valid range
  if (angle < MIN_SERVO_ANGLE) angle = MIN_SERVO_ANGLE;
  if (angle > MAX_SERVO_ANGLE) angle = MAX_SERVO_ANGLE;
  pca9685.setPWM(channel, 0, angleToPWM(angle));
}

void Servos::setServoAngles(uint16_t angles[]) {
  for (uint8_t i = 0; i < servo_count; i++) {
    setServoAngle(i, angles[i]);
  }
}