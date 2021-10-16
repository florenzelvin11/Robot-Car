#include "UltraSonic.h"
#include "Controller.h"
#include "L293DMotor.h"

/**
*	 Auto-Self Driving car:
*	- Using the UltraSonic Sensor to detect incoming obstabcles
*	- When the robot gets to a certain distance, it slow down to atleast 60% of its speed
*	- When the robot gets really close to the obstacle, it stops
*	- It then goes through a reset movement system
*		+ Goes Backwards
*		+ Either thurns left or right
*			- The turning rate is done randomly
*				* using -> rand() function
*		+ the robot goes through this process till its turned off
*/

// Motor 
LDMotor motorCar(7, 8, 12, 13, 9, 10);

// UltrSonic
USonic ultraSonic;

void setup()
{	
	Serial.begin(9600);
	motorCar.BeginPlay();
	ultraSonic.Init();
	
}

void loop()
{
	ultraSonic.TransmitPulse();
	long distance = ultraSonic.GetDistance();

	Movement(distance);

	delay(100);
}

void Movement(long distance) {
	if (distance >= 200) {
		// Keep moving forward	
		motorCar.Forward(255);
	}
	else if (distance >= 50) {
		// Move forward speed slowsd to 75%
		motorCar.Forward(192);
	}
	else if (distance >= 30) {
		// Foward speed 50%
		motorCar.Forward(130);
	}
	else if (distance < 20 || distance <= 0) {
		// Stop
		motorCar.Stop(0);
		delay(1500);

		// Goes Back for a short period of time
		motorCar.BackWard(255);
		delay(500);

		// Stop
		motorCar.Stop(0);
		delay(500);

		// Turns either Left or Right *Axial Turns*
		RandomTurn();
	}
}

void RandomTurn() {
	int randomTurn = random(1, 3);
	switch (randomTurn) {
	case 1:
		motorCar.AxialLeft(255);
		delay(1000);
		break;
	case 2:
		motorCar.AxialRight(255);
		delay(1000);
		break;
	default:
		break;
	}
	motorCar.Stop(0);
	delay(1500);
}

