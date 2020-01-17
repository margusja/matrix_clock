#include "includes.h"

void loop(){
  
  webPage();

  time_t now;
  struct tm * timeinfo;
  time(&now);
  timeinfo = localtime(&now);
  Serial.println(timeinfo->tm_hour);
  Serial.println(timeinfo->tm_min);

  hourMinute2led(timeinfo->tm_hour,timeinfo->tm_min);
  delay(delaytime);
}
