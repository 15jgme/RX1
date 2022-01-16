#include "messages/attitude.h"



attitude::attitude(){}
String attitude::getData()
{
	String datMsg = String(timestamp)+","+String(q1)+","+String(q2)+","+String(q3)+","+String(q4)+","+String(w1)+","+String(w2)+","+String(w3);
	return datMsg;
}
String attitude::getNames()
{
	String nameMsg = "timestamp,"+String("q1")+","+String("q2")+","+String("q3")+","+String("q4")+","+String("w1")+","+String("w2")+","+String("w3");
	return nameMsg;
}
float attitude::getq1()
{
	return q1;
}

void attitude::setq1(float newVal)
{
	if(newVal != q1){timestamp = micros();}
	q1 = newVal;
}

float attitude::getq2()
{
	return q2;
}

void attitude::setq2(float newVal)
{
	if(newVal != q2){timestamp = micros();}
	q2 = newVal;
}

float attitude::getq3()
{
	return q3;
}

void attitude::setq3(float newVal)
{
	if(newVal != q3){timestamp = micros();}
	q3 = newVal;
}

float attitude::getq4()
{
	return q4;
}

void attitude::setq4(float newVal)
{
	if(newVal != q4){timestamp = micros();}
	q4 = newVal;
}

float attitude::getw1()
{
	return w1;
}

void attitude::setw1(float newVal)
{
	if(newVal != w1){timestamp = micros();}
	w1 = newVal;
}

float attitude::getw2()
{
	return w2;
}

void attitude::setw2(float newVal)
{
	if(newVal != w2){timestamp = micros();}
	w2 = newVal;
}

float attitude::getw3()
{
	return w3;
}

void attitude::setw3(float newVal)
{
	if(newVal != w3){timestamp = micros();}
	w3 = newVal;
}

