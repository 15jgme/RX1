#include "Command.h"

Command::Command(messages *msgPtr){msg = msgPtr;}

void Command::update()
{
    switch (msg->commander_t.getstate())
    {
    case 0:
        runAbort();
        break;
    case 1:
        runStartup();
        break;
    case 2:
        runGroundIdle();
        break;
    case 3:
        runFlight();
        break;
    case 4:
        runApogee();
    case 5:
        runParachute();
    default:
        break;
    }
}

void Command::runStartup()
{
    sens.innitialize();
    logger.init();
}

void Command::runGroundIdle()
{
    led.setGreen(); led.update();
}