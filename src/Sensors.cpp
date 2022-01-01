#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <Adafruit_BMP280.h>
#include <imumaths.h>

#include "Sensors.h"

/* Set the delay between fresh samples */
#define BNO055_SAMPLERATE_DELAY_MS (100)

Sensors::Sensors(messages *msgPtr)
{
    msg = msgPtr;
    Wire.begin();
}

Adafruit_BNO055 bno; 
Adafruit_BMP280 bmp; 

void Sensors::innitialize()
{
    bno = Adafruit_BNO055(55, 0x28);
    if (!bno.begin())
    {
        SerialUSB.print("No BNO055 detected");
    }
    bno.setExtCrystalUse(true);
    bmp.begin(0x76);
    bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,Adafruit_BMP280::SAMPLING_X2,Adafruit_BMP280::SAMPLING_X16,Adafruit_BMP280::FILTER_X16,Adafruit_BMP280::STANDBY_MS_500);
}

void Sensors::update(void)
{

    bno.getEvent(&SensorsData, Adafruit_BNO055::VECTOR_EULER);
    bno.getEvent(&angVelData, Adafruit_BNO055::VECTOR_GYROSCOPE);
    bno.getEvent(&linearAccelData, Adafruit_BNO055::VECTOR_LINEARACCEL);
    bno.getEvent(&mainEvent);


    imu::Quaternion quat = bno.getQuat();
    msg->attitude_t.setq1((float)quat.w());
    msg->attitude_t.setq2((float)quat.x());
    msg->attitude_t.setq3((float)quat.y());
    msg->attitude_t.setq4((float)quat.z());

    //Update accel
    msg->position_t.seta1((float)linearAccelData.acceleration.x);
    msg->position_t.seta2((float)linearAccelData.acceleration.y);
    msg->position_t.seta3((float)linearAccelData.acceleration.z);

    //Update gyro
    msg->attitude_t.setw1((float)mainEvent.gyro.x);
    msg->attitude_t.setw2((float)mainEvent.gyro.y);
    msg->attitude_t.setw3((float)mainEvent.gyro.z);

    //Update altimeter
    msg->altitude_t.setaltitude_m(bmp.readAltitude(1013.25));
    msg->altitude_t.setpressure(bmp.readPressure());
    msg->altitude_t.settemperature(bmp.readTemperature());

}
