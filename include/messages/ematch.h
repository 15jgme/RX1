#include <Arduino.h>
#ifndef EMATCH_H
#define EMATCH_H
class ematch
{
	uint32_t timestamp = 0;
	bool em1_firing = false;
	bool em1_fired = false;
	bool em1_safe = false;
	bool em1_continuity = false;
	bool em2_firing = false;
	bool em2_fired = false;
	bool em2_safe = false;
	bool em2_continuity = false;
public:
	void setem1_firing(bool newVal);
	bool getem1_firing();
	void setem1_fired(bool newVal);
	bool getem1_fired();
	void setem1_safe(bool newVal);
	bool getem1_safe();
	void setem1_continuity(bool newVal);
	bool getem1_continuity();
	void setem2_firing(bool newVal);
	bool getem2_firing();
	void setem2_fired(bool newVal);
	bool getem2_fired();
	void setem2_safe(bool newVal);
	bool getem2_safe();
	void setem2_continuity(bool newVal);
	bool getem2_continuity();
	ematch();
	String getData(); // Returns all data in topic
	String getNames(); // Returns a string csv of the names of variables ouput by getData in same order
};
#endif
