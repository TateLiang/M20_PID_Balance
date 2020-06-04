# M20_PID_Balance
### Balancing a ball on a platform using Proportional-Integral-Derivative

M20 Physics IA source code

> "The inaccuracies arise when we attempt to determine the power and duration to assign the motor so that it moves a certain distance. In a perfect universe, we could simply use the fact that speed is distance per unit time to find the needed values: given a desired distance d and a desired speed s (such as the max speed of the motor), we can easily find the time of rotation. This is known as “dead-reckoning”. However, in the real world, there are many variables that may effect the speed, such as bumps on the ground, voltage delivered to the motors or the slipping of the wheels.

> One method may be to use feedback control, where a sensor is used to detect the distance travelled, and inform the program of the “error” of the robot. The “error” is simply the difference between the desired location of the robot and the current location of the robot. This kind of “bang-bang” control uses the error to determine the direction of the motor; A large positive error means full speed forward, and a large negative error means full speed backward. Error values near zero means the robot will stop. While this method may eventually lead to the correct location, it is quite easy to overshoot the goal when going full speed, resulting in constant oscillation about the goal."
