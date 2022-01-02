#include "Logging.h"

//SD Detection pin
#ifndef SD_DETECT_PIN
#define SD_DETECT_PIN SD_DETECT_NONE
#endif


Logging::Logging(messages *msgPtr)
{
    msg = msgPtr;
}

void Logging::init()
{
    //Initialize the card
    while(!msg->commander_t.getsddetect()) 
    {    
        msg->commander_t.setsddetect(SD.begin(SD_DETECT_PIN));
    }

    //Check for an available file to log to
    while (SD.exists(fileName.c_str()))
    {
        index++;
        fileName = (String)"log_" + (String)index + (String)".csv";
    }
    

    log = SD.open(fileName.c_str(), FILE_WRITE);
    msg->commander_t.setsdok(log); /* False if file not loaded */

    if (log) {
        log.seek(log.size());
    }
    String out = msg->getNames();
    log.println(out); log.flush();
}

void Logging::writeData()
{
    if(msg->commander_t.getsdok())
    {
        String out = msg->getData();
        log.println(out);
        log.flush();
    }

}