#include "main.h"

messages msg;
messages *msgPtr = & msg;
Sensors sens(msgPtr);
Batt batt(msgPtr);
Logging logger(msgPtr);
IndicatorLed led;


void setup() {
  SerialUSB.begin(115200);
  Serial3.begin(115200);
  delay(500); // Delay to let the BNO055 boot up
}

void loop() {
  // SerialUSB.println(msg.getData());
  Serial3.println(msg.getData());
  sens.update();
  batt.update();
  logger.writeData();
  msg.commander_t.setstate(5);
  delay(20);
}