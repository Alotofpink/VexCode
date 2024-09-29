#include "robot-config.h"

// Define motors with their port numbers and other parameters
pros::Motor leftDriveMotor1(1, pros::E_MOTOR_GEARSET_36, false);
pros::Motor leftDriveMotor2(2, pros::E_MOTOR_GEARSET_36, false);
pros::Motor leftDriveMotor3(3, pros::E_MOTOR_GEARSET_36, false);
pros::Motor rightDriveMotor1(11, pros::E_MOTOR_GEARSET_36, true);
pros::Motor rightDriveMotor2(12, pros::E_MOTOR_GEARSET_36, true);
pros::Motor rightDriveMotor3(13, pros::E_MOTOR_GEARSET_36, true);

// Initialize the controller
pros::Controller master(pros::E_CONTROLLER_MASTER);
