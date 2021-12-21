#include "main.h"

messages msg;

void setup() {
  // put your setup code here, to run once:
  SerialUSB.begin(115200);
  msg.battery_t.setcapacity(99.0f);
}

void loop() {
  // put your main code here, to run repeatedly:
  SerialUSB.println(msg.getData());
}