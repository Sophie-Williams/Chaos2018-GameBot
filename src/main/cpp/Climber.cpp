#include <cstdint>
#include "WPILib.h"
#include "Climber.h"

Climber::Climber( int talon_id, int topLS_port ):
	climberMotor( talon_id ),
	topLS( topLS_port)
{
}

void Climber::Set( float speed ) {
	if( !topLS.Get() ) {

			// If the top limit switch is tripped, only go down.
			if( speed < 0 ) {
				climberMotor.Set( speed );
			} else {
				climberMotor.Set( 0 );
			}

	} else {

		// Otherwise, go whatever speed is given.
		climberMotor.Set( speed );

	}

}

