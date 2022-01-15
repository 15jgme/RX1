#ifndef TELEMETRY_H
#define TELEMETRY_H

#include "messages/messages.h"
#include <Arduino.h>

extern messages msg;

class Telemetry
{
public:
    Telemetry();
    void update();
    void init();
};
#endif