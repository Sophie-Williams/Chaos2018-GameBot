#include "WPILib.h"
#include "Align.h"
#include "Robot.h"

Align::Align( int LeftLineSensor, int RightLineSensor ):
    LeftLine( LeftLineSensor ),
    RightLine( RightLineSensor )
{}

double Align::AutoAlign(){
    if(LeftLine.Get() && RightLine.Get()){
        return 0;
    } else if(LeftLine.Get() && !RightLine.Get()){
        return(-0.2);
    } else if(!LeftLine.Get() && RightLine.Get()){
        return(0.2);
    } else{
        return(99999);
    }
}