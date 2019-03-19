#include "WPILib.h"
#include <cstdint>
#include "Hatch.h"
#include <iostream>

Hatch::Hatch( int talon_id):
	hatch( talon_id )
{
    timer.Start();
}

void Hatch::teleopPeriodic(){
    if(deployFlag && timer.Get() < .5){
        hatch.Set(0.4);
    } else if(retractFlag && timer.Get() < .5){
        hatch.Set(-0.4);
    } else if(retractFlag){
        hatch.Set(-.1);
    } else{
        hatch.Set(0);
    }
    std::cout << timer.Get() << "\n";
}

void Hatch::deploy(){
    if(!deployFlag){
        timer.Reset();
        retractFlag = false;
        deployFlag = true;
    }
}

void Hatch::retract(){
    timer.Reset();
    deployFlag = false;
    retractFlag = true;
}

void Hatch::Set( float speed ) {

    hatch.Set( speed );

}
