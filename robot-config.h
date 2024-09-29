#ifndef ROBOT_CONFIG_H
#define ROBOT_CONFIG_H

#include "api.h"

// Declare motor and controller objects as extern to make them available globally
extern pros::Motor leftDriveMotor1;
extern pros::Motor leftDriveMotor2;
extern pros::Motor leftDriveMotor3;
extern pros::Motor rightDriveMotor1;
extern pros::Motor rightDriveMotor2;
extern pros::Motor rightDriveMotor3;

extern pros::Controller master;

#endif // ROBOT_CONFIG_H
