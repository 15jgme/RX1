#ifndef PARACHUTE_H
#define PARACHUTE_H
#include "messages/messages.h"

//This is a derivative of the old e-match class
extern messages msg;
class Parachute
{
    uint32_t tf = 0;
    float duration = 1; // seconds
public:
    Parachute();
    void Fire(); //Fire match
    void Arm(); //Fire match
    void checkContinuity(); //Check e-match continuity
    void update();
};
#endif