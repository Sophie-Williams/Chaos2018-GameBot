#ifndef SRC_ALIGN_H_
#define SRC_ALIGN_H_

#include "ctre/Phoenix.h"
#include "WPILib.h"
using namespace frc;

class Align {

private:

	// Limit Switches
	DigitalInput LeftLine;
	DigitalInput RightLine;

public:
	// Constructors
	Align( int LeftLineSenser, int RightLineSensor );

	// Member Methods

    double AutoAlign();

};

#endif /* SRC_ALIGN_H_ */
