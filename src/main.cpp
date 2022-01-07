#include "main.h"

messages msg;
commander cmd;


void setup() {
  SerialUSB.begin(115200);
  Serial3.begin(115200);
  delay(500); // Delay to let the BNO055 boot up
}

void loop() {
  Serial3.println(msg.getData());
  msg.commander_t.setstate(5);
  delay(20);
}