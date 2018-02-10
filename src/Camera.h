#ifndef SRC_CAMERA_H_
#define SRC_CAMERA_H_

#include "WPILib.h"
#include "Servo.h"

class Camera
{
  private:

	Servo cameraServo;

	bool looking;

  public:
	Camera( int servo_id);

	void SetState(bool newState);
	bool GetState();

	void Teleop();
};

#endif /* SRC_CAMERA_H_ */
