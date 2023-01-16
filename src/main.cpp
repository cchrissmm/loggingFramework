#include <Arduino.h>
#include "logger.h"

logger log01("NAME","VAR01,VAR02,VAR03"); // create the logging instance passing the name and header


int var01, var02, var03;

void serialRX()
{
  if (Serial.available())
  {
    String str = Serial.readStringUntil('\n');

    if (str.startsWith("DUMP"))
    {
      Serial.println("recieved: " + str);
      log01.read();
    }
  }
}

void setup()
{
  Serial.begin(115200);
  
  log01.setBufferSize(1000); // set the ringbuffer to 1000 lines

  Serial.println("setup done");
}

void loop()
{
  var01++;
  var02 = var02 + 2;
  var03 = var03 + 3;

  String log = String(var01) + "," + String(var02) + "," + String(var03);
  log01.data(log);
  //Serial.println(log);
  delay(100);
  serialRX();
}