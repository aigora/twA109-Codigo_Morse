
#include "LED.h"

LED LEDRojo(8);
LED LEDVerde(10);
int Estado=0;

void setup() 
{
  Serial.begin(9600);
}

void loop()
{
  char dato;
  
  switch (Estado)
  {
    case 0: if(Serial.available()>0)
            {
               dato =Serial.read();
               switch (dato)
               {
                   case '.': LEDRojo.Run(200,300);
                             tone(13,440,200);
                             Estado=1;
                             break;
                   case '-': LEDRojo.Run(400,300);
                              tone(13,440,400);
                             Estado=1;
                             break;
               }
            }
     case 1: if (LEDRojo.Update()==-1)
                  Estado=0;
             break;
  }
}
