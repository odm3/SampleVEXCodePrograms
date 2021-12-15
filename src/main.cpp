/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 2, 3, 4, 5   
// Arm                  motor_group   8, 13           
// Intake               motor         10              
// MogoLift             motor         11              
// pneumatics1          digital_out   A               
// pneumatics2          digital_out   B               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  int LeftSpeed; 
  int RightSpeed;
  int VerticalSpeed; 
  int HorizontalSpeed;
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

   // Tank Drive - Independent Control of Left and Right Side of Drivetrain
   // Arcade Drive - Forwards/Backwards Control, and Turn Control
     // Single Joystick Arcade, Split Joystick Arcade 

   // Tank Drive
   //Data types
   // int - Integers (+/- whole numbers)
   // float/double (+/- decimal numbers)
   // bool (true/false values)
   
  // LeftSpeed = Controller1.Axis3.value();
  // RightSpeed = Controller1.Axis2.value();

  // LeftDriveSmart.spin(fwd, LeftSpeed, pct);
  // RightDriveSmart.spin(fwd, RightSpeed, pct);

  // Single Joystick Arcade
  VerticalSpeed = Controller1.Axis2.value();
  HorizontalSpeed = Controller1.Axis4.value();

  LeftDriveSmart.spin(fwd, ( VerticalSpeed + HorizontalSpeed), pct);
  RightDriveSmart.spin(fwd, ( VerticalSpeed - HorizontalSpeed), pct);


  if(Controller1.ButtonL1.pressing()){
    Arm.spin(fwd, 80, pct);
  } else if (Controller1.ButtonL2.pressing()) {
    Arm.spin(reverse, 80, pct);
  } else {
    Arm.stop(hold);
  }

  if(Controller1.ButtonR1.pressing()){
    Intake.spin(fwd, 100, pct);
  } else if (Controller1.ButtonR2.pressing()) {
    Intake.spin(reverse, 100, pct);
  } else {
    Intake.stop();
  }

  if(Controller1.ButtonUp.pressing()){
    MogoLift.spin(fwd, 100, pct);
  } else if (Controller1.ButtonDown.pressing()) {
    MogoLift.spin(reverse, 100, pct);
  } else {
    MogoLift.stop(hold);
  }

  if(Controller1.ButtonX.pressing()) {
    pneumatics1.set(true); // Turns pneumatics on
  } else if(Controller1.ButtonB.pressing()) {
    pneumatics1.set(false);
  }

  if(Controller1.ButtonY.pressing()) {
    pneumatics2.set(true);
  } else if(Controller1.ButtonA.pressing()) {
    pneumatics2.set(false);
  }


    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}


/**             
            [cylinder]
                |
            [solenoid]->[solenoid driver]->[V5 Brain Digital Port]
              |
  [Reservoir1]
  |
  |
  [Reservoir2]
            |
            | 
            On/Off Valve

*/
