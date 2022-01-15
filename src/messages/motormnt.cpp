#include "messages/motormnt.h"



motormnt::motormnt(){}
String motormnt::getData()
{
	String datMsg = String(timestamp)+","+String(sety)+","+String(setz)+","+String(offy)+","+String(offz);
	return datMsg;
}
String motormnt::getNames()
{
	String nameMsg = "timestamp,"+String("sety")+","+String("setz")+","+String("offy")+","+String("offz");
	return nameMsg;
}
float motormnt::getsety()
{
	return sety;
}

void motormnt::setsety(float newVal)
{
	if(newVal != sety){timestamp = micros();}
	sety = newVal;
}

float motormnt::getsetz()
{
	return setz;
}

void motormnt::setsetz(float newVal)
{
	if(newVal != setz){timestamp = micros();}
	setz = newVal;
}

float motormnt::getoffy()
{
	return offy;
}

void motormnt::setoffy(float newVal)
{
	if(newVal != offy){timestamp = micros();}
	offy = newVal;
}

float motormnt::getoffz()
{
	return offz;
}

void motormnt::setoffz(float newVal)
{
	if(newVal != offz){timestamp = micros();}
	offz = newVal;
}

