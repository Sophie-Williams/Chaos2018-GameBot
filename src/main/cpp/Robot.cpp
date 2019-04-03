#include <Robot.h>
#include <cstdint>
#include "WPILib.h"
#include "Climber.h"
#include "Config.h"
#include "TimedRobot.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"

Robot::Robot():
	// Actual Motor Controllers
	m_pAHRS(nullptr),
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
	climber(CLIMBER_CANTALON_ID, 7, 4, 5),
	roller(ROLLER_CANTALON_ID),
	forklift(FORKLIFT_CANTALON_ID, 0, 9),
	hatch(HATCH_CANTALON_ID),
	align(6, 8),

	// Assorted In's and Out's
	pdu(0),
	accelerometer(),

	// NOTE: Documentation says (fl, rl, fr, rr), but it is actually (fr, fl, rr, rl)
	robotDrive(PWMfr, PWMfl, PWMrr, PWMrl),

	// SmartDashboard Stuff
	autoChooser(),
	positionChooser(),

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
	frontLeft.Set(PWMfl.Get());
	rearLeft.Set(PWMrl.Get());
	
	frontRight.Set(PWMfr.Get());
	rearRight.Set(PWMrr.Get());
}

void Robot::RobotInit() {
	autoChooser.AddDefault("Default", 0);
	autoChooser.AddObject("Do Nothing", 1);
	autoChooser.AddObject("Go Forward", 2);
	autoChooser.AddObject("Attempt Switch", 3);
	autoChooser.AddObject("Attempt Scale", 4);
	frc::SmartDashboard::PutData("Autonomous", &autoChooser);

	positionChooser.AddDefault("Default", 0);
	positionChooser.AddObject("Left", 1);
	positionChooser.AddObject("Center", 2);
	positionChooser.AddObject("Right", 3);
	frc::SmartDashboard::PutData("Position", &positionChooser);

	auto inst = nt::NetworkTableInstance::GetDefault();
	auto table = inst.GetTable("datatable");

}

START_ROBOT_CLASS(Robot);
