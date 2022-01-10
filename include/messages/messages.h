#ifndef MESSAGES_H
#define MESSAGES_H
#include <arduino.h>
#include "altitude.h"
#include "attitude.h"
#include "battery.h"
#include "ematch.h"
#include "position.h"
#include "commander.h"
class messages
{
public:
	messages();
	altitude altitude_t;
	attitude attitude_t;
	battery battery_t;
	ematch ematch_t;
	position position_t;
	commander commander_t;
	String getData();
	String getNames();
};
#endif
