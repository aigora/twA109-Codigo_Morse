#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SerialPort.h"

#define N 100
#define MAX_DATA_LENGTH 255

typedef struct // Esta estructura almacenar� la correspondencia entre s�mbolos y secuencias de puntos y rayas.
{
  char simbolo;
  char secuencia[10];
} CMorse;


char menu(); //FUNCI�N PARA DISTINGUIR SI ES UN MENSAJE DE SOCORRO O NO.
void mensaje(char []); //FUNCI�N PARA INTRODUCIR EL MENSAJE 
char mayusculas(char); //FUNCION PARA QUE, EN CASO DE UNA MAY�SCULA, SE CONVIERTA A MIN�SCULA.
int simbolo_ok(char); //FUNCI�N PARA DESCARTAR TODOS LOS CARACTERES QUE NO SEAN V�LIDOS DENTRO DE LA SELECCI�N
void imprimir(char *); //FUNCI�N PARA IMPRIMIR POR PANTALLA EL C�DIGO MORSE

void enviar_mensaje (SerialPort *,char [],int,CMorse [] ,int );  // Prepara un mensaje para ser enviado a Arduino
void enviar_arduino (SerialPort *,char []); // Env�a una cadena de puntos y rayas a Arduino

int load_tabla(CMorse []);  // Carga la tabla de correspondencias

int main()
{
    CMorse Tabla[45];  // Tabla de correspondencias.
    int total=0;
	char cad[N];
	char opcion;
    //Arduino SerialPort object
    SerialPort *arduino;
    // Puerto serie en el que est� Arduino
    char* portName = "\\\\.\\COM3";
    // Buffer para datos procedentes de Arduino
    char incomingData[MAX_DATA_LENGTH];
  
    // Crear estructura de datos del puerto serie
    arduino = (SerialPort *)malloc(sizeof(SerialPort));
    // Apertura del puerto serie
    Crear_Conexion(arduino,portName);

    total = load_tabla(Tabla); // Carga la tabla de conversi�n desde un fichero y devuelve el n�mero de pares.
    
	do {
		opcion = menu();
		switch (opcion)
		{
			case 'a': mensaje(cad); //Instrucciones asociadas
			          printf("Se enciende un LED rojo.\n");
                      //imprimir(cad); //enviar los datos a arduino.
                      enviar_mensaje(arduino,cad,1,Tabla,total); // Enviamos la cadena a Arduino indicando que es un mensaje normal
					  break;
			case 'b': mensaje(cad); //Instrucciones asociadas
			          printf("Se enciende un LED verde.\n");
                      //imprimir(cad);
                      enviar_mensaje(arduino,cad,0,Tabla,total); // Enviamos la cadena a Arduino indicando que es un mensaje normal
					  break;
		}
	} while (opcion != '*');
	
	system("pause");
	return 0;
}

char menu() //FUNCI�N PARA DISTINGUIR SI ES UN MENSAJE DE SOCORRO O NO.
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

void mensaje (char c[]) //FUNCI�N PARA INTRODUCIR EL MENSAJE
{
  int i, resultado;
  do
  {
    printf("Introduzca su mensaje (puede introducir numeros, espacios, comas, exclamaciones, interrogaciones, comillas o puntos si lo desea): ");
    gets(c); // gets_s(c);
	resultado = 1; //Doy por hecho que todos los caracteres son correctos, que es lo m�s l�gico
	for (i = 0; c[i] != '\0'; i++)
	{
		if (simbolo_ok(c[i]) == 0) //Descarto qu� s�mbolos no son v�lidos, lo comparo con mi selecci�n
			resultado = 0;
		else
		{
			if (c[i] >= 'A' && c[i] <= 'Z')
				c[i] = mayusculas(c[i]); //Llamo a la funci�n para pasar cualquier may�scula que haya a min�sculas
		}			
	}
    if (resultado == 0)
      printf("Algun caracter de los que ha introducido no es correcto.\n");
  } while (resultado == 0); //Se repite el bucle hasta que todos los caracteres sean correctos
}

int simbolo_ok(char c) //FUNCI�N PARA DESCARTAR TODOS LOS CARACTERES QUE NO SEAN V�LIDOS DENTRO DE LA SELECCI�N
{
	int resultado = 0;  //Considero por defecto que no es v�lido
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

char mayusculas(char letra) //FUNCION PARA QUE, EN CASO DE UNA MAY�SCULA, SE CONVIERTA A MIN�SCULA.
{
	char salida;
	salida = 'a' + letra - 'A';
	return salida;
}


void enviar_mensaje (SerialPort *arduino,char cadena[],int tipo,CMorse Tabla[],int n)
{
  int i,j;
  for (i=0;cadena[i]!='\0';i++)  // Recorremos cada letra del mensaje
  {
     for (j=0;j<n;j++)   // Buscamos en la tabla su correspondencia
      if (cadena[i]==Tabla[i].simbolo)
         enviar_arduino (arduino,Tabla[i].secuencia);
  }
}

void enviar_arduino (SerialPort *arduino,char secuencia[])
{
   int i;
   while (!isConnected(arduino)) //Espera la conexi�n con Arduino
   {
    	printf ("Intentando conectar con Arduino\n");
        Sleep(100);
		Crear_Conexion(arduino, arduino->portName);
	}
	for (i=0; secuencia[i]!='\0' && isConnected(arduino); i++)  //Bucle del env�o
		writeSerialPort(arduino, &secuencia[i], sizeof(char)); 
}

// ESTA FUNCI�N DEBE LEER UN FICHERO DE TEXTO Y ASOCIAR A CADA S�mbolo su secuencia
int load_tabla(CMorse tabla [])
{
  int i;
  char letra;
  FILE *entrada;
  entrada = fopen("AlfabetoMorse.txt","r");
  if (entrada==NULL)
  	  printf("No se ha podido crear el fichero.\n");
  else
  {
  	  for (i=0; i<41; i++)
  	  {
  	  	fscanf(entrada, "%c", &tabla[i].simbolo);
  	  	fscanf(entrada, "%s", &tabla[i].secuencia); //Para leer la secuencia
  	  	strcpy(tabla[i].secuencia,*tabla[i].secuencia); //Tendr�amos que copiar lo escaneado en la l�nea 171
  	  	fscanf(entrada, "%c", &letra); //Para leer salto de l�nea  	  	
	  }
	  fclose(entrada);
  }
  //tabla[0].simbolo='a';
  //strcpy (tabla[0].secuencia,".-.-");
  return 1;
}

/*void imprimir(char cad[]) //FUNCI�N PARA IMPRIMIR POR PANTALLA EL C�DIGO MORSE 
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
}*/


