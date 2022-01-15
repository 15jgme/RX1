#ifndef BATT_H
#define BATT_H

#include "messages/messages.h"
#include <Arduino.h>
#include <stm32f4xx_hal.h>

extern messages msg;

class Batt
{
    uint8_t pinNum;
public:
    Batt();
    void update();
};
#endif