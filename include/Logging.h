#ifndef LOGGING_H
#define LOGGING_H

#include <STM32SD.h>
#include "messages.h"


class Logging
{
    messages *msg;
    File log;
    String fileName = "log_0.csv";
    u_int16_t index; 

public:
    Logging(messages *msgPtr);
    void init();
    void writeData();
};
#endif