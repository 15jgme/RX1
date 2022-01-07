#include "Batt.h"

Batt::Batt(){}

void Batt::update()
{
    float volt = (float)((analogRead(A6)*6.6)/1024.0);
    float cap = (float) (-101.89*pow(volt, 4) + 1107.0*pow(volt, 3) - 3960.1*pow(volt, 2) + 4674.2 * volt + 1.0);
    
    //Saturate
    if(cap > 100.0){cap = 100.0;}
    if(cap < 0.0){cap = 0.0;}

    msg.battery_t.setvoltage(volt);
    msg.battery_t.setcapacity(cap);
    msg.commander_t.setsyshealth( msg.commander_t.getsyshealth() > 50.0f); // update total health
}