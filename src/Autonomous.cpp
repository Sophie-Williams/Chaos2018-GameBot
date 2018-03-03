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

	// Test that we got anything?
	switch(autoMode) {

		// Do nothing
		case 1:
			// TODO: Implement?
			break;

		// Go forward
		case 2:
			// TODO: Implement
			break;

		// Attempt switch
		case 3:
			switch(startingPosition) {
				case 1:
					if(gameData[0] == 'L') {
						// Start on left, end on left switch
						// TODO: Test
						roller.Set(-1);
						forklift.Set(1);
						Wait(2);
						roller.Set(0);
						forklift.Set(0);
						Forward(.5, 1);
						Turn(.5, 90);
						roller.Set(1);

					} else {
						// Start on left, end on right switch
						// TODO: Implement
					}
					break;
				case 2:
					if(gameData[0] == 'L') {
						// Start on center, end on left switch
						// TODO: Implement
					} else {
						// Start on center, end on right switch
						// TODO: Implement
					}
					break;
				case 3:
					if(gameData[0] == 'L') {
						// Start on right, end on left switch
						// TODO: Implement
					} else {
						// Start on right, end on right switch
						// TODO: Test
						roller.Set(-1);
						forklift.Set(1);
						Wait(2);
						roller.Set(0);
						forklift.Set(0);
						Forward(.5, 1);
						Turn(.5, -90);
						roller.Set(1);
					}
					break;
				default:
					// Didn't select starting position!
					// TODO: Decide what to do here. Perhaps just forward?
					break;
			}
			break;

		// Attempt scale
		case 4:
			switch(startingPosition) {
				case 1:
					if(gameData[0] == 'L') {
						// Start on left, end on left scale
						// TODO: Implement
					} else {
						// Start on left, end on right scale
						// TODO: Implement
					}
					break;
				case 2:
					if(gameData[0] == 'L') {
						// Start on center, end on left scale
						// TODO: Implement
					} else {
						// Start on center, end on right scale
						// TODO: Implement
					}
					break;
				case 3:
					if(gameData[0] == 'L') {
						// Start on right, end on left scale
						// TODO: Implement
					} else {
						// Start on right, end on right scale
						// TODO: Implement
					}
					break;
				default:
					// Didn't select starting position!
					// TODO: Decide what to do here. Perhaps just forward?
					break;
			}
			break;

		// Didn't select autonomous mode!
		default:
			// TODO: Decide what to do here. Perhaps just forward?
			break;
	}
}

void Robot::AutonomousPeriodic() {
	Wait(0.005);
}

