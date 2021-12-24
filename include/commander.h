#include <Arduino.h>
#ifndef COMMANDER_H
#define COMMANDER_H
class commander
{
	int state = 0.0f;
public:
	uint32_t sample = 0;
	void setstate(int newVal);
	int getstate();
	commander();
	String getData(); // Returns all data in topic
	String getNames(); // Returns a string csv of the names of variables ouput by getData in same order
};
#endif
