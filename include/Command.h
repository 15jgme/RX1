#ifndef COMMAND_H
#define COMMAND_H

#define _1_HZ uint32_t(1 * 1e6)
#define _5_HZ uint32_t(0.2 * 1e6)
#define _10_HZ uint32_t(0.1 * 1e6)
#define _25_HZ uint32_t(0.04 * 1e6)
#define _50_HZ uint32_t(0.02 * 1e6)
#define _100_HZ uint32_t(0.01 * 1e6)
#define _200_HZ uint32_t(0.005 * 1e6)

#include <Arduino.h>
#include "main.h"
#include "messages/messages.h"
#include "Timeman.h"

extern messages msg; //This is probably what I want

class Command
{
private:
    // messages *msg;
    Timeman tman;
    
    Sensors sens;
    Batt batt;
    Logging logger;
    IndicatorLed led;
    Telemetry tel;
    // 1 = sensors; 2 = control; 3 = logging; 4 = telemetry; 5 = parachute;
    int i = 0;
    int toRun = 0;
public:
    Command();
    void init();

    void update();
    void runStartup();
    void runGroundIdle();
    void runFlight();
    void runApogee();
    void runAbort();
    void runParachute();

    void setStartup();
    void setGroundIdle();
    void setFlight();
    void setApogee();
    void setAbort();
    void setParachute();

    void runProj(int runIdx);
};


#endif