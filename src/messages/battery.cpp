#include "battery.h"



battery::battery(){}
String battery::getData()
{
	String datMsg = String(voltage)+","+String(capacity);
	return datMsg;
}
String battery::getData()
{
	String nameMsg = String("voltage")+","+String("capacity");
	return nameMsg;
}
float battery::getvoltage()
{
	return voltage;
}

void battery::setvoltage(float newVal)
{
	if(newVal != voltage){sample ++;}
	voltage = newVal;
}

float battery::getcapacity()
{
	return capacity;
}

void battery::setcapacity(float newVal)
{
	if(newVal != capacity){sample ++;}
	capacity = newVal;
}

