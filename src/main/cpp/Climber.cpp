#include <cstdint>
#include "WPILib.h"
#include "Climber.h"

Climber::Climber( int talon_id, int topLS_port, int servo1_id, int servo2_id ):
	climberMotor( talon_id ),
	topLS( topLS_port),
	plateServo1(servo1_id),
	plateServo2(servo2_id)
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

void Climber::releasePlates( double servo1Angle,double servo2Angle) {
	plateServo1.SetAngle(servo1Angle);
	plateServo2.Set(servo2Angle);
}


