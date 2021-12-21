#include "attitude.h"



attitude::attitude(){}
String attitude::getData()
{
	String datMsg = String(q1)+","+String(q2)+","+String(q3)+","+String(q4)+","+String(w1)+","+String(w2)+","+String(w3)+","+String(alph1)+","+String(alph2)+","+String(alph3);
	return datMsg;
}
float attitude::getq1()
{
	sample ++;
	return q1;
}

void attitude::setq1(float newVal)
{
	sample ++;
	q1 = newVal;
}

float attitude::getq2()
{
	sample ++;
	return q2;
}

void attitude::setq2(float newVal)
{
	sample ++;
	q2 = newVal;
}

float attitude::getq3()
{
	sample ++;
	return q3;
}

void attitude::setq3(float newVal)
{
	sample ++;
	q3 = newVal;
}

float attitude::getq4()
{
	sample ++;
	return q4;
}

void attitude::setq4(float newVal)
{
	sample ++;
	q4 = newVal;
}

float attitude::getw1()
{
	sample ++;
	return w1;
}

void attitude::setw1(float newVal)
{
	sample ++;
	w1 = newVal;
}

float attitude::getw2()
{
	sample ++;
	return w2;
}

void attitude::setw2(float newVal)
{
	sample ++;
	w2 = newVal;
}

float attitude::getw3()
{
	sample ++;
	return w3;
}

void attitude::setw3(float newVal)
{
	sample ++;
	w3 = newVal;
}

float attitude::getalph1()
{
	sample ++;
	return alph1;
}

void attitude::setalph1(float newVal)
{
	sample ++;
	alph1 = newVal;
}

float attitude::getalph2()
{
	sample ++;
	return alph2;
}

void attitude::setalph2(float newVal)
{
	sample ++;
	alph2 = newVal;
}

float attitude::getalph3()
{
	sample ++;
	return alph3;
}

void attitude::setalph3(float newVal)
{
	sample ++;
	alph3 = newVal;
}

