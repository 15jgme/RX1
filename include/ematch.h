#include <Arduino.h>
#ifndef EMATCH_H
#define EMATCH_H
class ematch
{
public:
	ematch();
	bool em1_firing = 0.0f;
	bool em1_fired = 0.0f;
	bool em1_safe = 0.0f;
	bool em1_continuity = 0.0f;
	bool em2_firing = 0.0f;
	bool em2_fired = 0.0f;
	bool em2_safe = 0.0f;
	bool em2_continuity = 0.0f;
	String getData();
};
#endif
