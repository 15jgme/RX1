#include "main.h"

messages msg;
Command cmd;
String errMsg; //Holds most recent critical error message


void setup() {
  SerialUSB.begin(115200);
  cmd.init();
}

void loop() {
  cmd.update();
}