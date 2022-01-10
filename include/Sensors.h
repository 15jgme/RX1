#ifndef SENSORS_H
#define SENSORS_H

#include "messages/messages.h"
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <Adafruit_BMP280.h>
#include <imumaths.h>

class Sensors
{
    // messages *msg;
public:
    sensors_event_t SensorsData, linearAccelData, angVelData, mainEvent;
    Sensors(messages *msgPtr); // Depreciated
    Sensors();
    void innitialize();
    void update();
};

#endif