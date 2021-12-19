#include <Arduino.h>
#ifndef ALTITUDE_H
#define ALTITUDE_H
class altitude
{
public:
	altitude();
	float altitude_m = 0.0f;
	float pressure = 0.0f;
	float temperature = 0.0f;
	String getData();
};
#endif
