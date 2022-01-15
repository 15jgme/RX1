#ifndef SERV_H
#define SERV_H

#include <Arduino.h>
#include <STM32SD.h>
#include <Servo.h>
#include "messages/messages.h"
#include <PinNames.h>

extern messages msg;

class Serv
{
    Servo Sy;
    Servo Sz;
    uint32_t lastT = 0;

public:
    Serv();
    void init();
    void update();
};
#endif