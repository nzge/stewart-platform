#include <Arduino.h>
#include <Wire.h>

#include "fns.h"
#include "constants.h"

#include "servos.h"
#include "pid.h"

Servos StewartServos;  // Use Wire (I2C0) on Teensy 4.0
uint16_t servoAngles[NUM_SERVOS];  // Array of servo angles, with size based on NUM_SERVOS

void setup() {
  Serial.begin(9600);
  // Start Wire1 (I2C on pins 17/SDA1 and 16/SCL1)
  Wire.begin();
  Wire.setClock(100000);  // Set I2C frequency to 100kHz
  StewartServos.init();  // Initialize the PCA9685
}

void loop() {
  for (int angle = 0; angle < 180; angle+=5) {
    for (int i = 0; i < NUM_SERVOS; i++) {
      servoAngles[i] = angle;
    }
    StewartServos.setServoAngles(servoAngles);
    delay(ACTION_DELAY);  
  }

  delay(2000);

  for (int angle = 180; angle > 0; angle-=5) {
    for (int i = 0; i < NUM_SERVOS; i++) {
      servoAngles[i] = angle;
    }
    StewartServos.setServoAngles(servoAngles);
    delay(ACTION_DELAY);  
  }
}
