/*
 El circuito consta de una bocina conectada al pin 13 que tiene puesta una 
 resistencia para controlar el consumo del pin. La bocina permite
 oír el sonido de los puntos y las rayas que genere el mensaje que introduzcamos 
 por el monitor serial (teclado), para obtener una señal óptica.
 Conectamos un LED en el mismo pin 13. Para obtener mayor potencia utilizamos un 
 transistor en la salida.
 Este código básicamente lo que hace es recibir caracteres por el 
 puerto COM y los reproduce (luz, sonido o luz + sonido)
*/

unsigned short int punto = 70; //Duración del punto
unsigned short int raya = punto * 4; //Duración de la raya
unsigned short int negro = punto * 3; //Duración del apagado entre rayas y puntos
unsigned short int letrayletra = punto * 5; //Duración del apagado entre letras

void playTone(int tone, int duration, int speakerPin)  //Envía la señal al speakerPin (altavoz)
{
 for (long i = 0; i < duration * 1000L; i += tone * 2)
 {
   digitalWrite(speakerPin, HIGH);
   delayMicroseconds(tone);
   digitalWrite(speakerPin, LOW);
   delayMicroseconds(tone);
 }
}

void playToneLed(int tone, int duration, int speakerPin, int ledPin) //Envia la señal al altavoz y al LED.
{
 for (long i = 0; i < duration * 1000L; i += tone * 2)
 {
   digitalWrite(speakerPin, HIGH); //(pin, valor(HIGH o LOW))
   digitalWrite(ledPin, HIGH);
   delayMicroseconds(tone); //Pausa el programa el tiempo (en microsegundos) especficado
   digitalWrite(speakerPin, LOW);
   digitalWrite(ledPin, LOW);
   delayMicroseconds(tone);
 }
}

/* ########## TIPOS DE LETRA #########
 *  creamos una libreria
 *  class: una clase es una colección de funciones y variables que se mantienen juntas en un solo lugar, pueden ser :
 *   públicas: lo que significa que pueden acceder a ellas las personas que utilizan su biblioteca.
 *   privadas: lo que significa que solo se puede acceder desde la propia clase.
 */

class letra
{
  private:
    char caracter;
    char* codigo;
    int ledPin;
  public:
    letra (char car, char* cad, unsigned short int pin);
    void set (char car, char* cad, unsigned short int pin);
    void mostrar();
    void sonar();
    void mostrarYsonar();
};

letra::letra (char car, char* cad, unsigned short int pin)
 /* Constructor: cada clase tiene una función especial conocida como constructor,que se usa para crear una instancia de la clase. 
  * El constructor tiene el mismo nombre que la clase y ningún tipo de devolución.*/
{
  caracter = car;
  codigo = cad;
  ledPin = pin;
  pinMode(ledPin, OUTPUT);
}

void letra::set (char car, char* cad, unsigned short int pin) // Setter
{ 
 caracter = car;
 codigo = cad;
 ledPin = pin;
}

//¿Por qué hacer funciones de sonar y mostrar si ya hay una función que es sonarymostrar a la vez?

/*void letra::mostrar () //Enseña el código en el ledPin
{
  unsigned short int j = 0;
  while (codigo[j] != 0)
  {
   if (codigo[j] == '.')
   {
     digitalWrite (ledPin, HIGH);
     lcd.setCursor(1,2);
     lcd.print(codigo[j]);  
     delay (punto);
     digitalWrite (ledPin, LOW);
     delay (negro);
   }
   else if (codigo[j] == '-')
   {
    digitalWrite (ledPin, HIGH);
    lcd.setCursor(2,2);
    lcd.print(codigo[j]);
    delay (raya);
    digitalWrite (ledPin, LOW);
    delay (negro);
   }
    j++;
  }
  delay (letrayletra);
}*/

/*void letra::sonar () //Hace sonar el código en el speakerPin
{ 
  unsigned short int j = 0;
  while (codigo[j] != 0)
  {
   if (codigo[j] == '.')
   {
     playTone (440, 100, 9);
     delay (negro/3);
    }
    else if (codigo[j] == '-')
    {
      playTone (440, 100 * 4, 9);
      delay (negro/3);
    }
    j++;
  }
  delay (letrayletra);
}*/

