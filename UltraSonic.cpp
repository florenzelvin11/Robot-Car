#include "UltraSonic.h"

USonic::USonic(uint8_t pinTrig, uint8_t pinEcho, uint8_t timePulseDelay)
	: transmitter(pinTrig), reciever(pinEcho), pulseDelay(timePulseDelay) {}

USonic::USonic()
	: USonic(6, 5, 10) {}

void USonic::Init() {
	pinMode(transmitter, OUTPUT);
	pinMode(reciever, INPUT);
}

void USonic::TransmitPulse() {
	digitalWrite(transmitter, LOW);
	delayMicroseconds(10);	// The Sensor is put to low again for 10 microseconds, to ensure the sensor is resetted
	digitalWrite(transmitter, HIGH);
	delayMicroseconds(pulseDelay); // The length of how long in respect of time, a pulse is Outputted
	digitalWrite(transmitter, LOW); // Turns the sensor after the iteration

	RecievePulseData();

	CalcDistance();
}

void USonic::RecievePulseData() {
	duration = pulseIn(reciever, HIGH);
}

void USonic::CalcDistance() {
	distance = (duration / 2) / 29.1;
}

long USonic::GetDistance() {
	return distance;
}