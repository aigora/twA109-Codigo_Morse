
#include "LED.h"
#include <Arduino.h>

LED::LED(int pin)
{
  pinLED = pin;
  Estado = -1;
  pinMode(pinLED,OUTPUT);
  digitalWrite(pinLED,LOW);
}

void LED::Run(int t_on,int t_off)
{
  Tiempo_On = t_on;
  Tiempo_Off = t_off;
  digitalWrite (pinLED,HIGH);
  inicio=millis();
  Estado=1;
}
int LED::Update()
{
  if (Estado==1 && millis()-inicio>Tiempo_On)
  {
    digitalWrite (pinLED,LOW);
    Estado=0;
    inicio=millis();
  }
  else
    if (Estado==0 && millis()-inicio>Tiempo_Off)
    {
      Estado=-1;
      inicio=millis();
    }
  return (Estado);
}
