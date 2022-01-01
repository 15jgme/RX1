#include "main.h"

messages msg;
messages *msgPtr = & msg;
Sensors sens(msgPtr);
Batt batt(msgPtr);


void setup() {
  SerialUSB.begin(115200);
  Serial3.begin(9600);
  delay(50);
  msg.battery_t.setcapacity(99.0f);
  sens.innitialize();
}

void loop() {
  // SerialUSB.println(msg.getData());
  Serial3.println(msg.getData());
  sens.update();
  batt.update();
  delay(50);
}