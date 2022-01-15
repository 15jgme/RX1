#ifndef LOGGING_H
#define LOGGING_H

#include <STM32SD.h>
#include "messages/messages.h"

extern messages msg;
class Logging
{
    File log;
    String fileName = "log_0.csv";
    u_int16_t index; 

public:
    Logging();
    void init();
    void writeData();
};
#endif