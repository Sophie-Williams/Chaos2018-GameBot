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

bool autoUp=false;
bool autoDown=false;
bool autoDone=false;
int currentEncoderPos;
int currentArrayPos;
int tolerance;
int levels [8];
int getUpArrayPos(int curpos) {

	if (curpos<0){
		curpos=0;
	}

	for (int indx=0; indx < 3; indx++) {


//		if ( (levels[indx] <= curpos) && (levels[indx+1] >= curpos)){
		if ( (levels[indx] >= curpos)){
			if (curpos+tolerance >= levels[indx]){
				return indx+1;
			} else
			{return indx;
			}
		}			
	}
	return 3;
}
int getDownArrayPos(int curpos){

	if (curpos>9999999){
		curpos=9999999;
	} 
	std::cout << "IN GET DOWN POS: cur pos is " << curpos << "\n";
	for (int indx=3; indx > -1; indx--){


std::cout << "IN FOR LOOP indx is " <<levels[indx] << "\n" ;
std::cout << "IN FOR LOOP indx -1 is " <<levels[indx-1] << "\n" ;

		if ((levels[indx] <= curpos)){

			if ((curpos-tolerance) <= (levels[indx])){\

				return indx-1;
			} else
			{
				return indx;
			}		
		}
	}
	std::cout << "RETURNING ZERO\n";
	return 0;
}


double deadband(double input, float deadband = 0.2) {

	if (fabs(input) <= deadband) {
		return 0;
	} else {
		return input;
	}

}



void Robot::TeleopInit() {
	robotDrive.SetSafetyEnabled(false);	// Necessary for proper motor functioning during Teleop
levels [0] = 0;
levels [1] = 153;
levels [2] = 679;
levels [3] = 1139;
levels [4] = 8000;
levels [5] = 30000;
levels [6] = 40000;
levels [7] = 50000;
tolerance=50;
currentArrayPos=0;


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

	xEntry2.SetDouble(distanceSensor.GetVoltage());
	yEntry2.SetDouble(distanceSensor.GetDistance());

//	std::cout << "Encoder position: " << forklift.GetEncoder() << "\n";
//	std::cout << "Target position: " << levels[currentArrayPos] << "\n";
	

	if(driver.GetAButton()){
		robotDrive.DriveCartesian(
			1 * deadband(driver.GetY(GenericHID::kLeftHand)), // Forward movement
			1 * deadband(driver.GetX(GenericHID::kLeftHand)), // Sideways movement
			1 * deadband(driver.GetX(GenericHID::kRightHand))  // Rotational movement
		);
	} else{
		robotDrive.DriveCartesian(
			0.5 * deadband(driver.GetY(GenericHID::kLeftHand)), // Forward movement
			0.75 * deadband(driver.GetX(GenericHID::kLeftHand)), // Sideways movement
			0.5 * deadband(driver.GetX(GenericHID::kRightHand))  // Rotational movement
		);
	}

	// Auto Align
	/*if (driver.GetXButton() == true){
		
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
	}*/

	// Climbing Control
	if(driver.GetYButton()){

	
		//release climb plates
		climber.releasePlates(0, 180);

	} else{
		climber.releasePlates(30, 150);
	}

	climber.Set(
		deadband(copilot.GetY(GenericHID::kRightHand),0.2)
	);

	//Forklift Control
	/*forklift.Set(
		deadband(-(copilot.GetY(GenericHID::kLeftHand)), 0.2)
	);*/

	/*if(copilot.GetBumper(GenericHID::kLeftHand)){
		forklift.GoDownLevel();
	} else if(copilot.GetBumper(GenericHID::kRightHand)){
		forklift.GoUpLevel();
	}*/

	//NEW CODE HERE

//Forklift Control
if (deadband(copilot.GetY(GenericHID::kLeftHand), 0.1) != 0){
	
    autoUp=false;
	autoDown=false;
	autoDone=false;
	forklift.Set(-(copilot.GetY(GenericHID::kLeftHand))
	);
} else if (!autoUp && !autoDown && !autoDone)
	{
		forklift.Set(0);
	}



if (copilot.GetBumperPressed(GenericHID::kRightHand)){
	if (!autoUp){
		autoDown=false;
		autoUp=true;
		autoDone=false;
		currentEncoderPos=forklift.GetEncoder();
        currentArrayPos=getUpArrayPos(currentEncoderPos);
		std::cout << "NEW UP COMMAND" << "\n";
			std::cout << "Encoder position: " << forklift.GetEncoder() << "\n";
	std::cout << "Target position: " << levels[currentArrayPos] << "\n";

	}else{
		if (currentArrayPos < 3){
				std::cout << "INCREASE UP COMMAND" << "\n";
					std::cout << "Encoder position: " << forklift.GetEncoder() << "\n";
	std::cout << "Target position: " << levels[currentArrayPos] << "\n";

			currentArrayPos = currentArrayPos+1;
		}
	}
	if (currentEncoderPos < levels[currentArrayPos]){
		forklift.Set(deadband((.8), 0.1));
	}
	else {
		autoUp=false;
		autoDone=true;
		
	}
}
else if (copilot.GetBumperPressed(GenericHID::kLeftHand)){
	if (!autoDown){
		autoUp=false;
		autoDown=true;
		autoDone=false;
		currentEncoderPos=forklift.GetEncoder();
        currentArrayPos=getDownArrayPos(currentEncoderPos);
		std::cout << "NEW DOWN COMMAND" << "\n";
			std::cout << "Encoder position: " << forklift.GetEncoder() << "\n";
	std::cout << "Target position: " << levels[currentArrayPos] << "\n";
	} else{
		if (currentArrayPos > 0){
			currentArrayPos = currentArrayPos-1;
		}
	}
	if (currentEncoderPos > levels[currentArrayPos]){
		forklift.Set(deadband(-(.15), 0.1));
	}
	else {
		autoDown=false;
		autoDone=true;
		
	}
}
else if (autoUp){
		currentEncoderPos=forklift.GetEncoder();
		if (currentEncoderPos < levels[currentArrayPos]){
			forklift.Set(deadband((.8), 0.1));
		}
		else{
			autoUp=false;
			autoDone=true;
			forklift.Set( 0.2 );
		}
}
else if (autoDown){
		currentEncoderPos=forklift.GetEncoder();
		if (currentEncoderPos > levels[currentArrayPos]){
			forklift.Set(deadband(-(.1), 0.1));
		}
		else{
			autoDown=false;
			autoDone=true;
			if (levels[currentArrayPos]>tolerance){
				forklift.Set( 0.2 );
			}
			else {
				forklift.Set( 0 );
			}
		}
}/* else{
	if(currentEncoderPos <20){forklift.Set( 0 );}
	else{forklift.Set( 0.2 );}
	//forklift.Set(
	//deadband(-(copilot.GetY(GenericHID::kLeftHand)), 0.2)
	//);}
}*/






	//END NEW CODE HERE

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

	//Wait(0.005);

}

