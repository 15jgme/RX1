#include "messages/messages.h"

messages::messages(){}
String messages::getData()
{
	String datMsg = altitude_t.getData()+","+attitude_t.getData()+","+battery_t.getData()+","+ematch_t.getData()+","+position_t.getData()+","+commander_t.getData();
	return datMsg;
}
String messages::getNames()
{
	String namesMsg = altitude_t.getNames()+","+attitude_t.getNames()+","+battery_t.getNames()+","+ematch_t.getNames()+","+position_t.getNames()+","+commander_t.getNames();
	return namesMsg;
}
