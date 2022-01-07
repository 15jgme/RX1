#include "Timeman.h"

Timeman::Timeman(){}

void Timeman::setSlot(int slot, uint32_t freq)
{
    freqList[slot] = freq; // Set frequency in list
}

int Timeman::nextToRun()
{
    curTime = micros();
    for(uint8_t i = 0; i < slotsUsed; i++)
    {
        if(curTime - lastRan[i] > freqList[i])
        {
            lastRan[i] = curTime;
            return i; // Return highest priority program that needs updating
        }
    }

}