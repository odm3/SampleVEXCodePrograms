using namespace vex;

extern brain Brain;

// VEXcode devices
extern smartdrive Drivetrain;
extern motor_group RightDriveSmart;
extern motor_group LeftDriveSmart;
extern motor_group Arm;
extern motor Intake;
extern motor MogoLift;
extern digital_out pneumatics1;
extern digital_out pneumatics2;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );