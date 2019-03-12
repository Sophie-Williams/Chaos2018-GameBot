#ifndef SRC_CLIMBER_H_
#define SRC_CLIMBER_H_

#include "ctre/Phoenix.h"
#include "WPILib.h"
#include "frc/Servo.h"

using namespace frc;

class Climber
{
  private:
	WPI_TalonSRX climberMotor;

	// Limit Switches
		DigitalInput topLS;

	Servo plateServo1;
	Servo plateServo2;




  public:

	Climber( int talon_id, int topLS_port, int servo1_id, int servo2_2);

	void releasePlates(double servo1Angle, double servo2Angle);

	void Set( float speed );
};

#endif /* SRC_CLIMBER_H_ */
