#include "vex.h"

void moveArm(double distance, int speed) {
  Arm.spinFor(distance, rotationUnits::deg, speed, velocityUnits::pct);
}

void moveMogoLift(double distance, int speed) {
  MogoLift.spinFor(distance, rotationUnits::deg, speed, velocityUnits::pct);
}

void moveIntake(int intakeTime, int speed) {
  Intake.spinFor(intakeTime, timeUnits::msec, speed, velocityUnits::pct);
}

void movePneumatic1() {
  pneumatic1Toggle = !pneumatic1Toggle;
  pneumatics1.set(pneumatic1Toggle);
}

void movePneumatic2() {
  pneumatic2Toggle = !pneumatic2Toggle;
  pneumatics1.set(pneumatic2Toggle);
}