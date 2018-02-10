#include <GearHandler.h>
#include <cstdint>
#include "WPILib.h"

GearHandler::GearHandler( int talon_id ):
	gearHandlerMotor( talon_id )
{
}

void GearHandler::Set( float speed ) {
	gearHandlerMotor.Set( speed );
}
