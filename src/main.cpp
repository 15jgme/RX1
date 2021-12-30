#include "main.h"
#include <Adafruit_BMP280.h>

messages msg;
Adafruit_BMP280 bmp; 

void setup() {
  SerialUSB.begin(115200);
  Serial3.begin(9600);
  msg.battery_t.setcapacity(99.0f);
  bmp.begin(0x76);
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
}

void loop() {

  msg.altitude_t.setaltitude_m(bmp.readAltitude(1013.25));
  msg.altitude_t.setpressure(bmp.readPressure());
  msg.altitude_t.settemperature(bmp.readTemperature());
  SerialUSB.println(micros());
  Serial3.println(msg.getData());
  delay(100);
}