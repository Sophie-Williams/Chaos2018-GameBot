#include "WPILib.h"
#include <cstdint>
#include "ultrasonic.h"
#include <iostream>
#include "AnalogInput.h"

void DistanceSensor::distanceSensor(){
        mb1013.SetSampleRate(9600);
    };

double DistanceSensor::GetVoltage(){
    return mb1013.GetVoltage();
}

double DistanceSensor::GetDistance(){
    return (mb1013.GetVoltage() * VOLTS_TO_DIST);
}