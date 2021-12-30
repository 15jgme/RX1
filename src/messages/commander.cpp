#include "commander.h"



commander::commander(){}
String commander::getData()
{
	String datMsg = String(state)+","+String(timestamp);
	return datMsg;
}
String commander::getNames()
{
	String nameMsg = String("state")+","+"timestamp";
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

