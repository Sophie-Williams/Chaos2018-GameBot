#include "WPILib.h"
#include <cstdint>
#include "Hatch.h"

Hatch::Hatch( int talon_id):
	hatch( talon_id )
{}

void Hatch::Set( float speed ) {

    hatch.Set( speed );

}
