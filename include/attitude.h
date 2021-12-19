#include <Arduino.h>
#ifndef ATTITUDE_H
#define ATTITUDE_H
class attitude
{
public:
	attitude();
	float q1 = 0.0f;
	float q2 = 0.0f;
	float q3 = 0.0f;
	float q4 = 0.0f;
	float w1 = 0.0f;
	float w2 = 0.0f;
	float w3 = 0.0f;
	float alph1 = 0.0f;
	float alph2 = 0.0f;
	float alph3 = 0.0f;
	String getData();
};
#endif
