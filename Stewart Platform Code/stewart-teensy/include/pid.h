#ifndef PID_H
#define PID_H

#include <Arduino.h>

class PID {
  public: 
    PID();
    void init();
    void setSetpoint(float setpoint);
    void setKp(float Kp);
    void setKi(float Ki);
    void setKd(float Kd);
    void setOutputLimits(float min, float max);
    void setOutput(float output);
    float compute(float input);

    float getOutput();
    float getError();
    float getSetpoint();
    float getInput();
    float getKp();
    float getKi();
    float getKd();
  private:
    float _Kp;
    float _Ki;
    float _Kd;
    float _setpoint;
    float _output;
    float _min;
    float _max;
    float _error;
    float _input;
    float _prev_error;
    float _integral;
    float _derivative;
};

#endif
