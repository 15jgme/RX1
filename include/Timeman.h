#ifndef TIMEMAN_H
#define TIMEMAN_H

#include <Arduino.h>

class Timeman
{
    float freqList[20]; // A maximum of 20 slots should be ok
    uint32_t lastRan[20];
    int slotsUsed = 0;
    uint32_t curTime = 0;
    int lastRet = 0;
public:
    Timeman();
    void setSlot(int slotNum, uint32_t freq);
    int nextToRun();
    void reset(){slotsUsed = 0;}
};
#endif