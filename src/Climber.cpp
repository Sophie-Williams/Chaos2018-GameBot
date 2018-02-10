#include <cstdint>
#include "WPILib.h"
#include "Climber.h"

Climber::Climber( int talon_id ):
	climberMotor( talon_id )
{
}

void Climber::Set( float speed ) {
	climberMotor.Set( speed );
}
