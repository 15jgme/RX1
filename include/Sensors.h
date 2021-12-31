#ifndef SENSORS_H
#define SENSORS_H

#include "messages.h"
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>

class Sensors
{
    messages *msg;
public:
    sensors_event_t SensorsData, linearAccelData, angVelData, mainEvent;
    Sensors(messages *msgPtr);
    void innitialize();
    void update();
};

#endif