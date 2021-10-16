// UltraSonic.h

#ifndef _ULTRASONIC_h
#define _ULTRASONIC_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class USonic {

private:
	uint8_t transmitter;
	uint8_t reciever;
	uint8_t pulseDelay;
	
	long duration;
	long distance;

public:
	// Constructors
	USonic(uint8_t pinTrig, uint8_t pinEcho, uint8_t timePulseDelay);
	USonic();

	// Setup for the pin class
	void Init();

	// Transmits and Recieve the data from the pulses
	void TransmitPulse();
	void RecievePulseData();
	void CalcDistance();

	// Getters and Setters
	long GetDistance();
	
	
};

#endif

