#include <Arduino.h>
#include <Wire.h>

#include "Adafruit_PWMServoDriver.h"
#include "constants.h"
#include "fns.h"
#include "servos.h"

Servos StewartServos;  // Use Wire (I2C0) on Teensy 4.0

void setup() {
  Serial.begin(9600);

  // Start Wire1 (I2C on pins 17/SDA1 and 16/SCL1)
  Wire.begin();
  Wire.setClock(100000);  // Set I2C frequency to 100kHz

  StewartServos.init();  // Initialize the PCA9685
  Serial.println("Enter an angle (0-180) to set the servo on channel 0:");
}

void loop() {
  static int angle = -1;  // Initialize angle to -1

  // Check if there is data available from the Serial Monitor
  if (Serial.available() > 0) {
    // Read the input from Serial Monitor
    String input = Serial.readStringUntil('\n');  // Read input until newline character

    // Convert the input to an integer (angle)
    int newAngle = input.toInt();

    // Validate the input (must be between 0 and 180)
    if (newAngle >= 0 && newAngle <= 180) {
      angle = newAngle;  // Update the angle

      // Set the angle for both servos (channel 0 and 1)
      StewartServos.setServoAngle(0, angle);  // Set servo on channel 0 to the new angle
      StewartServos.setServoAngle(1, angle);  // Set servo on channel 1 to the same angle

      // Output to serial to confirm the change
      Serial.print("Both servos set to angle: ");
      Serial.println(angle);
    } 
    else {
      // If the input is invalid, display an error message
      Serial.println("Invalid input! Please enter an angle between 0 and 180.");
    }
  }

  delay(100);  // Small delay to prevent overloading the serial buffer
}


