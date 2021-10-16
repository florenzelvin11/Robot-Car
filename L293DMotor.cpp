#include "L293DMotor.h"

LDMotor::LDMotor(int pinDir1AR, int pinDir2AR, int pinDir1AL, int pinDir2AL, int speedR, int speedL) 
	: Dir1ARight(pinDir1AR), Dir2ARight(pinDir2AR), Dir1ALeft(pinDir1AL), Dir2ALeft(pinDir2AL), 
	SpeedRight(speedR), SpeedLeft(speedL) {}

LDMotor::LDMotor() {}

void LDMotor::LDMotorInit(int pinDir1AR, int pinDir2AR, int pinDir1AL, int pinDir2AL, int speedR, int speedL) {
	Dir1ARight = pinDir1AR;
	Dir2ARight = pinDir2AR;
	Dir1ALeft = pinDir1AL;
	Dir2ALeft = pinDir2AL;
	SpeedRight = speedR;
	SpeedLeft = speedL;
}

void LDMotor::BeginPlay() {
	// Initialise the I - O of the pins
	pinMode(Dir1ARight, OUTPUT);
	pinMode(Dir2ARight, OUTPUT);
	pinMode(Dir1ALeft, OUTPUT);
	pinMode(Dir2ALeft, OUTPUT);
	pinMode(SpeedRight, OUTPUT);
	pinMode(SpeedLeft, OUTPUT);

}
// ================================= Set Motors =========================================== //

void LDMotor::SetRMotor(int pin1ARight, int pin2ARight, int pinSpeedRight) {
	if (pinSpeedRight < 0) {
		pinSpeedRight = 0;
	}
	else if (pinSpeedRight > 255) {
		pinSpeedRight = 255;
	}

	digitalWrite(Dir1ARight, pin1ARight);
	digitalWrite(Dir2ARight, pin2ARight);
	analogWrite(SpeedRight, pinSpeedRight);
}

void LDMotor::SetLMotor(int pin1ALeft, int pin2ALeft, int pinSpeedLeft) {
	if (pinSpeedLeft < 0) {
		pinSpeedLeft = 0;
	}
	else if (pinSpeedLeft > 255) {
		pinSpeedLeft = 255;
	}

	digitalWrite(Dir1ALeft, pin1ALeft);
	digitalWrite(Dir2ALeft, pin2ALeft);
	analogWrite(SpeedLeft, pinSpeedLeft);
}


// ================================= Movements =========================================== //
void LDMotor::Forward(int speedData) {
	// Direction - AntClockwise
	SetRMotor(LOW, HIGH, speedData);
	SetLMotor(LOW, HIGH, speedData);
}


void LDMotor::BackWard(int speedData) {
	// Direction - ClockWise
	SetRMotor(HIGH, LOW, speedData);
	SetLMotor(HIGH, LOW, speedData);
}

void LDMotor::AxialRight(int speedData) {
	SetRMotor(LOW, HIGH, speedData);
	SetLMotor(HIGH, LOW, speedData);
}

void LDMotor::AxialLeft(int speedData) {
	SetRMotor(HIGH, LOW, speedData);
	SetLMotor(LOW, HIGH, speedData);
}

void LDMotor::ForwardRadialRight(int xSpeedData, int ySpeedData) {
	SetRMotor(LOW, HIGH, ySpeedData);
	SetLMotor(LOW, HIGH, xSpeedData);
}

void LDMotor::ForwardRadialLeft(int xSpeedData, int ySpeedData) {
	SetRMotor(LOW, HIGH, ySpeedData);
	SetLMotor(LOW, HIGH, xSpeedData);
}

void LDMotor::BackwardRadialRight(int xSpeedData, int ySpeedData) {
	SetRMotor(HIGH, LOW, ySpeedData);
	SetLMotor(HIGH, LOW, xSpeedData);
}

void LDMotor::BackwardRadialLeft(int xSpeedData, int ySpeedData) {
	SetRMotor(HIGH, LOW, ySpeedData);
	SetLMotor(HIGH, LOW, xSpeedData);
}

void LDMotor::Stop(int speedData) {
	SetRMotor(LOW, LOW, speedData);
	SetLMotor(LOW, LOW, speedData);
}