#include "commander.h"



commander::commander(){}
String commander::getData()
{
	String datMsg = String(timestamp)+","+String(state);
	return datMsg;
}
String commander::getNames()
{
	String nameMsg = "timestamp,"+String("state");
	return nameMsg;
}
int commander::getstate()
{
	return state;
}

void commander::setstate(int newVal)
{
	if(newVal != state){timestamp = micros();}
	state = newVal;
}

