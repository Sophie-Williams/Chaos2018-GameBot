#include <Robot.h>
#include <cstdint>
#include "WPILib.h"
#include <iostream>
#include <cmath>
#include <iostream>
#include "Climber.h"
#include "Shooter.h"
#include "Roller.h"
#include "Camera.h"

double deadband(double input) {

	float deadband = 0.2;

	if (fabs(input) <= deadband) {
		return 0;
	} else {
		return input;
	}

}

void Robot::TeleopInit() {
	robotDrive.SetSafetyEnabled(false);	// Necessary for proper motor functioning during Teleop
}

void Robot::TeleopPeriodic() {

	// Drive with deadband
	robotDrive.MecanumDrive_Cartesian(
		-0.5 * deadband(driver.GetY(GenericHID::kLeftHand)), // Forward movement
		 0.5 * deadband(driver.GetX(GenericHID::kLeftHand)), // Sideways movement
		-0.5 * deadband(driver.GetX(GenericHID::kRightHand))  // Rotational movement
	);

	// Climbing Control
	climber.Set(copilot.GetY(GenericHID::kRightHand));

	//Forklift Control
	forklift.Set(copilot.GetY(GenericHID::kLeftHand));

	// Roller Control
	if (copilot.GetAButton()){
		roller.Set(1);
	} else if (copilot.GetBButton()){
		roller.Set(-1);
	} else {
		roller.Set(0);
	}

	// Shooter Control
	if (copilot.GetAButton()) {
		shooter.SetState(false);
	} else if (copilot.GetBButton()) {
		shooter.SetState(true);
	}

	// Update Shooter
	shooter.Teleop();

	//Update Agitator
	agitator.Teleop();

	// Camera Control
		if (copilot.GetStartButton()) {
			camera.SetState(false);
		} else if (copilot.GetBackButton()) {
			camera.SetState(true);
		}

		// Update Camera
		camera.Teleop();

		// Gear Handler Control
	if (copilot.GetBumper(GenericHID::kRightHand)) {
		gearHandler.Set(0.25);
	} else if (copilot.GetBumper(GenericHID::kLeftHand)) {
		gearHandler.Set(-0.25);
	} else {
		gearHandler.Set(0);
	}

	UpdateMotors();

	Wait(0.005);

}

