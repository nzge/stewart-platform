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
  static int angle = -1;  // Store the last set angle

  // Check if there is data available from the Serial Monitor
  if (Serial.available() > 0) {
    // Read the input from Serial Monitor
    String input = Serial.readStringUntil('\n');  // Read input until newline character

    // Convert the input to an integer
    int newAngle = input.toInt();

    // Validate the input (must be between 0 and 180)
    if (newAngle >= 0 && newAngle <= 180) {
      angle = newAngle;  // Set the new angle

      // Map the angle to pulse width
      int PWM = angleToPWM(angle);

      // Set the servo to the calculated pulse width
      pca9685.setPWM(0, 0, PWM);  // Assuming channel 0 is the servo

      // Provide feedback to the user
      Serial.print("Moving servo to angle: ");
      Serial.print(angle);
      Serial.print(" -> PWM: ");
      Serial.println(PWM);
    } else {
      // If the input is not valid, print an error message
      Serial.println("Invalid input! Please enter an angle between 0 and 180.");
    }
  }

  // You can add a small delay to avoid overloading the serial buffer
  delay(100);
}


