#include "Command.h"

Command::Command(){msg.commander_t.setsyshealth(1); /*Set to good initially*/}

void Command::init()
{
    msg.commander_t.setstate(1);
    tman.setSlot(0, _100_HZ); // Sensors slot
    tman.setSlot(1, _100_HZ); // Logging slot
    tman.setSlot(2, _10_HZ);  // Telemetry
    tman.setSlot(3, _5_HZ);   // LED
    tman.setSlot(4, _1_HZ);   // Battery

    delay(500); // Let the BNO055 boot up
    sens.innitialize();
    logger.init();
    led.init();
    tel.init();
    serv.init();
    par.checkContinuity();
}

void Command::update()
{
    switch (msg.commander_t.getstate())
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
        // runApogee();
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
    runProj(tman.nextToRun());
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

void Command::setFlight()
{
    led.setBlue(); led.update();
    tman.setSlot(0, _100_HZ); // Sensors slot
    tman.setSlot(1, _50_HZ); // Logging slot
    tman.setSlot(2, _5_HZ);  // Telemetry
    tman.setSlot(3, _1_HZ);   // LED
    tman.setSlot(4, _1_HZ);   // Battery
    tman.setSlot(5, _25_HZ); //Motor mount

    msg.commander_t.setstate(3);

    par.Arm();
}

void Command::setParachute()
{
    tman.setSlot(0, _100_HZ); // Sensors slot
    tman.setSlot(1, _50_HZ); // Logging slot
    tman.setSlot(2, _5_HZ);  // Telemetry
    tman.setSlot(3, _1_HZ);   // LED
    tman.setSlot(4, _1_HZ);   // Battery
    tman.setSlot(5, _1_HZ); //Motor mount
    tman.setSlot(6, _1_HZ);   // Parachute

    par.Fire();
    par.update();
}

void Command::setAbort()
{
    led.setRed(); led.update();

    setParachute();

    tman.setSlot(0, _50_HZ); // Sensors slot
    tman.setSlot(1, _50_HZ); // Logging slot
    tman.setSlot(2, _5_HZ);  // Telemetry
    tman.setSlot(3, _1_HZ);   // LED
    tman.setSlot(4, _1_HZ);   // Battery
    tman.setSlot(5, _1_HZ); //Motor mount
    tman.setSlot(6, _1_HZ);   // Parachute

    msg.commander_t.setstate(0);

}

void Command::runGroundIdle()
{ 
    i = tman.nextToRun();
    runProj(i);
    if(checkLaunch())
    {
        setFlight();
    }
}

void Command::runFlight()
{ 
    i = tman.nextToRun();
    runProj(i);
    if(checkAbort())
    {
        setAbort();
    }
}

void Command::runAbort()
{ 
    i = tman.nextToRun();
    runProj(i);
}


int Command::checkLaunch()
{
    if(msg.position_t.geta1() > LIFT_LIMIT)
    {
        liftCount++;
        if(liftCount > LIFT_COUNT_MAX)
        {
            return 1;
        }
    }
    else
    {
        liftCount = 0;
    }
    return 0;
}

int Command::checkAbort()
{
    attErr = acosf(abs(2*(msg.attitude_t.getq2()*msg.attitude_t.getq4() - msg.attitude_t.getq1()*msg.attitude_t.getq3())));
    if(attErr*(180.0/3.14159) > ABORT_LIMIT)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Command::runProj(int runIdx)
{
    switch(runIdx)
    {
        case -1:
            break;
        case 0:
            sens.update();
            break;
        case 1: 
            logger.writeData();
            break;
        case 2:
            tel.update();
            break;
        case 3:
            led.update();
            break;
        case 4:
            batt.update();
            break;
        case 5:
            serv.update();
            break;
        case 6:
            par.update();
            break;
            
    }
}