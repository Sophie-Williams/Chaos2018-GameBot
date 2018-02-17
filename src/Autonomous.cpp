#include <Robot.h>
#include "WPILib.h"

void Robot::AutonomousInit() {
	// Setup
	robotDrive.SetSafetyEnabled(false);
	Forward(0.4,2);
	Strafe(0.3,2);
}

void Robot::AutonomousPeriodic() {
	Wait(0.005);
}
