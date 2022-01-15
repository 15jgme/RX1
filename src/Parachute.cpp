#include "Parachute.h"

Parachute::Parachute()
{
    pinMode(PIN_A0, OUTPUT); //Set the appropriate pin mode
    msg.ematch_t.setem1_safe(true);
}

void Parachute::checkContinuity()
{
    analogReadResolution(10); //10-bit max 1023
    float a = analogRead(PIN_A5);
    float v = float(a)*(3.3/1023.0); //convert to voltage
    if(v > 1.0f)
    {
        msg.ematch_t.setem1_continuity(true);
    }

}

void Parachute::Fire()
{

    if(!msg.ematch_t.getem1_safe())
    {
        msg.ematch_t.setem1_firing(true);
        digitalWrite(PIN_A0, HIGH);
        msg.ematch_t.setem1_fired(true);
        tf = millis(); // Capture trigger time
    }
}

void Parachute::update()
{
    if(!msg.ematch_t.getem1_safe() && msg.ematch_t.getem1_firing() && ((millis() - tf) > (uint32_t)(tf*1000)) )
    {
        digitalWrite(PIN_A0, LOW);
        msg.ematch_t.setem1_firing(false);
    } 
}

void Parachute::Arm()
{
    msg.ematch_t.setem1_safe(false);
}

