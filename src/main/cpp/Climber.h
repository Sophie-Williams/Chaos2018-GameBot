#ifndef SRC_CLIMBER_H_
#define SRC_CLIMBER_H_

#include "ctre/Phoenix.h"
#include "WPILib.h"

class Climber
{
  private:
	WPI_TalonSRX climberMotor;

	// Limit Switches
		DigitalInput topLS;



  public:

	Climber( int talon_id, int topLS_port );



	void Set( float speed );
};

#endif /* SRC_CLIMBER_H_ */
