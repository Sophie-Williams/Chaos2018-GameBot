#include <Agitator.h>
#include <cstdint>
#include "WPILib.h"

Agitator::Agitator( int talon_id,  int servo_id ):
	agitator( talon_id ),
	agitatorServo( servo_id ),
	agitating(true)
{
}

void Agitator::Teleop() {
	// Set shooter speed
	agitator.Set(1);

	// Set servo according to state

		agitatorServo.SetAngle(180);

}



