#include "commander.h"



commander::commander(){}
String commander::getData()
{
	String datMsg = String(timestamp)+","+String(state)+","+String(sddetect)+","+String(sdok);
	return datMsg;
}
String commander::getNames()
{
	String nameMsg = "timestamp,"+String("state")+","+String("sddetect")+","+String("sdok");
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

bool commander::getsddetect()
{
	return sddetect;
}

void commander::setsddetect(bool newVal)
{
	if(newVal != sddetect){timestamp = micros();}
	sddetect = newVal;
}

bool commander::getsdok()
{
	return sdok;
}

void commander::setsdok(bool newVal)
{
	if(newVal != sdok){timestamp = micros();}
	sdok = newVal;
}