void letra::mostrarYsonar () //Hace sonar y enseña el código (ledPin + speakerPin)
{ 
  unsigned short int j = 0;
  while (codigo[j] != 0)
  {
   if (codigo[j] == '.')
   {
    playToneLed (440, 100, 9, ledPin); //(frecuencia del tono(Hz), duración, pin salida, )
    delay (negro/4); //delay: para el programa por unos segundos 
   }
   else if (codigo[j] == '-')
   {
    playToneLed (440, 100 * 4, 9, ledPin);
    delay (negro/4); //delay (100)
   }
    j++;
  }
  delay (letrayletra/2);
}

void setup()
{
  Serial.begin(9600);
  pinMode(9,OUTPUT); 
}

int letraIN = 0;
unsigned short int ledPin = 13;

void loop()
{
  digitalWrite(ledPin, LOW);
  letraIN = 0;
  letraIN = Serial.read();
  letra let (0, "", ledPin);
  switch (letraIN)
  {
   case 'a':
   {
    let.set ('a', ".-", ledPin);
    break;
   }
   case 'b':
   {
    let.set ('b', "-...", ledPin)
    break;
   }
   case 'c':
   {
    let.set ('c', "-.-.", ledPin);
    break;
   }
   case 'd':
   {
    let.set ('d', "-..", ledPin);
    break;
   }
   case 'e':
   {
    let.set ('e', ".", ledPin);
    break;
   }
   case 'f':
   {
    let.set ('f', "..-.", ledPin);
    break;
   }
   case 'g':
   {
    let.set ('g', "--.", ledPin);
    break;
   }
   case 'h':
   {
    let.set ('h', "....", ledPin);
    break;
   }
   case 'i':
   {
    let.set ('i', "..", ledPin);
    break;
   }
   case 'j':
   {
    let.set ('j', ".---", ledPin); 
    break;
   }
   case 'k': 
   {
    let.set ('k', "-.-", ledPin);
    break;
   }
   case 'l': 
   {
   let.set ('l', ".-..", ledPin); 
   break;
   }
   case 'm':
   {
    let.set ('m', "--", ledPin);
    break;
   }
   case 'n': 
   {
   let.set ('n', "-.", ledPin);
   break;
   }
   case 'o': 
   {
   let.set ('o', "---", ledPin);
   break;
   }
   case 'p':
   {
   let.set ('p', ".--.", ledPin);
   break;
   }
   case 'q':
   {
   let.set ('q', "--.-", ledPin);
   break;
   }
   case 'r': 
   {
   let.set ('r', ".-.", ledPin);
   break;
   }
   case 's': 
   {
   let.set ('s', "...", ledPin);
   break;
   }
   case 't': 
   {
   let.set ('t', "-", ledPin);
   break;
   }
   case 'u':
   {
   let.set ('u', "..-", ledPin);
   break;
   }
   case 'v': 
   {
   let.set ('v', "...-", ledPin);
   break;
   }
   case 'w': 
   {
   let.set ('w', ".--", ledPin);
   break;
   }
   case 'x':
   {
   let.set ('x', "-..-", ledPin);
   break;
   }
   case 'y':
   {
   let.set ('y', "-.--", ledPin); 
   break;
   }
   case 'z':
   {
   let.set ('z', "--..", ledPin);
   break;
   }
   case '0': 
   {
   let.set ('0', "-----", ledPin);
   break;
   }
   case '1': 
   {
    let.set ('1', ".----", ledPin);
    break;
   }
   case '2':
   {
   let.set ('2', "..---", ledPin);
   break;
   }
   case '3':
   {
   let.set ('3', "...--", ledPin); 
   break;
   }
   case '4': 
   {
   let.set ('4', "....-", ledPin);
   break;
   }
   case '5': 
   {
   let.set ('5', ".....", ledPin);
   break;
   }
   case '6': 
   {
   let.set ('6', "-....", ledPin);
   break;
   }
   case '7':
   {
   let.set ('7', "--...", ledPin);
   break;
   }
   case '8': 
   {
   let.set ('8', "---..", ledPin);
   break;
   }
   case '9':
   {
   let.set ('9', "----.", ledPin); 
   break;
   }
   case '.': 
   {
   let.set ('.', ".-.-.-", ledPin); 
   break;
   }
   case ',': 
   {
   let.set (',', "--..--", ledPin);
   break;
   }
   case '?': 
   {
   let.set ('?', "..--..", ledPin); 
   break;
   }
   case '"':
   {
   let.set ('"', ".-..-.", ledPin);
   break;
   }
   case '!':
   {
   let.set ('!', ".-.-.", ledPin); 
   break;
   }
  }
   let.mostrarYsonar();
}
