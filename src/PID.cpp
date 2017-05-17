#include "PID.h"

PID::PID(double kp, double ki, double kd)
    : kp_(kp),
      ki_(ki),
      kd_(kd),
      last_err_(0),
      last_err_valid_(false),
      integral_err_(0) {
}

PID::~PID() {
}

double PID::Update(double error) {
  double derivative_error = 0;
  if (last_err_valid_) {
    derivative_error = error - last_err_;
  }
  last_err_ = error;
  last_err_valid_ = true;
  return -(kp_ * error + ki_ * integral_err_ + kd_ * derivative_error);
}

void PID::Reset() {
  integral_err_ = 0;
  last_err_valid_;
}
