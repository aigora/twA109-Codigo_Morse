#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SerialPort.h"

#define N 100
#define MAX_DATA_LENGTH 255

char menu(); //FUNCIÓN PARA DISTINGUIR SI ES UN MENSAJE DE SOCORRO O NO.
void mensaje(char []); //FUNCIÓN PARA INTRODUCIR EL MENSAJE 
char mayusculas(char); //FUNCION PARA QUE, EN CASO DE UNA MAYÚSCULA, SE CONVIERTA A MINÚSCULA.
int simbolo_ok(char); //FUNCIÓN PARA DESCARTAR TODOS LOS CARACTERES QUE NO SEAN VÁLIDOS DENTRO DE LA SELECCIÓN
void imprimir(char *); //FUNCIÓN PARA IMPRIMIR POR PANTALLA EL CÓDIGO MORSE
void autoConnect(SerialPort *arduino, char *);

int main()
{
	char cad[N];
	char opcion;
	do {
		opcion = menu();
		switch (opcion)
		{
			case 'a': mensaje(cad); //Instrucciones asociadas
			          printf("Se enciende un LED rojo.\n");
                      imprimir(cad); //enviar los datos a arduino.
					  break;
			case 'b': mensaje(cad); //Instrucciones asociadas
			          printf("Se enciende un LED verde.\n");
                      imprimir(cad);
					  break;
		}
	} while (opcion != '*');
	
	SerialPort *arduino; //Arduino SerialPort object
	char *portName = "\\\\.\\COM3"; //Puerto serie en el que está Arduino
	char incomingData[MAX_DATA_LENGTH]; //Buffer para datos procedentes de Arduino
	arduino = (SerialPort *)malloc(sizeof(SerialPort)); //Crear estructura de datos del puerto serie
	Crear_Conexion(arduino, portName); //Apertura del puerto serie
	autoConnect(arduino, incomingData);

	system("pause");
	return 0;
}

char menu() //FUNCIÓN PARA DISTINGUIR SI ES UN MENSAJE DE SOCORRO O NO.
{
  char opcion;
  do 
  {
	printf("Indique el motivo de su mensaje.\n");
    printf ("Pulse la letra 'a' si es un mensaje de alerta o socorro o la letra 'b' si es cualquier otro tipo de mensaje.\n");
	printf("\nSi desea salir del programa introduzca '*': ");
	scanf("%c", &opcion); //scanf_s("%c", &opcion);
    fflush(stdin);
    if (opcion != '*' && opcion != 'a' && opcion != 'b')
		printf("Ha marcado una letra incorrecta");
  } while (opcion != '*' && opcion != 'a' && opcion != 'b');
  return (opcion);
}

void mensaje (char c[]) //FUNCIÓN PARA INTRODUCIR EL MENSAJE
{
  int i, resultado;
  do
  {
    printf("Introduzca su mensaje (puede introducir numeros, espacios, comas, exclamaciones, interrogaciones, comillas o puntos si lo desea): ");
    gets(c); // gets_s(c);
	resultado = 1; //Doy por hecho que todos los caracteres son correctos, que es lo más lógico
	for (i = 0; c[i] != '\0'; i++)
	{
		if (simbolo_ok(c[i]) == 0) //Descarto qué símbolos no son válidos, lo comparo con mi selección
			resultado = 0;
		else
		{
			if (c[i] >= 'A' && c[i] <= 'Z')
				c[i] = mayusculas(c[i]); //Llamo a la función para pasar cualquier mayúscula que haya a minúsculas
		}			
	}
    if (resultado == 0)
      printf("Algun caracter de los que ha introducido no es correcto.\n");
  } while (resultado == 0); //Se repite el bucle hasta que todos los caracteres sean correctos
}

int simbolo_ok(char c) //FUNCIÓN PARA DESCARTAR TODOS LOS CARACTERES QUE NO SEAN VÁLIDOS DENTRO DE LA SELECCIÓN
{
	int resultado = 0;  //Considero por defecto que no es válido
	if (c >= 'A' && c <= 'Z')
		resultado = 1;
	else
		if (c >= 'a' && c <= 'z')
			resultado = 1;
		else
			if (c >= '0' && c <= '9')
				resultado = 1;
			else
				if (c == '.' || c == ',' || c == '?' || c == '"' || c == '!' || c == ' ')
					resultado = 1;
	return resultado;
}

char mayusculas(char letra) //FUNCION PARA QUE, EN CASO DE UNA MAYÚSCULA, SE CONVIERTA A MINÚSCULA.
{
	char salida;
	salida = 'a' + letra - 'A';
	return salida;
}

