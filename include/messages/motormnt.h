#include <Arduino.h>
#ifndef MOTORMNT_H
#define MOTORMNT_H
class motormnt
{
	float sety = 0.0f;
	float setz = 0.0f;
	float offy = 0.0f;
	float offz = 0.0f;
public:
	uint32_t timestamp = 0;
	void setsety(float newVal);
	float getsety();
	void setsetz(float newVal);
	float getsetz();
	void setoffy(float newVal);
	float getoffy();
	void setoffz(float newVal);
	float getoffz();
	motormnt();
	String getData(); // Returns all data in topic
	String getNames(); // Returns a string csv of the names of variables ouput by getData in same order
};
#endif
