#include "battery.h"



battery::battery(){}
String battery::getData()
{
	String datMsg = String(voltage)+","+String(capacity)+","+String(timestamp);
	return datMsg;
}
String battery::getNames()
{
	String nameMsg = String("voltage")+","+String("capacity")+","+"timestamp";
	return nameMsg;
}
float battery::getvoltage()
{
	return voltage;
}

void battery::setvoltage(float newVal)
{
	if(newVal != voltage){timestamp = micros();}
	voltage = newVal;
}

float battery::getcapacity()
{
	return capacity;
}

void battery::setcapacity(float newVal)
{
	if(newVal != capacity){timestamp = micros();}
	capacity = newVal;
}

