#include "Telemetry.h"

Telemetry::Telemetry(){}

void Telemetry::init()
{
    Serial3.begin(115200);
}

void Telemetry::update()
{
    Serial3.println(msg.getData());
}