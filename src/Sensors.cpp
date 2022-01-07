#include "Sensors.h"

/* Set the delay between fresh samples */
#define BNO055_SAMPLERATE_DELAY_MS (100)

extern messages msg;

Sensors::Sensors(messages *msgPtr)
{
    // msg = msgPtr;
    Wire.begin();
}
Sensors::Sensors()
{
    // msg = msgPtr;
    Wire.begin();
}


Adafruit_BNO055 bno; 
Adafruit_BMP280 bmp; 

void Sensors::innitialize()
{
    bno = Adafruit_BNO055(55, 0x28);
    
    msg.commander_t.setsyshealth(bno.begin() && msg.commander_t.getsyshealth());
    msg.commander_t.setsyshealth(bmp.begin(0x76) && msg.commander_t.getsyshealth());
    
    bno.setExtCrystalUse(true);
    bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,Adafruit_BMP280::SAMPLING_X2,Adafruit_BMP280::SAMPLING_X16,Adafruit_BMP280::FILTER_X16,Adafruit_BMP280::STANDBY_MS_500);
}

void Sensors::update(void)
{

    bno.getEvent(&angVelData, Adafruit_BNO055::VECTOR_GYROSCOPE);
    bno.getEvent(&linearAccelData, Adafruit_BNO055::VECTOR_LINEARACCEL);
    bno.getEvent(&mainEvent);

    imu::Quaternion quat = bno.getQuat();

    msg.attitude_t.setq1((float)quat.w());
    msg.attitude_t.setq2((float)quat.x());
    msg.attitude_t.setq3((float)quat.y());
    msg.attitude_t.setq4((float)quat.z());

    //Update accel
    msg.position_t.seta1((float)linearAccelData.acceleration.x);
    msg.position_t.seta2((float)linearAccelData.acceleration.y);
    msg.position_t.seta3((float)linearAccelData.acceleration.z);

    //Update gyro
    msg.attitude_t.setw1((float)angVelData.gyro.x);
    msg.attitude_t.setw2((float)angVelData.gyro.y);
    msg.attitude_t.setw3((float)angVelData.gyro.z);

    //Update altimeter
    msg.altitude_t.setaltitude_m(bmp.readAltitude(1013.25));
    msg.altitude_t.setpressure(bmp.readPressure());
    msg.altitude_t.settemperature(bmp.readTemperature());

}
