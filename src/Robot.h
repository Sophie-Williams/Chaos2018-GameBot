#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

#include <GearHandler.h>
#include <cstdint>
#include "WPILib.h"
#include "ADXRS450_Gyro.h"
#include "ctre/Phoenix.h"
#include "Climber.h"
#include "PowerDistributionPanel.h"
#include "Shooter.h"
#include "Roller.h"
#include "Camera.h"
#include "Agitator.h"

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
	Shooter shooter;
	Roller roller;
	GearHandler gearHandler;
	Camera camera;
	Agitator agitator;

	// Assorted In's and Out's
	ADXRS450_Gyro gyro;
	PowerDistributionPanel pdu;
	BuiltInAccelerometer accelerometer;
	RobotDrive robotDrive;

	// Flag variables
	bool climbing;
	bool rolling;
	bool handling;

  public:
	// Constructor Method
	Robot();

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
	void Strafe( float Speed, float Time );
	int AutoSwitch();
};

#endif /* SRC_ROBOT_H_ */
