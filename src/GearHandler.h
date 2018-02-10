#ifndef SRC_GEARHANDLER_H_
#define SRC_GEARHANDLER_H_

#include "WPILib.h"
#include "ctre/Phoenix.h"

class GearHandler
{
  private:
	WPI_TalonSRX gearHandlerMotor;

  public:
	GearHandler( int talon_id );

	void Set( float speed );
};

#endif /* SRC_GEARHANDLER_H_ */
