#pragma config(Sensor, S3,     UltraS,         sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          Right,         tmotorEV3_Large, openLoop, driveRight, encoder)
#pragma config(Motor,  motorB,          Left,          tmotorEV3_Large, openLoop, driveLeft, encoder)
#pragma config(Motor,  motorD,          Swivel,        tmotorEV3_Medium, openLoop, encoder)

int FindNextOpening()
{
	int distance = SensorValue(UltraS);

	if (distance > 3 && distance < 8)
	{
		//plot wall on right
		setMotorTarget(Swivel, 90, -40);// Look in front
		waitUntilMotorStop(Swivel);
		resetMotorEncoder(Swivel);
		sleep(1000);
	}
	else
		return 0; // Go RIGHT

	distance = SensorValue(UltraS);
	if (distance > 3 && distance < 8)
	{
		//plot wall in front
		distance = SensorValue(UltraS);
		setMotorTarget(Swivel, 90, -40); // Look left
		waitUntilMotorStop(Swivel);
		resetMotorEncoder(Swivel);
		sleep(1000);
	}
	else
		return 1; // GO FORWARD
	distance = SensorValue(UltraS);
	if (distance > 3 && distance < 8)
	{
		return 3; // GO BACK
	}
	else
		return 2;

}

void ResetSwivel(int SwivelPosition)
{
	switch(SwivelPosition)
	{
		case 0: break;
		case 1: setMotorTarget(Swivel,90, 40);
						waitUntilMotorStop(Swivel);
						sleep(1000);
						resetMotorEncoder(Swivel);
						break;
		case 2: setMotorTarget(Swivel,180, 40);
						waitUntilMotorStop(Swivel);
						sleep(1000);
						resetMotorEncoder(Swivel);
						break;
		case 3: setMotorTarget(Swivel,180, 40);
						waitUntilMotorStop(Swivel);
						sleep(1000);
						resetMotorEncoder(Swivel);
						break;
		default: break;
	}
}

task main()
{
while(1)
{
int x = FindNextOpening();
ResetSwivel(x);
}


}
