#include "main.h"

messages msg;

void setup() {
  SerialUSB.begin(115200);
  Serial3.begin(9600);
  msg.battery_t.setcapacity(99.0f);
}

void loop() {
  // put your main code here, to run repeatedly:
  SerialUSB.println(msg.getData());

  Serial3.println(msg.getData());
}