#ifndef SRC_ULTRASONIC_H_
#define SRC_ULTRASONIC_H_

#include "WPILib.h"

using namespace frc;

class DistanceSensor {

private:
	AnalogInput mb1013 = AnalogInput(0);
    
    double VOLTS_TO_DIST = 40.34; //161.26

public:
    //Constructor
    void distanceSensor();

	// Member Methods
	double GetVoltage();
    double GetDistance();

};

#endif /* SRC_ULTRASONIC_H_ */