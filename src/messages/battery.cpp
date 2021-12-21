#include "battery.h"



battery::battery(){}
String battery::getData()
{
	String datMsg = String(voltage)+","+String(capacity);
	return datMsg;
}
float battery::getvoltage()
{
	sample ++;
	return voltage;
}

void battery::setvoltage(float newVal)
{
	sample ++;
	voltage = newVal;
}

float battery::getcapacity()
{
	sample ++;
	return capacity;
}

void battery::setcapacity(float newVal)
{
	sample ++;
	capacity = newVal;
}

