#include "WPILib.h"
#include "Hatch.h"

Hatch::Hatch( int talon_id):
	hatchMotor( talon_id )
{}

void Hatch::Set( float speed ) {

    hatchMotor.Set( speed );

}
