const int LEDrojo = 8;
const int LEDverde = 10;

void setup() 
{
  //¿Hace falta Serial.begin(9600); ?
  pinMode(LEDrojo,OUTPUT); //salida 8 ->  LED ROJO
  pinMode(LEDverde,OUTPUT); //salida 10 -> LED VERDE
}

void loop() 
{
  led_punto();
  led_raya();
  /*digitalWrite(8,HIGH); //Pone a '1 lógico' (5V) el pin 8
  delay(100); //Espera durante 100 ms
  digitalWrite(8,LOW); //Pone a '0 lógico' (0V) el pin 8
  delay(100);
  digitalWrite(10,HIGH); //VERDE
  delay(100);
  digitalWrite(10,LOW);
  delay(100);*/
}

void led_punto() 
{ 
   digitalWrite(LEDrojo,HIGH); //Pone a “1 lógico”(5V) el pin 8
   delay(200); //Espera durante 200 ms
   digitalWrite(LEDrojo,LOW); //Pone a “0 lógico”(0V) el pin 8
   delay(300); //Espera durante 300 ms 
   digitalWrite(LEDverde,HIGH); //Pone a “1 lógico”(5V) el pin 10
   delay(200); //Espera durante 200 ms
   digitalWrite(LEDverde,LOW); //Pone a “0 lógico”(0V) el pin 10
   delay(300); //Espera durante 300 ms
} 

//La duración total de cada estado es de 500 ms (cada símbolo tiene asocidado la misma duración)

void led_raya() 
{ 
   digitalWrite(LEDrojo,HIGH); //Pone a “1 lógico”(5V) el pin 8
   delay(400); //Espera durante 400 ms
   digitalWrite(LEDrojo,LOW); //Pone a “0 lógico”(0V) el pin 8
   delay(100); //Espera durante 100 ms
   digitalWrite(LEDverde,HIGH); //Pone a “1 lógico”(5V) el pin 10
   delay(400); //Espera durante 400 ms 
   digitalWrite(LEDverde,LOW); //Pone a “0 lógico”(0V) el pin 10
   delay(100); //Espera durante 100 ms
}
