#include "altitude.h"



altitude::altitude(){}
String altitude::getData()
{
	String datMsg = String(altitude_m)+","+String(pressure)+","+String(temperature);
	return datMsg;
}
float altitude::getaltitude_m()
{
	sample ++;
	return altitude_m;
}

void altitude::setaltitude_m(float newVal)
{
	sample ++;
	altitude_m = newVal;
}

float altitude::getpressure()
{
	sample ++;
	return pressure;
}

void altitude::setpressure(float newVal)
{
	sample ++;
	pressure = newVal;
}

float altitude::gettemperature()
{
	sample ++;
	return temperature;
}

void altitude::settemperature(float newVal)
{
	sample ++;
	temperature = newVal;
}

