#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

#include <cstdint>
#include "WPILib.h"
#include <AHRS.h>
#include "ctre/Phoenix.h"
#include "Climber.h"
#include "PowerDistributionPanel.h"
#include "Roller.h"
#include "Camera.h"
#include "LimitedForklift.h"

// Main Robot Class
class Robot: public IterativeRobot
{
  private:
	// Actual Motor Controllers
	WPI_TalonSRX frontRight;
	WPI_TalonSRX frontLeft;
	WPI_TalonSRX rearLeft;
	WPI_TalonSRX rearRight;

	// Fake Motor Controllers
	// TODO: Check if WPILib is fixed yet.
	PWMTalonSRX PWMfr;
	PWMTalonSRX PWMfl;
	PWMTalonSRX PWMrl;
	PWMTalonSRX PWMrr;

	// Controllers
	XboxController driver;
	XboxController copilot;

	// Pseudo-subsystem
	Climber climber;
	Roller roller;
	Camera camera;
	LimitedForklift forklift;

	// Assorted In's and Out's
    AHRS *m_pAHRS;
	PowerDistributionPanel pdu;
	BuiltInAccelerometer accelerometer;
	MecanumDrive robotDrive;

	// SmartDashboard Stuff
	frc::SendableChooser<int> autoChooser;
	frc::SendableChooser<int> positionChooser;

	// Flag variables
	bool climbing;
	bool rolling;
	bool handling;
  public:
	// Constructor Method
	Robot();

	// For NetworkTables, mostly
	void RobotInit();

	// Various Iterators
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	
	// Various Helper Functions
	void UpdateMotors();
	void Forward( float Speed, float Time );
	void Backward( float Speed, float Time );
	void Turn( float absSpeed, float targetAngle );
	void Turn2( float Speed, float Time );
	void Strafe( float Speed, float Time );
	int AutoSwitch();
};

#endif /* SRC_ROBOT_H_ */
