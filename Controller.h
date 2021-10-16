// Controller.h

#ifndef _CONTROLLER_h
#define _CONTROLLER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "L293DMotor.h"

class LDMotor;

class LDController : LDMotor {
private:
	int pinX1;
	int pinY1;
	int pinSwitch;
	LDMotor motorCar;
public:
	LDController(int x1, int y1, int switch1);
	void SetMotorCarInput(int pinDir1AR, int pinDir2AR, int pinDir1AL, int pinDir2AL, int speedR, int speedL);
	virtual void BeginPlay() override;
	void ControllerRobot();
	
	
};

#endif

