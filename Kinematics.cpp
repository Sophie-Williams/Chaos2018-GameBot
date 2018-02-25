#include <Gyro.h>
#include <BuiltInAccelerometer.h>
#include <Timer.h>
#include "WPILib.h"
#include "Field.h"

/* This contains the kinematic expressions needed to determine the robot's motion
The accelerometer's x data will determine the forward motion, y would be used when strafing, and
 the gyro angle will be used to determine the heading. */
 
 
 float p_x;
 float p_y;
 float p_z;
 float Angle // in degrees;
 float Sample_Time; // in seconds
 float a_x; // in g
 float a_y; // in g
 float a_z; // in g
 float v_x; // in inches per second
 float v_xi; // initial x velocity in inches per second
 float v_y; // in inches per second
 float v_yi; // initial y velocity in inches per second
 float v_z; // in in per second
 float v_zi; // initial z velocity in inches per second
 float p_xi; // in inches
 float p_yi; // in inches
 float p_zi; // in inches
 float wheel_diameter; // in inches
 char[3] gameData;
 int OurSwitch[4,2];
 int OurScale[4,2];
 
 const int m2in=386; // convert g to in per second squared
 
 // Grab sensor data
 
 a_x=BuiltInAccelerometer.GetX() * m2in;
 a_y=BuiltInAccelerometer.GetY() * m2in;
 a_z=BuiltInAccelerometer.GetZ() * m2in;
 Angle=Gyro.GetAngle();
 Sample_Time= Timer.Get();
 wheel_diameter=4;
 
 
 // Robot height determination
 // The robot's initial base height is 4 inches. This code is used during climbing.
 
 v_zi=0;
 p_zi=wheel_diameter;
 
 while (p_z <14) {
 p_z=p_zi + (.5 *BuiltInAccelerometer.GetZ()* m2in *t^2) + (v_zi*t); // current height
 p_zi=p_z; // new initial height
 v_z=v_zi + BuiltInAccelerometer.GetZ()*t; // current velocity
 v_zi=v_z; // new initial velocity
 }
 
 // End of robot height determination
 

 // Determining out alliances scale and switch in Autonomous
 
 	std::string gameData;
		gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
  
  // Switch or Scale
  
  			if (Scale==1 AND gameData[1] == 'L')
  			{
  			  OurScale = LSP;
			  switch (StartingPosition)
				  {
				  	case 1
				  	/* 1. Go forward.
				  	   2. Stop at scale midpoint.
				  	   3. Rotate 90 degrees clockwise.
				  	   4. Deliver cube. */
				  	case 2
				  	/* 1. Move forward 5 inches in front of exchange zone.
				  	   2. Strafe left until 15 inches in front of scale.
				  	   3. Go forward.
				  	   4. Stop at scale midpoint.
				  	   5. Rotate 90 degrees clockwise.
				  	   6. Deliver cube. */
				  	case 3
				  	/* 1. Move forward 5 inches in front of exchange zone.
				  	   1. Strafe left until 15 inches in front of scale.
				  	   2. Go forward.
				  	   3. Stop at scale midpoint.
				  	   4. Rotate 90 degrees clockwise.
				  	   5. Deliver cube. */
				  }
			  }  
			else if (Scale==1 AND gameData[1] == 'R')
			  {
		  		OurScale = RSP;
				  switch (StartingPosition)
					  {
					  	case 1
					  	/* 1. Move forward 5 inches in front of exchange zone.
					  	   2. Strafe right until 15 inches in front of scale.
					  	   3. Go forward.
					  	   4. Stop at switch midpoint.
					  	   5. Rotate 90 degrees counterclockwise.
					  	   6. Deliver cube. */
					  	case 2
					  	/* 1. Strafe right until 15 inches in front of scale.
					  	   2. Go forward.
					  	   3. Stop at switch midpoint.
					  	   4. Rotate 90 degrees counterclockwise.
					  	   5. Deliver cube. */
					  	case 3
					  	/* 1. Go forward.
					  	   2. Stop at switch midpoint.
					  	   3. Rotate 90 degrees counterclockwise.
					  	   4. Deliver cube. */
					  }
	  			 }
  			else if (Scale==0 AND gameData[1] == 'L')
  			{
			 OurSwitch = LSwP;
			 switch (StartingPosition)
				  {
				  	case 1
				  	/* 1. Go forward.
				  	   2. Stop at switch midpoint.
				  	   3. Rotate 90 degrees clockwise.
				  	   4. Deliver cube. */
				  	   
				  	case 2
				  	/* 1. Go forward 5 inches in front of exchange zone.
				  	   2. Strafe left until 15 inches in front of switch.
				  	   3. Go forward.
				  	   4. Stop at switch midpoint.
				  	   5. Rotate 90 degrees clockwise.
				  	   6. Deliver cube. */
				  	case 3
				  	/* 1. Go forward 5 inches in front of exchange zone.
				  	   2. Strafe left until 15 inches in front of switch.
				  	   3. Go forward.
				  	   4. Stop at switch midpoint.
				  	   5. Rotate 90 degrees clockwise.
				  	   6. Deliver cube. */
				}
			  }  
			 else if (Scale==0 AND gameData[1] == 'R')
			  {
			OurSwitch = RSwP;
			switch (StartingPosition)
				  {
				  	case 1
				  	/* 1. Go forward 5 inches in front of exchange zone.
				  	   1. Strafe right until 15 inches past switch.
				  	   2. Go forward.
				  	   3. Stop at switch midpoint.
				  	   4. Rotate 90 degrees counterclockwise.
				  	   5. Deliver cube. */
				  	case 2
				  	/* 1. Strafe right 15 inches past switch.
				  	   2. Go forward.
				  	   3. Stop at switch midpoint.
				  	   4. Rotate 90 degrees counterclockwise.
				  	   5. Deliver cube. */
				  	case 3
				  	/* 1. Go forward.
				  	   2. Stop at switch midpoint.
				  	   3. Rotate 90 degrees counterclockwise.
				  	   4. Deliver cube. */
				  }
	  			 }
	  	// Just get across AUTO line
	  	switch (StartingPosition)
				  {
				  	case 1
				  	/* 1. Go forward.
				  	   2. Stop at other side of line */
				  	case 2
				  	/* 1. Strafe right until 15 inches past switch.
				  	   2. Go forward.
				  	   3. Stop at at other side of line.*/
				  	case 3
				  	/* 1. Go forward.
				  	   2. Stop at at other side of line. */
				  }