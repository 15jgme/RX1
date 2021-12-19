#include <Arduino.h>
#ifndef BATTERY_H
#define BATTERY_H
class battery
{
public:
	battery();
	float voltage = 0.0f;
	float capacity = 0.0f;
	String getData();
};
#endif
