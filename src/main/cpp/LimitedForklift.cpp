#include "WPILib.h"
#include "LimitedForklift.h"

LimitedForklift::LimitedForklift( int talon_id, int topLS_port, int bottomLS_port ):
	forkliftMotor( talon_id ),
	topLS( topLS_port ),
	bottomLS( bottomLS_port )
{
	liftEncoder = new Encoder(0, 1, false, Encoder::EncodingType::k4X);
	liftEncoder->SetMaxPeriod(.1);
	liftEncoder->SetMinRate(10);
}

void LimitedForklift::Set( float speed ) {

	// Check the limit switches first
	if( !topLS.Get() ) {

		// If the top limit switch is tripped, only go down.
		if( speed > 0 ) {
			forkliftMotor.Set( speed );
		} else {
			forkliftMotor.Set( 0 );
		}

	} else if( !bottomLS.Get() ) {

		// If the bottom limit switch is tripped, only go up.
		if( speed < 0 ) {
			forkliftMotor.Set( speed );
		} else {
			forkliftMotor.Set( 0.2 );
		}

	} else {

		// Otherwise, go whatever speed is given.
		forkliftMotor.Set( speed );

	}

}

int LimitedForklift::GetEncoder(){
	return (liftEncoder->Get());
}
