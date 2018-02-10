#include <Shooter.h>
#include <cstdint>
#include "WPILib.h"

Shooter::Shooter( int talon_id, int talon_id2, int servo_id ):
	shooterLeft( talon_id ),
	shooterRight( talon_id2 ),
	shooterServo( servo_id ),
	shooting(true)
{
}

void Shooter::Teleop() {
	// Set shooter speed
	//SetSpeed(0.42);

	// Set servo according to state
	if (shooting) {
		shooterServo.SetAngle(20);
	} else {
		shooterServo.SetAngle(175);
	}
}

void Shooter::SetSpeed( float speed) {
	shooterLeft.Set( -speed );
	shooterRight.Set( speed );
}

void Shooter::SetState(bool newState) {
	shooting = newState;
}

bool Shooter::GetState() {
	return shooting;
}
