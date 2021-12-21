#include <Arduino.h>
#ifndef ALTITUDE_H
#define ALTITUDE_H
class altitude
{
	float altitude_m = 0.0f;
	float pressure = 0.0f;
	float temperature = 0.0f;
public:
	uint32_t sample = 0;
	void setaltitude_m(float newVal);
	float getaltitude_m();
	void setpressure(float newVal);
	float getpressure();
	void settemperature(float newVal);
	float gettemperature();
	altitude();
	String getData();
};
#endif
