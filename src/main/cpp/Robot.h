#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_


#include <cstdint>
#include "WPILib.h"
#include <AHRS.h>
#include "ctre/Phoenix.h"
#include "rev/CANSparkMax.h"
#include "Climber.h"
#include "PowerDistributionPanel.h"
#include "Roller.h"
#include "Hatch.h"
#include "LimitedForklift.h"
#include "ultrasonic.h"

// Main Robot Class
class Robot: public IterativeRobot
{
  private:
	// Actual Motor Controllers
	static const int frontRightDeviceID = 58, frontLeftDeviceID = 61, rearRightDeviceID =60, rearLeftDeviceID = 59;
	rev::CANSparkMax frontRight{frontRightDeviceID, rev::CANSparkMax::MotorType::kBrushless};
	rev::CANSparkMax frontLeft{frontLeftDeviceID, rev::CANSparkMax::MotorType::kBrushless};
	rev::CANSparkMax rearRight{rearRightDeviceID, rev::CANSparkMax::MotorType::kBrushless};
	rev::CANSparkMax rearLeft{rearLeftDeviceID, rev::CANSparkMax::MotorType::kBrushless};
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
	LimitedForklift forklift;
	Hatch hatch;
	DistanceSensor distanceSensor;

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
