#include <Arduino.h>
#include <Wire.h>

#include "Adafruit_PWMServoDriver.h"
#include "constants.h"
#include "fns.h"
#include "servos.h"

Servos StewartServos;  // Use Wire (I2C0) on Teensy 4.0

// Array to hold the angles for all servos
uint16_t servoAngles[NUM_SERVOS];  // Array of servo angles, with size based on NUM_SERVOS

void setup() {
  Serial.begin(9600);

  // Start Wire1 (I2C on pins 17/SDA1 and 16/SCL1)
  Wire.begin();
  Wire.setClock(100000);  // Set I2C frequency to 100kHz

  StewartServos.init();  // Initialize the PCA9685

  // Initialize all servo angles to 90 (middle position)
  for (int i = 0; i < NUM_SERVOS; i++) {
    servoAngles[i] = 90;  // Default angle for all servos
  }

  Serial.println("Enter a single angle (0-180) to set all servos to that angle.");
}

void loop() {
  static int angle = -1;  // Initialize angle to -1

  // Check if there is data available from the Serial Monitor
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');  // Read input until newline character

    // Convert the input to an integer (angle)
    uint16_t newAngle = input.toInt();

    // Validate the input (must be between 0 and 180)
    if (newAngle >= 0 && newAngle <= 180) {
      // Populate the servoAngles array with the same value (newAngle) for all servos
      for (int i = 0; i < NUM_SERVOS; i++) {
        servoAngles[i] = newAngle;
      }

      // Use the setServoAngles function to update all servos
      StewartServos.setServoAngles(servoAngles);

      Serial.print("All servos set to angle: ");
      Serial.println(newAngle);
    } else {
      // If the input is invalid, display an error message
      Serial.println("Invalid input! Please enter an angle between 0 and 180.");
    }
  }

  delay(100);  // Small delay to prevent overloading the serial buffer
}
