#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_PWMServoDriver.h"
#include "constants.h"
#include "fns.h"

Adafruit_PWMServoDriver pca9685;  // Use Wire (I2C0) on Teensy 4.0

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel PWM test!");

  // Start Wire1 (I2C on pins 17/SDA1 and 16/SCL1)
  Wire.begin();
  Wire.setClock(100000);  // Set I2C frequency to 100kHz

  // I2C device scanning (using Wire1)
  Serial.println("Scanning for I2C devices...");
  for (uint8_t addr = 1; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) {
      Serial.print("Found I2C device at 0x");
      Serial.println(addr, HEX);
    }
  }

  int pulse = map(50, 0, 180, 2, 4000);
  // Print the result of the mapping for debugging
  Serial.print("Mapped pulse: ");
  Serial.println(pulse);

  // Initialize PCA9685
  pca9685.begin();
  // Use default oscillator frequency (25 MHz)
  pca9685.setOscillatorFrequency(25000000);  // Set to 25 MHz (default)
  pca9685.setPWMFreq(PWM_FREQ);  // Set PWM frequency for servos (50Hz)
}


void loop() {
  Serial.println("Loop running...");  // Check if loop is starting
  Serial.println("Rotating 180 degrees...");
  for (uint16_t angle = 0; angle <= 180; angle += 5) {
    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.print(" -> PWM: ");
    Serial.println(angleToPWM(angle));
    pca9685.setPWM(0, 0, angleToPWM(angle));  // Set servo on channel 0
    delay(100);  // Give servo time to move
  }

  Serial.println("Rotating opposite direction...");
  delay(1000);  // Pause before reversing

  for (uint16_t angle = 180; angle >= 0; angle -= 5) {
    pca9685.setPWM(0, 0, angleToPWM(angle));  // Move back to 0°
    delay(200);  // Give servo time to move
  }

  delay(1000);  // Pause before restarting loop
} 

