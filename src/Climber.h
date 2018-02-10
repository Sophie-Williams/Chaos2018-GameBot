#ifndef SRC_CLIMBER_H_
#define SRC_CLIMBER_H_

#include "ctre/Phoenix.h"
#include "WPILib.h"

class Climber
{
  private:
	WPI_TalonSRX climberMotor;

  public:
	Climber( int talon_id );

	void Set( float speed );
};

#endif /* SRC_CLIMBER_H_ */
