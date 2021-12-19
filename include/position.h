#include <Arduino.h>
#ifndef POSITION_H
#define POSITION_H
class position
{
public:
	position();
	float a1 = 0.0f;
	float a2 = 0.0f;
	float a3 = 0.0f;
	String getData();
};
#endif
