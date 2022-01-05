#ifndef COMMAND_H
#define COMMAND_H

#include <Arduino.h>
#include "main.h"
#include "messages.h"

class Command
{
private:
    messages *msg;
    
    Sensors sens(msg);
    Batt batt(msg);
    Logging logger(msg);
    IndicatorLed led;
public:
    Command(messages *msgPtr);
    void update();
    void runStartup();
    void runGroundIdle();
    void runFlight();
    void runApogee();
    void runParachute();

    void runAbort();
};


#endif