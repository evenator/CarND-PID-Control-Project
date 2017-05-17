#ifndef PID_H
#define PID_H

/**
 * @brief A discrete PID controller (assumes constant timestep)
 */
class PID {
 public:
  /**
   * @brief constructor
   * @param kp Proportional error gain
   * @param ki Integral error gain
   * @param kd Derivative error gain
   */
  PID(double kp, double ki, double kd);

  virtual ~PID();

  /**
   * @brief Update the PID controller with a new measurement and calculate a command
   * @param error The new error measurement
   * @return The new command
   */
  double Update(double error);

  /**
   * @brief Reset the integral sum to 0; reset the derivative
   */
  void Reset();

 private:
  /// Proportional gain
  double kp_;
  /// Integral gain
  double ki_;
  /// Derivative gain
  double kd_;
  /// Previous error measurement
  double last_err_;
  /// Last error not valid until the second measurement
  bool last_err_valid_;
  /// Integral error sum
  double integral_err_;
};

#endif /* PID_H */
