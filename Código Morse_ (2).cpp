#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

void imprimir(char *); //ojo
int menu(void);
int mensaje(void);
char mayusculas(char);

int main()
{
	char cad[N], *pcad, minus;
	pcad = cad;
	char opcion;
	opcion=menu(void);
	do {
		while (opcion != 'a' || opcion != 'b')
		{
			printf("Ha marcado una letra incorrecta");
			opcion=menu(void);//Llamar a función de menú de nuevo para pedir la letra.
		}
		if (opcion == 'a')
		{
			cad=mensaje(void);
			while (*pcad = '\0')
			{
				if (*pcad < 33  || (*pcad > 34 && *pcad < 44) || (*pcad > 44 && *pcad < 48) || (*pcad > 57 && *pcad < 63) || (*pcad > 63 && *pcad <65) || *pcad > 122)
				{
					printf("Algun caracter de los que ha introducido no es correcto.\n");
					cad=mensaje(void); // hay algun caracter incorrecto , llama a la funcion otra vez 
				}
				else if(*pcad>64 && *pcad<91) //para pasar de mayusculas a minusculas 
				{
					minus=mayusculas(cad);
				}
				pcad++;
			}
		
			printf("Se enciende un LED rojo.\n");
			imprimir(&cad); // imprimir en codigo morse . Llamada a la función imprimir.
		}
		else if (opcion == 'b')
		{
			cad=mensaje(void);
			while (*pcad = '\0')
			{
				if (*pcad < 33  || (*pcad > 34 && *pcad < 44) || (*pcad > 44 && *pcad < 48) || (*pcad > 57 && *pcad < 63) || (*pcad > 63 && *pcad < 97) || *pcad > 122)
				{
					printf("Algun caracter de los que ha introducido no es correcto.\n");
					cad=mensaje(void); // hay algun caracter incorrecto , llama a la funcion otra vez 
				}
				pcad++;
			}
			
			printf("Se enciende un LED verde.\n");
			imprimir(&cad);
		}
		printf("\n");
		opcion=menu(void);//Llamar a función de menú de nuevo para pedir la letra.
		
	} while (opcion != '*');
	system("pause");
}

int menu(void)
{
	int opcion;
	printf("Indique el motivo de su mensaje. Pulse la letra a si es un mensaje de alerta o socorro, o la letra b si es cualquier otro tipo de mensaje: ");
	printf("\nSi desea salir del programa introduzca '*' ");
	scanf_s("%c", &opcion);
	return (opcion);
}
int mensaje(void)
{
	char cad;
	printf("Introduzca su mensaje (todo en minusculas). Puedes introducir numeros, espacios, comas, ?, "" y puntos si lo desea: ");
	gets_s(cad);
	return cad;
}
char mayusculas(char letra)
{
	char a;
	a=letra+32;
	return a;
	
}


void imprimir(char *cad )
{
	char *pcad;
	pcad = cad;
	while (*pcad != '\0') //¿mejor cada letra con printf, o asignando la codificación Morse a cada letra para luego imprimirlo en un puts?
	{
		switch (*pcad) {
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
		}
	}
}
