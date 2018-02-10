#ifndef SRC_ROLLER_H_
#define SRC_ROLLER_H_

#include "WPILib.h"
#include "ctre/Phoenix.h"

class Roller
{
  private:
	WPI_TalonSRX roller;

  public:
	Roller( int talon_id );

	void Set( float speed );
};

#endif /* SRC_ROLLER_H_ */
