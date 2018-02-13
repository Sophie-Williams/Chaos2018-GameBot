#include <Robot.h>
#include <cstdint>
#include "WPILib.h"
#include "Climber.h"
#include "Config.h"

Robot::Robot():
	// Actual Motor Controllers
	frontRight(FRONT_RIGHT_CANTALON_ID),
	frontLeft(FRONT_LEFT_CANTALON_ID),
	rearLeft(REAR_LEFT_CANTALON_ID),
	rearRight(REAR_RIGHT_CANTALON_ID),

	// Fake Motor Controllers
	PWMfr(0),
	PWMfl(1),
	PWMrl(2),
	PWMrr(3),
	
	// Controllers
	driver(5),
	copilot(4),

	// Subsystems
	climber(CLIMBER_CANTALON_ID),
	roller(ROLLER_CANTALON_ID),
	camera(5),
	forklift(FORKLIFT_CANTALON_ID, 0, 1),

	// Assorted In's and Out's
	gyro(),
	pdu(0),
	accelerometer(),


	// NOTE: Documentation says (fl, rl, fr, rr), but it is actually (fr, fl, rr, rl)
	robotDrive(PWMfr, PWMfl, PWMrr, PWMrl),

	// Flag variables
	climbing(false),
	rolling(false),
	handling(false)
{
	CameraServer::GetInstance()->StartAutomaticCapture();
	  robotDrive.SetExpiration(0.3);
}

// TODO: Check if WPILib is fixed yet.
void Robot::UpdateMotors() {
	// Set real motor values based off of the fake ones
	frontLeft.Set(-PWMfl.Get());
	rearLeft.Set(PWMrl.Get());
	
	frontRight.Set(-PWMfr.Get());
	rearRight.Set(PWMrr.Get());
}

START_ROBOT_CLASS(Robot);
