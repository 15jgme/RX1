#include <Arduino.h>
#ifndef ATTITUDE_H
#define ATTITUDE_H
class attitude
{
	float q1 = 0.0f;
	float q2 = 0.0f;
	float q3 = 0.0f;
	float q4 = 0.0f;
	float w1 = 0.0f;
	float w2 = 0.0f;
	float w3 = 0.0f;
public:
	uint32_t timestamp = 0;
	void setq1(float newVal);
	float getq1();
	void setq2(float newVal);
	float getq2();
	void setq3(float newVal);
	float getq3();
	void setq4(float newVal);
	float getq4();
	void setw1(float newVal);
	float getw1();
	void setw2(float newVal);
	float getw2();
	void setw3(float newVal);
	float getw3();
	attitude();
	String getData(); // Returns all data in topic
	String getNames(); // Returns a string csv of the names of variables ouput by getData in same order
};
#endif
