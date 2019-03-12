#ifndef SRC_HATCH_H_
#define SRC_HATCH_H_

#include "ctre/Phoenix.h"
#include "WPILib.h"

using namespace frc;

class Hatch {

private:
	WPI_TalonSRX hatch;
	bool deployFlag;
	bool retractFlag;
	Timer timer;

public:
	// Constructors
	Hatch( int talon_id);

	// Member Methods
	void teleopPeriodic();
	void deploy();
	void retract();
	void Set( float speed );

};

#endif /* SRC_HATCH_H_ */