#include "battery.h"



battery::battery(){}
String battery::getData()
{
	String datMsg = String(voltage)+","+String(capacity);
	return datMsg;
}
