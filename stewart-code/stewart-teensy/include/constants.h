#ifndef CONSTANTS_H
#define CONSTANTS_H

// Constants for the PCA9685 PWM driver and servo control
#define PCA9685_ADDR 0x40  // Default I2C address of PCA9685
#define MODE1 0x00         // PCA9685 Mode 1 register
#define PRESCALE 0xFE      // Prescale register for PWM frequency

//Towerpro MG996R servo
#define PWM_FREQ 50         // PWM frequency in Hz (50Hz for servos)
#define PWM_PERIOD 20000     // PWM period in us (20ms for 50Hz)
#define SERVO_MIN 500    //500 us Minimum PWM pulse (~0 degrees)
#define SERVO_MAX 2000    //2000 us Maximum PWM pulse (~180 degrees) //2500 us is actual Maximum PWM pulse (~250 degrees)
#define NUM_SERVOS 6
#define MIN_SERVO_ANGLE 0
#define MAX_SERVO_ANGLE 180
#define ACTION_DELAY 50

//PID constants
#define KP 1
#define KI 0
#define KD 0



#endif 
