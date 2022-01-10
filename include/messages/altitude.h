#include <Arduino.h>
#ifndef ALTITUDE_H
#define ALTITUDE_H
class altitude
{
	uint32_t timestamp = 0;
	float altitude_m = 0.0f;
	float pressure = 0.0f;
	float temperature = 0.0f;
public:
	void setaltitude_m(float newVal);
	float getaltitude_m();
	void setpressure(float newVal);
	float getpressure();
	void settemperature(float newVal);
	float gettemperature();
	altitude();
	String getData(); // Returns all data in topic
	String getNames(); // Returns a string csv of the names of variables ouput by getData in same order
};
#endif
