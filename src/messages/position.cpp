#include "position.h"



position::position(){}
String position::getData()
{
	String datMsg = String(a1)+","+String(a2)+","+String(a3);
	return datMsg;
}
float position::geta1()
{
	sample ++;
	return a1;
}

void position::seta1(float newVal)
{
	sample ++;
	a1 = newVal;
}

float position::geta2()
{
	sample ++;
	return a2;
}

void position::seta2(float newVal)
{
	sample ++;
	a2 = newVal;
}

float position::geta3()
{
	sample ++;
	return a3;
}

void position::seta3(float newVal)
{
	sample ++;
	a3 = newVal;
}

