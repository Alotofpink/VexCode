#ifndef ROBOT_CONFIG_H
#define ROBOT_CONFIG_H

#include "vex.h"using namespace vex;

// Brain should be defined by default
brain Brain;

// Robot configuration code
digital_out DigitalOutB(Brain.ThreeWirePort.B);

// wait for rotation sensor to fully initialize
this_thread::sleep_for(30);

// Make random actually random
void initializeRandomSeed() {
    this_thread::sleep_for(100);
    int random = Brain.Battery.voltage(voltageUnits::mV) + Brain.Battery.current(currentUnits::amp) * 100 + Brain.Timer.systemHighResolution();
    srand(random);
}

// Set random seed
initializeRandomSeed();

// Function to control the drivetrain and the piston
void controlDrivetrainAndPiston() {
    bool pistonState = false;  // Keep track of the piston state (True = activated, False = deactivated)

    while (true) {
        // Get the values from the right analog stick
        int forwardBackward = Controller.Axis2.position();
        int turn = Controller.Axis1.position();

        // Set the velocities of the left and right motors based on joystick input
        int leftSpeed = forwardBackward + turn;
        int rightSpeed = forwardBackward - turn;

        LeftDrive.spin(directionType::fwd, leftSpeed, velocityUnits::pct);
        RightDrive.spin(directionType::fwd, rightSpeed, velocityUnits::pct);

        // Check if the B button is pressed to toggle the piston
        if (Controller.ButtonB.pressing()) {
            pistonState = !pistonState;  // Toggle the state
            DigitalOutB.set(pistonState);  // Set the digital output
            this_thread::sleep_for(300);  // Add a small delay to prevent rapid toggling
        }

        // A brief delay to prevent spamming the CPU
        this_thread::sleep_for(20);
    }
}

// Define motors
motor leftDriveMotor1(PORT1, gearSetting::ratio36_1, true);
motor leftDriveMotor2(PORT2, gearSetting::ratio36_1, true);
motor leftDriveMotor3(PORT3, gearSetting::ratio36_1, true);
motor rightDriveMotor1(PORT11, gearSetting::ratio36_1, false);
motor rightDriveMotor2(PORT12, gearSetting::ratio36_1, false);
motor rightDriveMotor3(PORT13, gearSetting::ratio36_1, false);

// Group the left and right motors together
motor_group LeftDrive(leftDriveMotor1, leftDriveMotor2, leftDriveMotor3);
motor_group RightDrive(rightDriveMotor1, rightDriveMotor2, rightDriveMotor3);

// Define the drivetrain with the motors and updated gear ratio
drivetrain Drivetrain(LeftDrive, RightDrive, 319.19, 295, 40, mm, 1);

// Define the controller
controller Controller;

int main() {
    // add a small delay to make sure we don't print in the middle of the REPL header
    this_thread::sleep_for(200);
    // clear the console to make sure we don't have the REPL in the console
    Brain.Screen.clearScreen();

    initializeRandomSeed();
    controlDrivetrainAndPiston();
}
