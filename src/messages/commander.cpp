#include "commander.h"



commander::commander(){}
String commander::getData()
{
	String datMsg = String(state);
	return datMsg;
}
String commander::getNames()
{
	String nameMsg = String("state");
	return nameMsg;
}
int commander::getstate()
{
	return state;
}

void commander::setstate(int newVal)
{
	if(newVal != state){sample ++;}
	state = newVal;
}

