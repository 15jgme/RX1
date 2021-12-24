#include <Arduino.h>
#ifndef BATTERY_H
#define BATTERY_H
class battery
{
	float voltage = 0.0f;
	float capacity = 0.0f;
public:
	uint32_t sample = 0;
	void setvoltage(float newVal);
	float getvoltage();
	void setcapacity(float newVal);
	float getcapacity();
	battery();
	String getData(); // Returns all data in topic
	String getNames(); // Returns a string csv of the names of variables ouput by getData in same order
};
#endif
