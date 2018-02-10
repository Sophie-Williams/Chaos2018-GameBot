#include "WPILib.h"
#include "LimitedForklift.h"

LimitedForklift::LimitedForklift( int talon_id, int topLS_port, int bottomLS_port ):
	forkliftMotor( talon_id ),
	topLS( topLS_port ),
	bottomLS( bottomLS_port )
{
}

void LimitedForklift::Set( float speed ) {

	// Check the limit switches first
	/*if( topLS.Get() ) {

		// If the top limit switch is tripped, only go down.
		if( speed < 0 ) {
			forkliftMotor.Set( speed );
		} else {
			forkliftMotor.Set( 0 );
		}

	} else if( bottomLS.Get() ) {

		// If the bottom limit switch is tripped, only go up.
		if( speed > 0 ) {
			forkliftMotor.Set( speed );
		} else {
			forkliftMotor.Set( 0 );
		}

	} else {*/

		// Otherwise, go whatever speed is given.
		forkliftMotor.Set( speed );

	//}

}
