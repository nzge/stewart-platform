#include <Arduino.h>
#include <Wire.h>

#include "Adafruit_PWMServoDriver.h"
#include "constants.h"

Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver();

int angleToPulse(int angle) {
  float pulse_min = (SERVO_MIN/PWM_PERIOD)*4096;
  float pulse_max = (SERVO_MAX/PWM_PERIOD)*4096;
  return map(angle, 0, 180, pulse_min, pulse_max);
}

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel PWM test!");

  pca9685.begin();
  pca9685.setOscillatorFrequency(27000000);
  pca9685.setPWMFreq(PWM_FREQ);  // This is the maximum PWM frequency

  // if you want to really speed stuff up, you can go into 'fast 400khz I2C' mode
  // some i2c devices dont like this so much so if you're sharing the bus, watch
  // out for this!
  Wire.setClock(400000);
}

void loop() {

  for (uint16_t angle = 0; angle <= 180; angle += 10) {
    pca9685.setPWM(0, 0, angleToPulse(angle));  // Set servo on channel 0
    delay(200);
  }

  delay(1000);

  for (uint16_t angle = 180; angle >= 0; angle -= 10) {
    int pulse = map(SERVO_MIN, SERVO_MAX, 0, 180, angle);
    pca9685.setPWM(0, 0, angleToPulse(angle));  // Move back to 0°
    delay(200);
  }

}

