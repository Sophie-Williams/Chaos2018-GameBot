#include <Robot.h>
#include "WPILib.h"
#include <cstdint>
#include <cmath>

void Robot::Turn( float absSpeed, float targetAngle ) {
	float angle;
	float offset;
	float speed;

	// Reset the ahrs to 0 degrees
//	m_pAHRS->Reset();

	// Initialize Timer
	Timer timer;
	timer.Reset();
	timer.Start();

	do {
		// Find the offsets for the rest of the math
//		angle = m_pAHRS->GetAngle();
		angle = 0;
		offset = targetAngle - angle;

		// Calculate output speed
		if(offset < 0)
			speed = absSpeed;
		else
			speed = -absSpeed;

		// Turn
		robotDrive.DriveCartesian(0, 0, speed);
		UpdateMotors();

		// Keep CPU from catching fire and network from exploding in a fireball of packets.
		Wait(0.005);

	} while( abs(offset) > 1 && timer.Get() < 5 ); // Repeat until target is reached or we timeout.

	// Leave everything as we found it
	robotDrive.DriveCartesian(0, 0, 0);
	UpdateMotors();
}

void Robot::Backward( float Speed, float Time ) {
	// Reset the ahrs to 0 degrees
	//m_pAHRS->Reset();

	// Initialize Timer
	Timer timer;
	timer.Reset();
	timer.Start();

	// Move straight, changing angle to adjust for drift
	while ( timer.Get() <= Time ) {
		Wait(0.005);
		robotDrive.DriveCartesian(-Speed, 0, 0 );
		UpdateMotors();
	}

	// Leave everything as we found it
	robotDrive.DriveCartesian(0, 0, 0);
	UpdateMotors();
	timer.Stop();
}

void Robot::Forward( float Speed, float Time ) {
	// Reset the ahrs to 0 degrees
	//m_pAHRS->Reset();

	// Initialize Timer
	Timer timer;
	timer.Reset();
	timer.Start();

	// Move straight, changing angle to adjust for drift
	while ( timer.Get() <= Time ) {
		Wait(0.005);
		robotDrive.DriveCartesian(Speed, 0, 0);
		UpdateMotors();
	}

	// Leave everything as we found it
	robotDrive.DriveCartesian(0, 0, 0);
	UpdateMotors();
	timer.Stop();
}

void Robot::Strafe( float Speed, float Time ) {
	// Reset the ahrs to 0 degrees
	//m_pAHRS->Reset();

	// Initialize Timer
	Timer timer;
	timer.Reset();
	timer.Start();

	// Move straight, changing angle to adjust for drift
	while ( timer.Get() <= Time ) {
		Wait(0.005);
		robotDrive.DriveCartesian(0, Speed, 0 );
		UpdateMotors();
	}
	// Leave everything as we found it
	robotDrive.DriveCartesian(0, 0, 0);
	UpdateMotors();
	timer.Stop();

}

void Robot::Turn2( float Speed, float Time ) {
	// Reset the ahrs to 0 degrees
//	m_pAHRS->Reset();

	// Initialize Timer
	Timer timer;
	timer.Reset();
	timer.Start();

	// Move straight, changing angle to adjust for drift
	while ( timer.Get() <= Time ) {
		Wait(0.005);
		robotDrive.DriveCartesian( 0, 0, Speed );
		UpdateMotors();
	}

	// Leave everything as we found it
	robotDrive.DriveCartesian(0, 0, 0);
	UpdateMotors();
	timer.Stop();
}
