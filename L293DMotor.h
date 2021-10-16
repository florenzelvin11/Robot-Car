// L293DMotor.h

#ifndef _L293DMOTOR_h
#define _L293DMOTOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class LDMotor {
private:
	// Direction Pins of Motor - OUTPUT
	int Dir1ARight;
	int Dir2ARight;
	int Dir1ALeft;
	int Dir2ALeft;

	// Speed pins for the Motors - OUTPUT
	int SpeedRight;
	int SpeedLeft;

public:
	LDMotor(int pinDir1AR, int pinDir2AR, int pinDir1AL, int pinDir2AL, int speedR, int speedL);
	LDMotor();
	// Intialise from other classes
	void LDMotorInit(int pinDir1AR, int pinDir2AR, int pinDir1AL, int pinDir2AL, int speedR, int speedL);

	// To be used in setup()
	virtual void BeginPlay();

	// Set Component Orientation
	void SetRMotor(int pin1ARight, int pin2ARight, int pinSpeedRight);
	void SetLMotor(int pin1ALeft, int pin2ALeft, int pinSpeedLeft);

	// ================================= Movements =========================================== //
	void Forward(int speedData);
	void BackWard(int speedData);
	void AxialRight(int speedData);
	void AxialLeft(int speedData);
	void ForwardRadialRight(int xSpeedData, int ySpeedData);
	void ForwardRadialLeft(int xSpeedData, int ySpeedData);
	void BackwardRadialRight(int xSpeedData, int ySpeedData);
	void BackwardRadialLeft(int xSpeedData, int ySpeedData);
	void Stop(int speedData);

};

#endif

