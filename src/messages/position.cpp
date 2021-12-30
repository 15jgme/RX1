#include "position.h"



position::position(){}
String position::getData()
{
	String datMsg = String(a1)+","+String(a2)+","+String(a3)+","+String(timestamp);
	return datMsg;
}
String position::getNames()
{
	String nameMsg = String("a1")+","+String("a2")+","+String("a3")+","+"timestamp";
	return nameMsg;
}
float position::geta1()
{
	return a1;
}

void position::seta1(float newVal)
{
	if(newVal != a1){timestamp = micros();}
	a1 = newVal;
}

float position::geta2()
{
	return a2;
}

void position::seta2(float newVal)
{
	if(newVal != a2){timestamp = micros();}
	a2 = newVal;
}

float position::geta3()
{
	return a3;
}

void position::seta3(float newVal)
{
	if(newVal != a3){timestamp = micros();}
	a3 = newVal;
}

