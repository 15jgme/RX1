#include <Arduino.h>
#ifndef EMATCH_H
#define EMATCH_H
class ematch
{
public:
	ematch();
	bool em1_firing = false;
	bool em1_fired = false;
	bool em1_safe = false;
	bool em1_continuity = false;
	bool em2_firing = false;
	bool em2_fired = false;
	bool em2_safe = false;
	bool em2_continuity = false;
	String getData();
};
#endif
