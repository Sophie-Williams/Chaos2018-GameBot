#include <Robot.h>
#include "WPILib.h"
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

void Robot::AutonomousInit() {
	robotDrive.SetSafetyEnabled(false);

	// Set autonomous mode and position to defaults
	int autoMode = -1;
	int startingPosition = -1;

	// Get the values from the respective SendableChooser objects
	autoMode = autoChooser.GetSelected();
	startingPosition = positionChooser.GetSelected();

	// Get game data
	std::string gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
}

void Robot::AutonomousPeriodic() {
	Wait(0.005);
}
