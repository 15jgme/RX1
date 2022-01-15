#include "messages/battery.h"



battery::battery(){}
String battery::getData()
{
	String datMsg = String(timestamp)+","+String(voltage)+","+String(capacity);
	return datMsg;
}
String battery::getNames()
{
	String nameMsg = "timestamp,"+String("voltage")+","+String("capacity");
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

