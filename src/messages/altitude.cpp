#include "altitude.h"



altitude::altitude(){}
String altitude::getData()
{
	String datMsg = String(altitude_m)+","+String(pressure)+","+String(temperature);
	return datMsg;
}
String altitude::getNames()
{
	String nameMsg = String("altitude_m")+","+String("pressure")+","+String("temperature");
	return nameMsg;
}
float altitude::getaltitude_m()
{
	return altitude_m;
}

void altitude::setaltitude_m(float newVal)
{
	if(newVal != altitude_m){sample ++;}
	altitude_m = newVal;
}

float altitude::getpressure()
{
	return pressure;
}

void altitude::setpressure(float newVal)
{
	if(newVal != pressure){sample ++;}
	pressure = newVal;
}

float altitude::gettemperature()
{
	return temperature;
}

void altitude::settemperature(float newVal)
{
	if(newVal != temperature){sample ++;}
	temperature = newVal;
}

