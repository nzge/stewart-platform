#include "pid.h"

PID::PID() {
  _Kp = 0;
  _Ki = 0;
  _Kd = 0;
  _setpoint = 0;
  _output = 0;
  _min = 0;
  _max = 0;
  _error = 0;
  _input = 0;
  _prev_error = 0;
  _integral = 0;
  _derivative = 0;
}

void PID::init() {
  _integral = 0;
  _prev_error = 0;
}

void PID::setSetpoint(float setpoint) {
  _setpoint = setpoint;
}

void PID::setKp(float Kp) {
  _Kp = Kp;
}

void PID::setKi(float Ki) {
  _Ki = Ki;
}

void PID::setKd(float Kd) {
  _Kd = Kd;
}

void PID::setOutputLimits(float min, float max) {
  _min = min;
  _max = max;
}

void PID::setOutput(float output) {
  _output = output;
}

float PID::compute(float input) {
  _input = input;
  _error = _setpoint - _input;
  _integral += _error;
  _derivative = _error - _prev_error;
  _output = _Kp * _error + _Ki * _integral + _Kd * _derivative;
  _output = constrain(_output, _min, _max);
  _prev_error = _error;
  return _output;
}

float PID::getOutput() {
  return _output;
}

float PID::getError() {
  return _error;
}

float PID::getSetpoint() {
  return _setpoint;
}

float PID::getInput() {
  return _input;
}

float PID::getKp() {
  return _Kp;
}

