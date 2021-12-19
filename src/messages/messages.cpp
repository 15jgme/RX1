#include "messages.h"

messages::messages(){}
String messages::getData()
{
	String datMsg = altitude_t.getData()+","+attitude_t.getData()+","+battery_t.getData()+","+ematch_t.getData()+","+position_t.getData();
	return datMsg;
}
