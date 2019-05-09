
#include "LED.h"

LED LEDRojo(8);
LED LEDVerde(10);
int Estado=0;

void setup() 
{
  Serial.begin(9600);
  Estado=0;
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
                             Estado=1;
                             break;
                   case '-': LEDRojo.Run(400,100);
                             Estado=1;
                             break;
               }
            }
            break;
     case 1: if (LEDRojo.Update()==-1)
             {
                  Estado=0;
             }
             break;
  }
}
