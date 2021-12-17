#include "vex.h"

void RightSideAWP() {
  Drivetrain.setTurnVelocity(60, pct);
  Drivetrain.turnToRotation(45, degrees);
  Drivetrain.setDriveVelocity(75, pct);
  Drivetrain.driveFor(18, distanceUnits::in);
  movePneumatic1();
  moveArm(500, 75);
  Drivetrain.driveFor(-10, distanceUnits::in);
}

void LeftSideAWP() {

}

void RightSideNeutral() {

}

void LeftSideNeutral() {

}