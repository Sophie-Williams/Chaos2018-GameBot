#include <Robot.h>
#include <cstdint>
#include "WPILib.h"
#include <iostream>
#include <cmath>
#include "Climber.h"
#include "Roller.h"
#include "Hatch.h"
#include "TimedRobot.h"
#include "ultrasonic.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"


double deadband(double input, float deadband = 0.2) {

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

	auto inst = nt::NetworkTableInstance::GetDefault();
	auto table = inst.GetTable("datatable");
	auto table2 = inst.GetTable("ultrasonic");

	double ballAngle = 0;
	double targetAngle = 0;

	float Direction = 0;

	float sped = 0;
	float tim = 0;

	nt::NetworkTableEntry xEntry = table->GetEntry("X");
	nt::NetworkTableEntry yEntry = table->GetEntry("Y");

	ballAngle = xEntry.GetDouble(0);
	targetAngle = yEntry.GetDouble(0);

	nt::NetworkTableEntry xEntry2 = table2->GetEntry("X");
	nt::NetworkTableEntry yEntry2 = table2->GetEntry("y");

	xEntry2.SetDouble(forklift.GetEncoder());

	std::cout << "Encoder position: " << forklift.GetEncoder() << "\n";
	//yEntry2.SetDouble(distanceSensor.GetDistance());
	

	

	

	// Drive with deadband
	robotDrive.DriveCartesian(
		0.5 * deadband(driver.GetY(GenericHID::kLeftHand)), // Forward movement
		0.75 * deadband(driver.GetX(GenericHID::kLeftHand)), // Sideways movement
		0.5 * deadband(driver.GetX(GenericHID::kRightHand))  // Rotational movement

	);

	// Auto Align
	if (driver.GetAButton() == true){
		
		ballAngle = xEntry.GetDouble(0);

		if (abs(ballAngle) < 1){
			while (true){
				if (driver.GetAButtonReleased()){
					break;
				}
			}
		}

		if (ballAngle > .5){
			sped = 0.2;
		} else if (ballAngle < -.5){
			sped = -0.2;
		} else{
			sped = 0;
		}

		if ((ballAngle < 0.75) and (ballAngle > -0.75)){
			tim = 0.01;
		} else{
			tim = 0.05;
		}
		Turn2(sped, tim);
		//robotDrive.DriveCartesian(0, 0, (ballAngle * 0.0125), 0);
		//std::cout << sped << "\n";
		//std::cout << tim << "\n";
			
		
	} 
	if (driver.GetBButton()){
		robotDrive.DriveCartesian(0, 0, (targetAngle * 0.02), 0);		
	}

	// Climbing Control
	if(driver.GetYButton()){

	
		//release climb plates
		climber.releasePlates(0, 180);

	} else{
		climber.releasePlates(30, 150);
	}

	climber.Set(
		deadband(copilot.GetY(GenericHID::kRightHand),0.1)
	);

	//Forklift Control
	forklift.Set(
		deadband(-(copilot.GetY(GenericHID::kLeftHand)), 0.1)
	);

	if(copilot.GetBumper(GenericHID::kLeftHand)){
		forklift.GoDownLevel();
	} else if(copilot.GetBumper(GenericHID::kRightHand)){
		forklift.GoUpLevel();
	}

	//Hatch Control
	/*
	if(copilot.GetXButton()){
		hatch.Set(-0.4);
	} else if (copilot.GetYButton()){
		hatch.Set(0.4);
	} else {
		hatch.Set(-0.1);
	} */

	/*if(copilot.GetXButtonPressed()){
		Timer timer;
		timer.Reset();
		timer.Start();

		while(timer.Get() < .7){
			hatch.Set(-0.4);
		}

		hatch.Set(-.05);
	} else if (copilot.GetYButtonPressed()){
		Timer timer;
		timer.Reset();
		timer.Start();

		while(timer.Get() < .5){
			hatch.Set(0.4);
		}

		hatch.Set(0);
	}*/

	if(copilot.GetYButton()){
		hatch.deploy();
	} else if(copilot.GetXButton()){
		hatch.retract();
	}
	hatch.teleopPeriodic();

	// Roller Control
	if (copilot.GetAButton()){
		roller.Set(0.4);
	} else if (copilot.GetBButton()){
		roller.Set(-0.4);
	} else {
		roller.Set(0.2);
	}


	UpdateMotors();

	Wait(0.005);

}

