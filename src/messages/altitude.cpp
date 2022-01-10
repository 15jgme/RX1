#include "messages/altitude.h"



altitude::altitude(){}
String altitude::getData()
{
	String datMsg = String(timestamp)+","+String(altitude_m)+","+String(pressure)+","+String(temperature);
	return datMsg;
}
String altitude::getNames()
{
	String nameMsg = "timestamp,"+String("altitude_m")+","+String("pressure")+","+String("temperature");
	return nameMsg;
}
float altitude::getaltitude_m()
{
	return altitude_m;
}

void altitude::setaltitude_m(float newVal)
{
	if(newVal != altitude_m){timestamp = micros();}
	altitude_m = newVal;
}

float altitude::getpressure()
{
	return pressure;
}

void altitude::setpressure(float newVal)
{
	if(newVal != pressure){timestamp = micros();}
	pressure = newVal;
}

float altitude::gettemperature()
{
	return temperature;
}

void altitude::settemperature(float newVal)
{
	if(newVal != temperature){timestamp = micros();}
	temperature = newVal;
}

