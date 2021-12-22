#include "attitude.h"



attitude::attitude(){}
String attitude::getData()
{
	String datMsg = String(q1)+","+String(q2)+","+String(q3)+","+String(q4)+","+String(w1)+","+String(w2)+","+String(w3)+","+String(alph1)+","+String(alph2)+","+String(alph3);
	return datMsg;
}
String attitude::getData()
{
	String nameMsg = String("q1")+","+String("q2")+","+String("q3")+","+String("q4")+","+String("w1")+","+String("w2")+","+String("w3")+","+String("alph1")+","+String("alph2")+","+String("alph3");
	return nameMsg;
}
float attitude::getq1()
{
	return q1;
}

void attitude::setq1(float newVal)
{
	if(newVal != q1){sample ++;}
	q1 = newVal;
}

float attitude::getq2()
{
	return q2;
}

void attitude::setq2(float newVal)
{
	if(newVal != q2){sample ++;}
	q2 = newVal;
}

float attitude::getq3()
{
	return q3;
}

void attitude::setq3(float newVal)
{
	if(newVal != q3){sample ++;}
	q3 = newVal;
}

float attitude::getq4()
{
	return q4;
}

void attitude::setq4(float newVal)
{
	if(newVal != q4){sample ++;}
	q4 = newVal;
}

float attitude::getw1()
{
	return w1;
}

void attitude::setw1(float newVal)
{
	if(newVal != w1){sample ++;}
	w1 = newVal;
}

float attitude::getw2()
{
	return w2;
}

void attitude::setw2(float newVal)
{
	if(newVal != w2){sample ++;}
	w2 = newVal;
}

float attitude::getw3()
{
	return w3;
}

void attitude::setw3(float newVal)
{
	if(newVal != w3){sample ++;}
	w3 = newVal;
}

float attitude::getalph1()
{
	return alph1;
}

void attitude::setalph1(float newVal)
{
	if(newVal != alph1){sample ++;}
	alph1 = newVal;
}

float attitude::getalph2()
{
	return alph2;
}

void attitude::setalph2(float newVal)
{
	if(newVal != alph2){sample ++;}
	alph2 = newVal;
}

float attitude::getalph3()
{
	return alph3;
}

void attitude::setalph3(float newVal)
{
	if(newVal != alph3){sample ++;}
	alph3 = newVal;
}

