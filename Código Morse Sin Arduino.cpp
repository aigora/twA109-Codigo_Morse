#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

char menu(); //FUNCIÓN PARA DISTINGUIR SI ES UN MENSAJE DE SOCORRO O NO.
void mensaje(char[]); //FUNCIÓN PARA INTRODUCIR EL MENSAJE 
char mayusculas(char); //FUNCION PARA QUE, EN CASO DE UNA MAYÚSCULA, SE CONVIERTA A MINÚSCULA.
int simbolo_ok(char); //FUNCIÓN PARA DESCARTAR TODOS LOS CARACTERES QUE NO SEAN VÁLIDOS DENTRO DE LA SELECCIÓN
void imprimir(char[]); //FUNCIÓN PARA IMPRIMIR POR PANTALLA EL CÓDIGO MORSE 

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
				imprimir(cad);
				break;
		case 'b': mensaje(cad); //Instrucciones asociadas
				printf("Se enciende un LED verde.\n");
				imprimir(cad);
				break;
		}
	} while (opcion != '*');
	system("pause");
}

char menu() //FUNCIÓN PARA DISTINGUIR SI ES UN MENSAJE DE SOCORRO O NO.
{
	char opcion;
	do
	{
		printf("Indique el motivo de su mensaje.\n");
		printf("Pulse la letra 'a' si es un mensaje de alerta o socorro o la letra 'b' si es cualquier otro tipo de mensaje.\n");
		printf("\nSi desea salir del programa introduzca '*': ");
		scanf("%c", &opcion); //scanf_s("%c", &opcion);
		fflush(stdin);
		if (opcion != '*' && opcion != 'a' && opcion != 'b')
			printf("Ha marcado una letra incorrecta");
	} while (opcion != '*' && opcion != 'a' && opcion != 'b');
	return (opcion);
}

void mensaje(char c[]) //FUNCIÓN PARA INTRODUCIR EL MENSAJE
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