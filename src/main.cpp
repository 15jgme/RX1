#include "main.h"

messages msg;
Command cmd;
String errMsg; //Holds most recent critical error message


void setup() {
  SerialUSB.begin(115200);
  Serial3.begin(115200);
  delay(500); // Delay to let the BNO055 boot up
  cmd.update();
}

void loop() {
  Serial3.println(msg.getData());
  cmd.update();
  delay(20);
}