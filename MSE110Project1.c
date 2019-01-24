#pragma config(Sensor, S1,     color,          sensorEV3_Color, modeEV3Color_Color)
#pragma config(Sensor, S4,     ultra,          sensorEV3_Ultrasonic)
#pragma config(Motor,  motorB,          left,          tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          right,         tmotorEV3_Large, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

long colorR, colorB, colorG;


task main()
{
	while(1)
	{
	nMotorEncoder[left] = 0;
	nMotorEncoder[right] = 0;
	getColorRGB(color,colorR,colorG,colorB);
	//first part, before detecting, object
		while(getUSDistance(ultra) > 10){
		getColorRGB(color,colorR,colorG,colorB);

		if(colorR > 19)
		{
			displayCenteredBigTextLine(5,"%d",colorG);
			motor[left] = 10;
			motor[right] = -20;
			getColorRGB(color,colorR,colorG,colorB);
		}

		if(colorR < 14)
		{
			displayCenteredBigTextLine(5,"%d",colorG);
			motor[left] = -20;
			motor[right] = 10;
			getColorRGB(color,colorR,colorG,colorB);
		}

		if(colorR > 13 && colorR < 20)
		{
			displayCenteredBigTextLine(5,"%d",colorG);
			motor[left] = 40;
			motor[right] = 40;
			getColorRGB(color,colorR,colorG,colorB);
		}
	}
	//second part after detecting object
	setSoundVolume(100);
	playSound(soundBeepBeep);
	sleep(2000);
	// if its green, turn around and go back
	if(getUSDistance(ultra) < 10)
{
	setSoundVolume(100);
	nMotorEncoder[left] = 0;
	nMotorEncoder[right] = 0;
	motor[left] = 0;
	motor[right] = 0;
	playSound(soundBeepBeep);
	sleep(2000);
	if(colorG > 10){
		turnRight(180, degrees, 20);
	}


	// if its not green (blue), remove object, then keep going
	if(colorG < 10)
	{
		displayCenteredBigTextLine(5, "d", "BLUE BLUE BLUE");
		wait1Msec(2);

	}
	}
}
}
