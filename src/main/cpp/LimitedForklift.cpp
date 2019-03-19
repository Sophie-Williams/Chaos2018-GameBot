#include "WPILib.h"
#include "LimitedForklift.h"

LimitedForklift::LimitedForklift( int talon_id, int topLS_port, int bottomLS_port ):
	forkliftMotor( talon_id ),
	liftEncoder(3, 4, false, Encoder::EncodingType::k4X),
	topLS( topLS_port ),
	bottomLS( bottomLS_port )
{
	liftEncoder.SetMaxPeriod(.1);
	liftEncoder.SetMinRate(10);
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
	return (liftEncoder.Get());
}

void LimitedForklift::GoUpLevel(){
	if(liftEncoder.Get() < 95){
		forkliftMotor.Set( 0.25 );
	} else if(95 < liftEncoder.Get() && liftEncoder.Get() < 105){
		forkliftMotor.Set( 0 );
	} else if(105 < liftEncoder.Get() && liftEncoder.Get() < 195){
		forkliftMotor.Set( 0.25 );
	} else if(190 < liftEncoder.Get() && liftEncoder.Get() < 210){
		forkliftMotor.Set( 0 );
	} else if(205 < liftEncoder.Get() && liftEncoder.Get() < 295){
		forkliftMotor.Set( 0.25 );
	} else if(295 < liftEncoder.Get() && liftEncoder.Get() < 305){
		forkliftMotor.Set( 0 );
	} else{
		forkliftMotor.Set(-.25);
	}

}

void LimitedForklift::GoDownLevel(){
	if(liftEncoder.Get() < 95){
		forkliftMotor.Set( 0.25 );
	} else if(95 < liftEncoder.Get() && liftEncoder.Get() < 105){
		forkliftMotor.Set( 0 );
	} else if(105 < liftEncoder.Get() && liftEncoder.Get() < 195){
		forkliftMotor.Set( -0.25 );
	} else if(190 < liftEncoder.Get() && liftEncoder.Get() < 210){
		forkliftMotor.Set( 0 );
	} else if(205 < liftEncoder.Get() && liftEncoder.Get() < 295){
		forkliftMotor.Set( -0.25 );
	} else if(295 < liftEncoder.Get() && liftEncoder.Get() < 305){
		forkliftMotor.Set( 0 );
	} else{
		forkliftMotor.Set(-.25);
	}

}

