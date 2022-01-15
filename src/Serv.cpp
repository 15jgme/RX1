#include "Serv.h"

Serv::Serv(){}

void Serv::init()
{
    Sy.attach(D9);
    Sz.attach(D6);
}

void Serv::update()
{
    if(msg.motormnt_t.timestamp > lastT)
    {
        Sy.write(msg.motormnt_t.getsety() - msg.motormnt_t.getoffy());
        Sz.write(msg.motormnt_t.getsetz() - msg.motormnt_t.getoffz());
        lastT = msg.motormnt_t.timestamp;
    }
}