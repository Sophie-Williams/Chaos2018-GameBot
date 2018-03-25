/* This files lays out the mapping of the field markings and obstacles
			Branden Wilson
			1/22/18
			
			All dimensions are in inches.
*/
 
 
 // Alliance Station (AS) dimensions.
 
	 const int AS_Width= 264;
	 const int AS_Depth= 120;
	 const int AS_Height= 120;
	 
 //
 
 // Alliance Wall (AW) dimension
 
 	int AW[4][2]={30,0,30,0,294,0,294,0};

 
 // Auto Line (AL) dimensions
 	
 	int AL[4][2]={0,120,0,122,324,120,324,122};
 	
 // EXCHANGE ZONE (EZ)
 	
 	int EZ[4][2]={104,0,104,35,152,0,152,35};
 	
 // LEFT NULL TERRITORY (LNT)
 
 	int LNT[4][2]=	{0,288,0,360,96,288,96,360};
 	
 // RIGHT NULL TERRITORY (RNT)
 
 	int RNT[4][2]={230,288,230,360,325,288,325,360};
 	
 // PLATFORM ZONE (PZ)
 
 	int PZ[4][2]={96,195,96,315,230,195,230,315};
 	
 // POWER CUBE ZONE
 
 	int PCZ[4][2]={140,98,140,140,185,98,185,140};
 	
 // LEFT GUARDRAIL (LG)
 
 	int LG[4][2]={0,35,0,350,30,0,30,0};
 	
 // RIGHT GUARDRAIL (RG)
 
 	int RG[4][2]={30,0,30,0,324,35,324,350};
 	
 // LEFT SCALE PLATE (LSP)
 
 	int LSP[4][2]={72,299,72,347,108,299,108,347};
 	
 // RIGHT SCALE PLATE (RSP)
 
 	int RSP[4][2]={216,299,216,347,252,299,252,347};
 	
 // LEFT SWITCH PLATE (LSwP)
 
 	int LSwP[4][2]={90,143,90,192,127,143,127,192};
 	
 // RIGHT SWITCH PLATE (RSwP)
 
 	int RSwP[4][2]={198,143,198,192,234,143,234,192};
 	
 // FENCE (Fe)
 	
 	int Fe[4][2]={84,140,84,196,239,140,239,196};
 	
 // POSITIONS (Pos)
 	int Pos[3][2]={30,0,162,0,294,0};
 	
