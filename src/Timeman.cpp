#include "Timeman.h"

Timeman::Timeman(){}

void Timeman::setSlot(int slotNum, uint32_t freq)
{
    freqList[slotNum] = freq; // Set frequency in list
    if(slotNum > (slotsUsed - 1)){
        slotsUsed++;
    }
}

int Timeman::nextToRun()
{
    curTime = micros();
    // SerialUSB.println(slotsUsed - 1);
    for(int i = lastRet; i <= (slotsUsed - 1); i++)
    {
        if((curTime - lastRan[i]) > freqList[i])
        {
            lastRan[i] = curTime;

            if(i == (slotsUsed - 1)){
                lastRet = 0;
            }else{
                lastRet = i + 1;
            }
            
            return i; // Return next program that needs updating
        }
    }

    lastRet = 0;
    return -1;
    

}