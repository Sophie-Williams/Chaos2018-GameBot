#ifndef SRC_LIMITEDFORKLIFT_H_
#define SRC_LIMITEDFORKLIFT_H_

#include "ctre/Phoenix.h"
#include "WPILib.h"
#include "frc/Encoder.h"
using namespace frc;

class LimitedForklift {

private:
	WPI_TalonSRX forkliftMotor;

	Encoder *liftEncoder;

	// Limit Switches
	DigitalInput topLS;
	DigitalInput bottomLS;

public:
	// Constructors
	LimitedForklift( int talon_id, int bottomLS_port, int topLS_port );

	//liftEncoder(int arg1, int arg2, bool arg3, Encoder::EncodingType::k4X);

	// Member Methods
	void Set( float speed );

	int GetEncoder();

};

#endif /* SRC_LIMITEDFORKLIFT_H_ */
