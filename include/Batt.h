#ifndef BATT_H
#define BATT_H

#include "messages.h"
#include <Arduino.h>
#include <stm32f4xx_hal.h>

class Batt
{
    messages *msg;
    uint8_t pinNum;
public:
    Batt(messages *msgPtr);
    void update();
};
#endif