#include "altitude.h"



altitude::altitude(){}
String altitude::getData()
{
	String datMsg = String(altitude_m)+","+String(pressure)+","+String(temperature);
	return datMsg;
}
