#include "Controller.h"
#include "L293DMotor.h"

LDController::LDController(int x1, int y1, int switch1)
	: pinX1(x1), pinY1(y1), pinSwitch(switch1) {}

void LDController::SetMotorCarInput(int pinDir1AR, int pinDir2AR, int pinDir1AL, int pinDir2AL, int speedR, int speedL) {
	LDMotorInit(pinDir1AR, pinDir2AR, pinDir1AL, pinDir2AL, speedR, speedL);
}

void LDController::BeginPlay() {
	LDMotor::BeginPlay();
	pinMode(pinSwitch, INPUT_PULLUP);
}

void LDController::ControllerRobot() {
	int x1Data = analogRead(pinX1);
	int y1Data = analogRead(pinY1);

	// Movement of the robot in respect of the joystick controller

	if ((x1Data >= 517 && x1Data <= 520) &&
		(y1Data >= 500 && y1Data <= 515)) {
		// Stops the Robot 
		Serial.println("Stop");
		Stop(0);
	}
	else if ((x1Data > 517 && x1Data <= 1023) &&
		(y1Data >= 500 && y1Data <= 515)) {
		// Forward Movement
		int forwardSpeed = map(x1Data, 517, 1023, 0, 255);
		Forward(forwardSpeed);
		Serial.println("Forward");
	}
	else if ((x1Data > 0 && x1Data < 517) &&
		(y1Data >= 500 && y1Data <= 515)) {
		// Backward Movement
		int backwardSpeed = map(x1Data, 517, 0, 0, 255);
		BackWard(backwardSpeed);
		Serial.println("Backward");
	}
	else if ((x1Data >= 517 && x1Data <= 520) &&
		(y1Data > 515 && y1Data <= 1023)) {
		// Right Axial Movement
		int rightAxialSpeed = map(y1Data, 515, 1023, 0, 255);
		AxialRight(rightAxialSpeed);
		Serial.println("Axial Right");
	}
	else if ((x1Data >= 517 && x1Data <= 520) &&
		(y1Data < 500 && y1Data >= 0)) {
		// Left Axial Movement
		int leftAxialSpeed = map(y1Data, 500, 0, 0, 255);
		AxialLeft(leftAxialSpeed);
		Serial.println("Axial Left");
	}
	else if ((x1Data > 517 && x1Data <= 1023) &&
		(y1Data > 515 && y1Data <= 1023)) {
		// Right Radial Movement Forward
		int rightWheelSpeed = map(y1Data, 515, 1023, 0, 130);
		int leftWheelSpeed = map(x1Data, 517, 1023, 0, 255);
		ForwardRadialRight(leftWheelSpeed, rightWheelSpeed);
		Serial.println("Forward Radial Right");
	}
	else if ((x1Data > 517 && x1Data <= 1023) &&
		(y1Data < 500 && y1Data >= 0)) {
		// Left Radial Movement Forward
		int rightWheelSpeed = map(y1Data, 500, 0, 0, 255);
		int leftWheelSpeed = map(x1Data, 517, 1023, 0, 130);
		ForwardRadialLeft(leftWheelSpeed, rightWheelSpeed);
		Serial.println("Forward Radial Left");
	}
	else if ((x1Data > 0 && x1Data < 517) &&
		(y1Data > 515 && y1Data <= 1023)) {
		// Right Radial Movement Backward
		int rightWheelSpeed = map(y1Data, 515, 1023, 0, 130);
		int leftWheelSpeed = map(x1Data, 517, 0, 0, 255);
		BackwardRadialRight(leftWheelSpeed, rightWheelSpeed);
		Serial.println("Backward Radial Right");
	}
	else if ((x1Data > 0 && x1Data < 517) &&
		(y1Data < 500 && y1Data >= 0)) {
		// Left Radial Movement BackWard
		int rightWheelSpeed = map(y1Data, 500, 0, 0, 255);
		int leftWheelSpeed = map(x1Data, 517, 0, 0, 130);
		BackwardRadialLeft(leftWheelSpeed, rightWheelSpeed);
		Serial.println("Backward Radial Left");
		
	}
}


