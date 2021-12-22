#include <Arduino.h>
#ifndef POSITION_H
#define POSITION_H
class position
{
	float a1 = 0.0f;
	float a2 = 0.0f;
	float a3 = 0.0f;
public:
	uint32_t sample = 0;
	void seta1(float newVal);
	float geta1();
	void seta2(float newVal);
	float geta2();
	void seta3(float newVal);
	float geta3();
	position();
	String getData(); // Returns all data in topic
	String getNames(); // Returns a string csv of the names of variables ouput by getData in same order
};
#endif
