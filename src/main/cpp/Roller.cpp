#include "WPILib.h"
#include <cstdint>
#include "Roller.h"

Roller::Roller( int talon_id ):
	roller( talon_id )
{
}

void Roller::Set( float speed ) {
	roller.Set( -speed );
}
