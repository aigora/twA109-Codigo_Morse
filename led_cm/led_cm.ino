void setup() 
{
  pinMode(8,OUTPUT);//8 LED ROJO
  pinMode(10,OUTPUT);//10 LED VERDE
}

void loop() 
{
  digitalWrite(8,HIGH);
  delay(100);
  digitalWrite(8,LOW);
  delay(100);
  digitalWrite(10,HIGH);
  delay(100);
  digitalWrite(10,LOW);
  delay(100);

}
