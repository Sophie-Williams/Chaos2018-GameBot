#include <Robot.h>
#include "WPILib.h"
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

void Robot::AutonomousInit() {
	Robot::TeleopInit();
}

void Robot::AutonomousPeriodic() {
	Robot::TeleopPeriodic();
}

