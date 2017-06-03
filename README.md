PID Steering and Speed Control
==============================

Project 4 of Term 2 of the Udacity Self-Driving Car Engineer Nanodegree Program

---

About This Project
------------------

The assignment for this project was to control a simulated car driving around a simulated track
using PID controllers. Because Ackerman steering is so non-linear, a PID controller is not an ideal
method to control steering on a car, but it works well enough for the purposes of this project.

Design
------

My approach to the project was to use two PID controllers. One controller regulates the speed of the
car, which has a constant setpoint of 40 MPH. The simulator provides speed feedback on each update,
and the speed error is simply calculated by subtracting the current speed from the speed setpoint.
The output of this controller is fed into the throttle/brake control of the simulated car. The
second controller is used to steer the car. It takes in the cross-track error, which is provided
by the simulator on each update. From the cross-track error, this PID controller outputs a steering
angle for the simulated car.

For this project, I created a generic PID controller class. The proportional, integral, and
derivative error gains are set in the constructor of the `PID` class. The `PID` class has only
two other methods, `Update()` and `Reset()`. `Update()` is called each time a new error value is
available from the simulator. It updates the derivative and integral terms, then calculates and
returns the output for the current time step. The `Reset()` method resets the integral gain to 0 so
that it does not wind up during manual takeover, which would cause erratic behavior when the car
resumes autonomous mode.

Tuning
------

For this project, I tuned the PID controller manually. For the speed controller, the gains were
relatively easy to tune, and precise speed tracking was not very important. For the steering
controller, I began by increasing the proportional gain until the steering became unstable--the car
swerved uncontrollably back and forth, then increased the derivative gain. I alternately increased
these gains until the steering was stable, but aggressive enough to complete the tightest turns on
the track. I tested the stability of my controller by perturbing it--manually driving to the edge of
the track and resuming autonomous mode. The controller was able to recover without driving off the
road. For the steering controller, I did not use any integral gain because I felt that it made the
steering less stable. I did use a very small integral gain on the speed control, because I found
that it reduced the speed error. My final PID gains are shown below:

### Speed Controller Gains

kP    | kI    | kD
----- | ----- | -----
1.000 | 0.001 | 0.500

### Steering Controller Gains

kP    | kI    | kD
----- | ----- | -----
0.120 | 0.000 | 1.000

Results
-------

The steering controller is still somewhat under-damped, which causes the car to swerve some, but the
car can safely navigate the full track at 40 miles per hour indefinitely. I think that the steering
control is inherently limited by the nonlinearity of the steering model, and by the fact that
cross-track error does not tell you much information about what you want to drive. In a steep turn,
for example, the cross-track error tells you nothing about the curvature of the turn. The steering
controller must be very aggressive to turn the car sharply enough without driving off the road. On
a straightaway, the same aggressive controller is undesirable. You can see my car negotiate the
simulator track here:

[![Youtube Video](https://img.youtube.com/vi/VdZj_HlWw_U/0.jpg)](https://youtu.be/VdZj_HlWw_U)


Building and Running
--------------------

### Dependencies

* cmake >= 3.5
* make >= 4.1
* gcc/g++ >= 5.4
* [uWebSockets](https://github.com/uWebSockets/uWebSockets) == 0.13
* Udacity Term 2 Simulator. You can download these from the [project intro page](https://github.com/udacity/CarND-PID-Control-Project/releases) in the classroom.

### Basic Build/Run Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 
5. Run the simulator as well and start the Project 4 simulator to see it drive around the track.

