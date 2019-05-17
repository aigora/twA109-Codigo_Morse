
#include "LED.h"

LED LEDRojo(8);
LED LEDVerde(10);
int Estado=0;
int fin1,fin2;

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
                             tone(13,440,200); //pin, frecuencia, duración
                             Estado=1;
                             LEDVerde.Run(200,300);
                             tone(13,440,200);
                             Estado=1;
                             break;
                   case '-': LEDRojo.Run(400,100);
                             tone(13,440,400);
                             Estado=1;                          
                             LEDVerde.Run(400,100);
                             tone(13,440,400);
                             Estado=1;
                             break;                            
               }
            }
            break;
     case 1: fin1 = LEDVerde.Update(); 
             fin2 = LEDRojo.Update();
            if (fin1==-1 && fin2==-1)
                  Estado=0;
             break;
  }
}
