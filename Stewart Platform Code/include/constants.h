#ifndef CONSTANTS_H
#define CONSTANTS_H

// Constants for the PCA9685 PWM driver and servo control
#define PCA9685_ADDR 0x40  // Default I2C address of PCA9685
#define MODE1 0x00         // PCA9685 Mode 1 register
#define PRESCALE 0xFE      // Prescale register for PWM frequency

//Towerpro MG996R servo
#define PWM_FREQ 50         // PWM frequency in Hz (50Hz for servos)
#define PWM_PERIOD 20     // PWM period in microseconds (20ms for 50Hz)
#define SERVO_MIN 1    //1 ms Minimum PWM pulse (~0 degrees)
#define SERVO_MAX 2    //2 ms Maximum PWM pulse (~180 degrees)
#define NUM_SERVOS 6


#endif 
