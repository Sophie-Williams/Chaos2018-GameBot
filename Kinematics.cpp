#include <Gyro.h>
#include <BuiltInAccelerometer.h>
#include <Timer.h>
#include "WPILib.h"
#include "Field.h"
#include <Robot.h>
#include <cmath>

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
  
 // Grab sensor data
 
 a_x=g2in(BuiltInAccelerometer.GetX());
 a_y=g2in(BuiltInAccelerometer.GetY());
 a_z=g2in(BuiltInAccelerometer.GetZ());
 Angle=Gyro.GetAngle();
 t= Timer.Get();
 wheel_diameter=4;
 
 
 // Robot height determination
 // The robot's initial base height is 4 inches. This code is used during climbing.
 
 v_zi=0;
 p_zi=wheel_diameter;
 
 while (p_z <14) {
 p_z=p_zi + (.5 *g2in(BuiltInAccelerometer.GetZ()) *t^2) + (v_zi*t); // current height
 p_zi=p_z; // new initial height
 v_z=v_zi +  g2in(BuiltInAccelerometer.GetZ())*t; // current velocity
 v_zi=v_z; // new initial velocity
 }
 
 // End of robot height determination
 

 // Determining out alliances scale and switch in Autonomous
 
 	std::string gameData;
		gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
  
  // Switch or Scale
  			Timer SampT
  			SampT.Reset
  			if (Scale==1 AND gameData[1] == 'L')
  			{
  			  OurScale = LSP; // Not needed
			  switch (StartingPosition)
				  {
				  	case 1
				  	/* 1. Go forward.
				  	   2. Stop at scale midpoint.
				  	   3. Rotate 90 degrees clockwise.
				  	   4. Deliver cube.
				  	   5. Back up. */
				  	   // Go forward to midpoint of scale
				  	   
				  	   Robot::Robot.Forward(2,0);
				  	   SampT.Reset;
				  	   SampT.Start;
				  	   v_y=0;
				  	   while (RobotPosition[0][1] < (LSP[0][1]+LSP[1][1])/2)
				  	   		{
				  	   			YPosition();	
				  	   		}
				  	   	//Rotate 90 degrees clockwise
				  	   	Robot::Robot.Forward(0,0);
				  	   	SampT.Stop;
				  	   	Robot.Turn(2,90);
				  	   	//Place pause here if necessary.
				  	   	
				  	   	//Deliver the cube
				  	   	
				  	   	//Place code to release cube here
				  	   	
				  	   	//Back up 12 inches
				  	   	
				  	   	Robot::Robot.Bakward(2,90);
				  	   	v_x=0;
				  	   	SampT.Reset;
				  	   	SampT.Start;
				  	   	while (RobotPosition[0][0] > LSP[0][0]-12)
				  	   		{
				  	   			XPosFor();
				  	   			
				  	   		}
				  	   	Robot::Robot.Backward(0,0); //Stop robot.
				  	   	SampT.Stop;
				  	   break;
				  	case 2
				  	/* 1. Move forward 5 inches in front of exchange zone.
				  	   2. Strafe left until 15 inches in front of scale.
				  	   3. Go forward.
				  	   4. Stop at scale midpoint.
				  	   5. Rotate 90 degrees clockwise.
				  	   6. Deliver cube.
				  	   7. Back up. */
				  	   
				  	   // Move forward 5 inches.
				  	   
				  	   Robot::Robot.Forward(2,0);
				  	   SampT.Reset;
				  	   SampT.Start;
				  	   v_y=0;				  	   
				  	   while (RobotPosition[0][1] < EZ[3][1]+5)
				  	   		{
				  	   			YPosFor();
				  	   		}
				  	   	Robot::Robot.Forward(0,0);
				  	   	SampT.Stop;
				  	   	//Place pause if necessary.
				  	   	//Strafe left.
				  	   	
				  	   	Robot::Robot.Strafe(2,0);
				  	   SampT.Reset;
				  	   SampT.Start;
				  	   v_x=0;
				  	   while (RobotPosition[0][0]> LSP[0][0]-15)
				  	   		{
				  	   			XPosStrafe();
				  	   		}
				  	   	Robot::Robot.Strafe(0,0); //Stop robot.
				  	   	SampT.Stop;
				  	   	//Place pause here if necessary
				  	   // Go forward to midpoint of scale
				  	   
				  	   Robot::Robot.Forward(2,0);
				  	   SampT.Reset;
				  	   SampT.Start;
				  	   v_y=0;
				  	   while (RobotPosition[0][1] < (LSP[0][1]+LSP[1][1])/2)
				  	   		{
				  	   			YPosition();	
				  	   		}
				  	   	//Rotate 90 degrees clockwise
				  	   	Robot::Robot.Forward(0,0);
				  	   	SampT.Stop;
				  	   	Robot.Turn(2,90);
				  	   	//Place pause here if necessary.
				  	   	
				  	   	//Deliver the cube
				  	   	
				  	   	//Place code to release cube here
				  	   	
				  	   	//Back up 12 inches
				  	   	
				  	   	Robot::Robot.Bakward(2,90);
				  	   	v_x=0;
				  	   	SampT.Reset;
				  	   	SampT.Start;
				  	   	while (RobotPosition[0][0] > LSP[0][0]-12)
				  	   		{
				  	   			XPosFor();
				  	   		}
				  	   	Robot::Robot.Backward(0,0); //Stop robot.
				  	   	SampT.Stop;					  	   					  	   
				  	   break;
				  	case 3
				  	/* 1. Move forward 5 inches in front of exchange zone.
				  	   1. Strafe left until 15 inches in front of scale.
				  	   2. Go forward.
				  	   3. Stop at scale midpoint.
				  	   4. Rotate 90 degrees clockwise.
				  	   5. Deliver cube. */
				  	   // Move forward 5 inches.
				  	   
				  	   Robot::Robot.Forward(2,0);
				  	   SampT.Reset;
				  	   SampT.Start;
				  	   v_y=0;				  	   
				  	   while (RobotPosition[0][1] < EZ[3][1]+5)
				  	   		{
				  	   			YPosFor();
				  	   		}
				  	   	Robot::Robot.Forward(0,0);
				  	   	SampT.Stop;
				  	   	//Place pause if necessary.
				  	   	//Strafe left.
				  	   	
				  	   Robot::Robot.Strafe(2,0);
				  	   SampT.Reset;
				  	   SampT.Start;
				  	   v_x=0;
				  	   while (RobotPosition[0][0]> LSP[0][0]-15)
				  	   		{
				  	   			XPosStrafe();
				  	   		}
				  	   	Robot::Robot.Strafe(0,0); //Stop robot.
				  	   	SampT.Stop;
				  	   	//Place pause here if necessary
				  	   // Go forward to midpoint of scale
				  	   
				  	   Robot::Robot.Forward(2,0);
				  	   SampT.Reset;
				  	   SampT.Start;
				  	   v_y=0;
				  	   while (RobotPosition[0][1] < (LSP[0][1]+LSP[1][1])/2)
				  	   		{
				  	   			YPosition();	
				  	   		}
				  	   	//Rotate 90 degrees clockwise
				  	   	Robot::Robot.Forward(0,0);
				  	   	SampT.Stop;
				  	   	Robot.Turn(2,90);
				  	   	//Place pause here if necessary.
				  	   	
				  	   	//Deliver the cube
				  	   	
				  	   	//Place code to release cube here
				  	   	
				  	   	//Back up 12 inches
				  	   	
				  	   	Robot::Robot.Bakward(2,90);
				  	   	v_x=0;
				  	   	SampT.Reset;
				  	   	SampT.Start;
				  	   	while (RobotPosition[0][0] > LSP[0][0]-12)
				  	   		{
				  	   			XPosFor();
				  	   		}
				  	   	Robot::Robot.Backward(0,0); //Stop robot.
				  	   	SampT.Stop;				  	   
				  	   break;
				  }	  
			  }  
			else if (Scale==1 AND gameData[1] == 'R')
			  {
		  		OurScale = RSP;// Not needed.
				  switch (StartingPosition)
					  {
					  	case 1
					  	/* 1. Move forward 5 inches in front of exchange zone.
					  	   2. Strafe right until 15 inches in front of scale.
					  	   3. Go forward.
					  	   4. Stop at scale midpoint.
					  	   5. Rotate 90 degrees counterclockwise.
					  	   6. Deliver cube.
					  	   7. Back up. */
					  	   
						// Move forward 5 inches.
				  	   
				  	   Robot::Robot.Forward(2,0);
				  	   SampT.Reset;
				  	   SampT.Start;
				  	   v_y=0;				  	   
				  	   while (RobotPosition[0][1] < EZ[3][1] +5)
				  	   		{
				  	   			YPosFor();
				  	   		}
				  	   	Robot::Robot.Forward(0,0);
				  	   	SampT.Stop;
				  	   	//Place pause if necessary.
				  	   	//Strafe left.
				  	   	
				  	   Robot::Robot.Strafe(2,0);
				  	   SampT.Reset;
				  	   SampT.Start;
				  	   v_x=0;
				  	   while (RobotPosition[0][0]< RSP[2][0]+15)
				  	   		{
				  	   			XPosStrafe();
				  	   		}
				  	   	Robot::Robot.Strafe(0,0); //Stop robot.
				  	   	SampT.Stop;
				  	   	//Place pause here if necessary
				  	   // Go forward to midpoint of scale
				  	   
				  	   Robot::Robot.Forward(2,0);
				  	   SampT.Reset;
				  	   SampT.Start;
				  	   v_y=0;
				  	   while (RobotPosition[0][1] < (RSP[0][1]+RSP[1][1])/2)
				  	   		{
				  	   			YPosition();	
				  	   		}
				  	   	//Rotate 90 degrees counterclockwise
				  	   	Robot::Robot.Forward(0,0);
				  	   	SampT.Stop;
				  	   	Robot.Turn(2,-90);
				  	   	//Place pause here if necessary.
				  	   	
				  	   	//Deliver the cube
				  	   	
				  	   	//Place code to release cube here
				  	   	
				  	   	//Back up 12 inches
				  	   	
				  	   	Robot::Robot.Bakward(2,-90);
				  	   	v_x=0;
				  	   	SampT.Reset;
				  	   	SampT.Start;
				  	   	while (RobotPosition[0][0] < RSP[2][0]+12)
				  	   		{
				  	   			XPosFor();
				  	   		}
				  	   	Robot::Robot.Backward(0,0); //Stop robot.
				  	   	SampT.Stop;				  	   
				  	   break;
				  }	  
					  	case 2
						  	/* 1. Strafe right until 15 inches in front of scale.
					  	   2. Go forward.
					  	   3. Stop at scale midpoint.
					  	   4. Rotate 90 degrees counterclockwise.
					  	   5. Deliver cube. 
					  	   6. Back up. */
					  	   
					  	   //Strafe right 15 inches in front of scale.
					  	   
					  	   Robot::Strafe(0,0);
					  	   v_x=0;
					  	   SampT.Reset;
					  	   SampT.Start;
					  	   while(RobotPosition[0][0]< RSP[2][0]+15)
					  	   {
					  	   		XPosStrafe();	
					  	   }
					  	   Robot::Forward(0,0);
					  	   SampT.Stop;
					  	   v_y=0;
					  	   SampT.Reset;
					  	   SampT.Start;
					  	   while(RobotPosition[0][1]< (RSP[2][1]+RSP[3][1])/2)
					  	   {
					  	   		YPosFor();
					  	   }
					  	   Robot::Robot.Forward(0,0); //Stop the robot
					  	   SampT.Stop;
					  	   Robot::Robot.Turn();
					  	   
					  	   //Deliver the cube
					  	   
					  	   v_x=0
					  	   SampT.Reset;
					  	   SampT.Start;
					  	   Robot::Robot.Backward();
					  	   while(RobotPosition[0][0]<RSP[2][0]+15)
					  	   {
					  	   		XPosFor();
					  	   }
					  	   Robot::Robot.Forward(0,0);
					  	   SampT.Stop;
					  	   break;
					  	case 3
					  	/* 1. Go forward.
					  	   2. Stop at scale midpoint.
					  	   3. Rotate 90 degrees counterclockwise.
					  	   4. Deliver cube.
					  	   5. Back up. */
					  	   
					  	   Robot::Robot.Forward();
					  	   v_y=0;
					  	   SampT.Reset;
					  	   SampT.Start;
					  	   while(Robot::RobotPosition[0][1]<(RSP[2][1]+RSP[3][1])/2)
					  	   {
					  	   		YPosFor();
					  	   }
					  	   
					  	   Robot::Robot.Forward();
					  	   SampT.Stop;
					  	   Robot::Robot.Turn();
					  	   Robot::Robot.Forward();
					  	   
					  	   //Deliver the cube
					  	   
					  	   //Back up
					  	   v_x=0;
					  	   SampT.Reset;
					  	   SampT.Start;
					  	   while(RobotPosition[0][0]<RSP[2][0]+15)
					  	   {
					  	   		XPosFor();
					  	   }
					  	   SampT.Stop;
					  	   break;
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
				  	   4. Deliver cube.
				  	   5. Back up. */
				  	   
				  	   v_y=0;
				  	   SampT.Reset;
				  	   SampT.Start;
				  	   Robot::Robot.Forward();
				  	   while(RobotPosition[0][1]<(LSwP[0][1]+LSwP[1][1])/2)
				  	   {
				  	   		YPosFor();
				  	   }
				  	   SampT.Stop;
				  	   Robot::Robot.Forward();//Stop robot
				  	   Robot::Robot.Turn;
				  	   //Deliver cube
				  	   
				  	   //Back up
				  	   v_x=0
				  	   SampT.Rest;
				  	   SampT.Start;
				  	   Robot::Robot.Forward;
				  	   while(RobotPosition[0][0]>LSwP[0][0]-12)
				  	   {
				  	   		XPosFor();
				  	   }
				  	   SampT.Stop;
				  	   
				  	   break;
				  	case 2
				  	/* 1. Go forward 5 inches in front of exchange zone.
				  	   2. Strafe left until 15 inches in front of switch.
				  	   3. Go forward.
				  	   4. Stop at switch midpoint.
				  	   5. Rotate 90 degrees clockwise.
				  	   6. Deliver cube.
				  	   7. Back up.  */
				  	   
				  	   v_y=0;
				  	   SampT.Reset;
				  	   SampT.Start;
				  	   Robot::Robot.Forward;
				  	   while(RobotPosition[0][1]< EZ[3][1]+5)
				  	   {
				  	   		YPosFor();
				  	   }
				  	   SampT.Stop;
				  	   
				  	   v_x=0;
				  	   SampT.Reset;
				  	   SampT.Start;
				  	   Robot::Robot.Strafe;
				  	   while(RobotPosition[0][0]>LSwP[0][0]-15)
				  	   {
				  	   		XPosStrafe();
				  	   }
				  	   SampT.Stop;
				  	   v_y=0;
				  	   SampT.Reset;
				  	   SampT.Start;
				  	   Robot::Robot.Forward;
				  	   while(RobotPosition[0][1]<(LSwP[0][1]+LSwP[1][1])/2)
				  	   {
				  	   		YPosFor;	
				  	   }
				  	   SampT.Stop;
				  	   Robot::Robot.Turn;
				  	   //Deliver the cube
				  	   
				  	   //Back up
				  	   v_x=0;
				  	   SampT.Reset;
				  	   SampT.Start;
				  	   Robot::Robot.Forward;
				  	   while(RobotPosition[0][0]> LSwP[0][0]-15)
				  	   {
				  	   		XPosFor;
				  	   }
				  	   SampT.Stop;
				  	   break;
				  	case 3
				  	/* 1. Go forward 5 inches in front of exchange zone.
				  	   2. Strafe left until 15 inches in front of switch.
				  	   3. Go forward.
				  	   4. Stop at switch midpoint.
				  	   5. Rotate 90 degrees clockwise.
				  	   6. Deliver cube.
				  	   7. Back up. */
				  	   
				  	   v_y=0;
				  	   SampT.Reset;
				  	   SampT.Stop;
				  	   Robot::Robot.Forward;
					   while(RobotPosition[0][1]< EZ[3][1]+5)
					   {
					   		YPosFor();
					   }
					   SampT.Stop;
					   
					   v_x=0;
					   SampT.Reset;
					   SampT.Start;
					   Robot::Robot.Strafe;
					   while(RobotPosition[0][0]>LSwP[0][0]-15)
					   {
					   		XPosStrafe();
					   }
					   SampT.Stop;
					   
					   v_y=0;
					   SampT.Reset;
					   SampT.Start;
					   Robot::Robot.Forward;
					   while(RobotPosition[0][1]< (LSwP[0][1]+LSwP[1][1])/2)
					   {
					   		YPosFor();
					   }
					   SampT.Stop;
					   
					   //Deliver the cube
					   
					   //Back up
					   
					   v_x=0;
					   SampT.Reset;
					   SampT.Start;
					   while(RobotPosition[0][0]>LSwP[0][0]-15)
					   {
					   		XPosFor();
					   }
					   Robot::Robot.Forward;
					   SampT.Stop;
				  	   break;
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
				  	   5. Deliver cube. 
				  	   6. Back up. */
				  	   
				  	   v_y=0;
				  	   SampT.Reset;
				  	   SampT.Start;
				  	   Robot:Robot.Forward;
				  	   while(RobotPosition[0][1]< RSwP[1][1]+5)
				  	   {
				  	   		YPosFor:
				  	   }
				  	   SampT.Stop;
				  	   
				  	   v_x=0;
				  	   SampT.Reset;
				  	   SampT.Start;
				  	   Robot::Robot.Strafe;
				  	   while(RobotPosition[0][0]<RSwP[2][0]+15)
				  	   {
				  	   		XPosStrafe;
				  	   }
				  	   SampT.Stop;
				  	   
				  	   v_y=0;
				  	   SampT.Reset;
				  	   SampT.Start;
				  	   Robot::Robot.Forward;
				  	   while(RobotPosition[0][1]<(RSwP[2][1]+RSwP[3][1])/2)
				  	   {
				  	   		YPosFor();
				  	   }
				  	   SampT.Stop;
				  	   
				  	   Robot::Robot.Turn;
				  	   
				  	   //Deliver cube
				  	   
				  	   //Back up
				  	   
				  	   v_x=0;
				  	   SampT.Reset;
				  	   SampT.Start;
				  	   Robot::Robot.Forward;
				  	   while(RobotPosition[0][0]<RSwP[2][0]+15)
				  	   {
				  	   		XPosFor;
				  	   }
				  	   SampT.Stop;
				  	   break;
				  	case 2
				  	/* 1. Strafe right 15 inches past switch.
				  	   2. Go forward.
				  	   3. Stop at switch midpoint.
				  	   4. Rotate 90 degrees counterclockwise.
				  	   5. Deliver cube. 
				  	   6. Back up. */
				  	   
				  	   v_x=0;
				  	   SampT.Reset;
				  	   SampT.Start;
				  	   Robot::Robot.Strafe;
				  	   while(RobotPosition[0][0]<RSwP[2][0]+15)
				  	   {
				  	   		XPosStrafe;
				  	   }
				  	   SampT.Stop;
				  	   
				  	   v_y=0;
				  	   SampT.Reset;
				  	   SampT.Start;
				  	   Robot::Robot.Forward;
				  	   while(RobotPosition[0][1]<(RSwP[2][1]+RSwP[3][1])/2)
				  	   {
				  	   		YPosFor;
				  	   }
				  	   SampT.Stop;
				  	   
				  	   Robot::Robot.Turn;
				  	   
				  	   //Deliver cube
				  	   
				  	   //Back up
				  	   
				  	   v_x=0;
				  	   SampT.Reset;
				  	   SampT.Start;
				  	   Robot::Robot.Forward;
				  	   while(RobotPosition[0][0]<RSwP[2][0]+15)
				  	   {
				  	   		XPosFor;
				  	   }
				  	   SampT.Stop;
				  	   break;
				  	case 3
				  	/* 1. Go forward.
				  	   2. Stop at switch midpoint.
				  	   3. Rotate 90 degrees counterclockwise.
				  	   4. Deliver cube.
				  	   5. Back up. */
				  	   
				  	   v_y=0;
				  	   SampT.Reset;
				  	   SampT.Start;
				  	   Robot::Robot.Forward;
				  	   while(RobotForward[0][1]<(RSwP[0][1]+RSwP[1][1])/2)
				  	   {
				  	   		YPosFor;
				  	   }
				  	   SampT.Stop;
				  	   
				  	   Robot::Robot.Turn;
				  	   
				  	   //Deliver cube
				  	   
				  	   //Back up
				  	   
				  	   v_x=0;
				  	   SampT.Reset;
				  	   SampT.Start;
				  	   Robot::Robot.Forward;
				  	   while(RobotPosition[0][0]<RSwP[2][0]+15)
				  	   {
				  	   		XPosFor;				  	   		
				  	   }
				  	   SampT.Stop;
				  	   break;
				  }
	  			 }
	  			 
		float g2in(float acc)
			{	
				g2in=acc * 386;
				return g2in;
			}
			
		/* This function calculates the current x position given acceleration and the initial x velocity and x position.
			while going forward */
			
		void XPosFor()
			{
				p_x=RobotPosition[0][0];
  	   			t = SampT.Get;
  	   			SampT.Reset;
  	   			RobotPosition[0][0] = p_x + v_x * t + .5 * g2in(BuiltInAccelerometer.GetX())*t^2;
  	   			v_xi = v_x + g2in(BuiltInAccelerometer.GetX())*t;
  	   			v_x = v_xi;
  	   			return;
			}
		/* This function calculates the current y position given acceleration and the initial y velocity and y position.
			while going forward */	
			
		void YPosFor()
			{
				p_y = RobotPosition[0][1];
  	   			t = SampT.Get;
  	   			SampT.Reset;
  	   			RobotPosition[0][1] = p_y + v_y * t + .5 * g2in(BuiltInAccelerometer.GetX())*t^2;
  	   			v_yi = v_y + g2in(BuiltInAccelerometer.GetX())*t;
  	   			v_y = v_yi;
  	   			return;				
			}
		/* This function calculates the current x position given acceleration and the initial x velocity and x position.
			while strafing */
			
		void XPosStrafe()
			{
				p_x=RobotPosition[0][0];
  	   			t = SampT.Get;
  	   			SampT.Reset;
  	   			RobotPosition[0][0] = p_x + v_x * t + .5 * g2in(BuiltInAccelerometer.GetY())*t^2;
  	   			v_xi = v_x + g2in(BuiltInAccelerometer.GetY())*t;
  	   			v_x = v_xi;
  	   			return;
			}
		/* This function calculates the current y position given acceleration and the initial y velocity and y position.
			while strafing */
				
		void YPosStrafe()
			{
				p_y = RobotPosition[0][1];
  	   			t = SampT.Get;
  	   			SampT.Reset;
  	   			RobotPosition[0][1] = p_y + v_y * t + .5 * g2in(BuiltInAccelerometer.GetY())*t^2;
  	   			v_yi = v_y + g2in(BuiltInAccelerometer.GetY())*t;
  	   			v_y = v_yi;
  	   			return;				
			}