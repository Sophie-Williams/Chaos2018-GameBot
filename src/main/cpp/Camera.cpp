#include <Camera.h>
#include <cstdint>
#include "WPILib.h"

Camera::Camera( int servo_id ):
cameraServo( servo_id ),
looking(false)
{
}
	void Camera::Teleop() {
// Set servo according to state
	if (looking) {
		cameraServo.SetAngle(20);

	}else {
			cameraServo.SetAngle(90);
		}
}
		void Camera::SetState(bool newState) {
			looking = newState;
		}


	bool Camera::GetState() {
		return looking;
	}
