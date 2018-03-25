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
			// TODO: Test
			Forward(-.4, 2);
			break;

		// Attempt switch
		case 3:
			switch(startingPosition) {
				case 1:
					if(gameData[0] == 'L') {
						// Start on left, end on left switch
						// TODO: Test
						Forward(-.4, 3.5);
						Turn2(.4, 1);
						Forward(-.3, 1);
						forklift.Set(-.7);
						roller.Set(-.5);
						Wait(1.5);
						roller.Set(0);
						forklift.Set(-.2);

					} else {
						// Start on left, end on right switch
						// TODO: Test
						Forward(-.4, 3);

					}
					break;
				case 2:
					if(gameData[0] == 'L') {
						// Start on center, end on left switch
						// TODO: Test
						/*Forward(-.4, 1);
						Wait(.25);
						Strafe(-0.6, 2.4);
						Wait(.05);
						Turn2(-.3, .25);
						Forward(-.55, 2.3);
						Wait(.1);
						forklift.Set(-.7);
						roller.Set(-1);
						Wait(1.5);
						roller.Set(0);
						forklift.Set(-.2);
						Backward(-.55, .9);
						forklift.Set(.2);
						Wait(1.2);
						forklift.Set(0);
						Turn2(.3, .9);
						roller.Set(1);
						Forward(-.4, 2);
						roller.Set(0);
						Backward(-.5, 1);
						forklift.Set(-.7);
						Wait(1.9);
						forklift.Set(-.2);
						*/
						Forward(-.4, .5);
						Wait(.25);
						Turn2(-.3, .55);
						Forward(-.4, 3);
						Turn2(.3, .3);
						Forward(-.4, 1.5);
						forklift.Set(-.7);
						roller.Set(-1);
						Wait(1.5);
						forklift.Set(-.2);
						roller.Set(0);


					} else {
						// Start on center, end on right switch
						// TODO: Test
						/*Forward(-.4, 1);
						Wait(.25);
						Strafe(0.6, 1.8);
						Wait(.05);
						Turn2(.3, .25);
						Forward(-.55, 2.3);
						Wait(.1);
						forklift.Set(-.7);
						roller.Set(-1);
						Wait(1.5);
						roller.Set(0);
						forklift.Set(-.2);
						Backward(-.55, .9);
						forklift.Set(.2);
						Wait(1.2);
						forklift.Set(0);
						Turn2(-.3, .9);
						roller.Set(1);
						Forward(-.4, 2.2);
						roller.Set(0);
						Backward(-.5, 1);
						forklift.Set(-.7);
						Wait(1.9);
						forklift.Set(-.2);
						*/
						Forward(-.4, .5);
						Wait(.25);
						Turn2(.3, .4);
						Forward(-.4, 3);
						Turn2(-.3, .3);
						Forward(-.4, 1.5);
						forklift.Set(-.7);
						roller.Set(-1);
						Wait(1.5);
						forklift.Set(-.2);
						roller.Set(0);

						}
					break;
				case 3:
					if(gameData[0] == 'L') {
						// Start on right, end on left switch
						// TODO: Test
						Forward(-.4, 3.5);
					} else {
						// Start on right, end on right switch
						// TODO: Test
						Forward(-.4, 3.5);
						Turn2(-.4, 1);
						Forward(-.3, 1);
						forklift.Set(-.7);
						roller.Set(-.5);
						Wait(1.5);
						roller.Set(0);
						forklift.Set(-.2);
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
					if(gameData[0]=='L') {
						// Start on center, end on left switch
						// TODO: Test
						roller.Set(-1);
						forklift.Set(1);
						Wait(2);
						roller.Set(0);
						forklift.Set(0);
						Forward(.5, .5);
						Strafe(-1, 1.5);
						Forward(.2, 1);
						roller.Set(1);
					} else {
						// Start on center, end on right switch
						// TODO: Test
						roller.Set(-1);
						forklift.Set(1);
						Wait(2);
						roller.Set(0);
						forklift.Set(0);
						Forward(.5, .5);
						Strafe(-1, 1.5);
						Forward(.2, 1);
						roller.Set(1);
					}
					break;
				case 3:
					if(gameData[0] == 'L') {
						// Start on right, end on left switch
						// TODO: Test
						Forward(.5, 2);
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

		// Didn't select autonomous mode!
	//	default:
			// TODO: Decide what to do here. Perhaps just forward?
	//		break;
	}
}

void Robot::AutonomousPeriodic() {
	Wait(0.005);
}