void imprimir(char cad[]) //FUNCIÓN PARA IMPRIMIR POR PANTALLA EL CÓDIGO MORSE 
{
  int i;
  for (i = 0; cad[i] != '\0'; i++)
  {
	  switch (cad[i])
	  {
	  case 'a':
	  {
		  printf(".-  ");
		  break;
	  }
	  case 'b':
	  {
		  printf("-...  ");
		  break;
	  }
	  case 'c':
	  {
		  printf("-.-.  ");
		  break;
	  }
	  case 'd':
	  {
		  printf("-..  ");
		  break;
	  }
	  case 'e':
	  {
		  printf(".  ");
		  break;
	  }
	  case 'f':
	  {
		  printf("..-.  ");
		  break;
	  }
	  case 'g':
	  {
		  printf("--.  ");
		  break;
	  }
	  case 'h':
	  {
		  printf("....  ");
		  break;
	  }
	  case 'i':
	  {
		  printf("..  ");
		  break;
	  }
	  case 'j':
	  {
		  printf(".---  ");
		  break;
	  }
	  case 'k':
	  {
		  printf("-.-  ");
		  break;
	  }
	  case 'l':
	  {
		  printf(".-..  ");
		  break;
	  }
	  case 'm':
	  {
		  printf("--  ");
		  break;
	  }
	  case 'n':
	  {
		  printf("-.  ");
		  break;
	  }
	  case 'o':
	  {
		  printf("---  ");
		  break;
	  }
	  case 'p':
	  {
		  printf(".--.  ");
		  break;
	  }
	  case 'q':
	  {
		  printf("--.-  ");
		  break;
	  }
	  case 'r':
	  {
		  printf(".-.  ");
		  break;
	  }
	  case 's':
	  {
		  printf("...  ");
		  break;
	  }
	  case 't':
	  {
		  printf("-  ");
		  break;
	  }
	  case 'u':
	  {
		  printf("..-  ");
		  break;
	  }
	  case 'v':
	  {
		  printf("...-  ");
		  break;
	  }
	  case 'w':
	  {
		  printf(".--  ");
		  break;
	  }
	  case 'x':
	  {
		  printf("-..-  ");
		  break;
	  }
	  case 'y':
	  {
		  printf("-.--  ");
		  break;
	  }
	  case 'z':
	  {
		  printf("--..  ");
		  break;
	  }
	  case '0':
	  {
		  printf("-----  ");
		  break;
	  }
	  case '1':
	  {
		  printf(".----  ");
		  break;
	  }
	  case '2':
	  {
		  printf("..---  ");
		  break;
	  }
	  case '3':
	  {
		  printf("...--  ");
		  break;
	  }
	  case '4':
	  {
		  printf("....-  ");
		  break;
	  }
	  case '5':
	  {
		  printf(".....  ");
		  break;
	  }
	  case '6':
	  {
		  printf("-....  ");
		  break;
	  }
	  case '7':
	  {
		  printf("--...  ");
		  break;
	  }
	  case '8':
	  {
		  printf("---..  ");
		  break;
	  }
	  case '9':
	  {
		  printf("----.");
		  break;
	  }
	  case '.':
	  {
		  printf(".-.-.-  ");
		  break;
	  }
	  case ',':
	  {
		  printf("--..--  ");
		  break;
	  }
	  case '?':
	  {
		  printf("..--..  ");
		  break;
	  }
	  case '"':
	  {
		  printf(".-..-.  ");
		  break;
	  }
	  case '!':
	  {
		  printf(".-.-.  ");
		  break;
	  }
	  case ' ':
	  {
		  printf(" ");
		  break;
	  }
	  }
  }
}

void autoConnect(SerialPort *arduino, char *incomingData)
{
	char sendData = 0;
	while (!isconnected(arduino)) //Espera la conexión con Arduino
	{
		Sleep(100);
		Crear_Conexion(arduino, arduino->portName);
	}
	if (isConnected(arduino)) //Comprueba si Arduino está conectado
		printf("Conectado con Arduino en el puerto %s\n", arduino->portName);
	printf("0 - LED OFF, 1 - LED ON, * - SALIR");
	while (isConnected(arduino) && sendData != '*') //Bucle de la aplicación
	{
		sendData = getch();
		writeSerialPort(arduino, &sendData, sizeof(char));
	}
	if (!isconnected(arduino))
		printf("Se ha perdido la conexion con Arduino.\n");
}
