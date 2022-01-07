#include "Command.h"

Command::Command()
{
    tman.setSlot(0, _100_HZ); // Sensors slot
    tman.setSlot(1, _100_HZ); // Logging slot
    tman.setSlot(2, _10_HZ);  // Telemetry
    tman.setSlot(3, _5_HZ);   // LED
    tman.setSlot(4, _1_HZ);   // Battery

    sens.innitialize();
    logger.init();
}

void Command::update()
{
    switch (msg.commander_t.getstate())
    {
    case 0:
        // runAbort();
        break;
    case 1:
        runStartup();
        break;
    case 2:
        runGroundIdle();
        break;
    case 3:
        // runFlight();
        break;
    case 4:
        // runApogee();
    case 5:
        // runParachute();
        break;
    default:
        break;
    }
}

void Command::runStartup()
{
    if(msg.commander_t.getsyshealth())
    { 
        setGroundIdle(); 
    }
    runProj();
}

void Command::setGroundIdle()
{
    led.setGreen(); led.update();
    tman.setSlot(0, _200_HZ); // Sensors slot
    tman.setSlot(1, _10_HZ); // Logging slot
    tman.setSlot(2, _10_HZ);  // Telemetry
    tman.setSlot(3, _5_HZ);   // LED
    tman.setSlot(4, _1_HZ);   // Battery

    msg.commander_t.setstate(2);
}

void Command::runGroundIdle()
{
    runProj();
}

void Command::runProj()
{
    switch(tman.nextToRun())
    {
        case 0:
            sens.update();
            break;
        case 1: 
            logger.writeData();
            break;
        case 2:
            // tel.update()
            break;
        case 3:
            led.update();
            break;
        // case 4:
            
    }
}