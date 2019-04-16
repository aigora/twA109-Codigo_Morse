#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

void imprimir(char *); //FUNCI�N PARA IMPRIMIR POR PANTALLA EL CODIGO MORSE 
int menu(void); // FUNCI�N PARA IMPLEMENTAR SI ES UN MENSAJE DE SOCORRO O NO.
int mensaje(void); //FUNCI�N PARA INTRODUCIR EL MENSAJE 
char mayusculas(char); // FUNCION PARA QUE , EN CASO DE UNA MAYUSCULA SE CONVIERTA A MINUSCULA.

int main()
{
	char cad[N], *pcad, minus;
	pcad = cad;
	char opcion,letra;
	opcion=menu(void);
	do {
		while (opcion != 'a' || opcion != 'b')
		{
			printf("Ha marcado una letra incorrecta");
			opcion=menu(void);//Llamar a funci�n de men� de nuevo para pedir la opci�n.
		}
		if (opcion == 'a')
		{
			cad[N]=mensaje(void);
			while (*pcad = '\0')
			{
				if (*pcad < 33  || (*pcad > 34 && *pcad < 44) || (*pcad > 44 && *pcad < 48) || (*pcad > 57 && *pcad < 63) || (*pcad > 63 && *pcad <65) || *pcad > 122)
				{
					printf("Algun caracter de los que ha introducido no es correcto.\n");
					cad[N]=mensaje(void); // hay algun caracter incorrecto , llama a la funci�n para introducir el mensaje otra vez 
				}
				else if(*pcad>64 && *pcad<91) //para pasar de mayusculas a minusculas 
				{
					minus=mayusculas(letra); // llamada a la funcion
					imprimir(&cad); // imprimir la letra en minuscula  
				}
				pcad++;
			}
		
			printf("Se enciende un LED rojo.\n");
			imprimir(&cad); // imprimir en codigo morse . Llamada a la funci�n imprimir.
		}
		else if (opcion == 'b')
		{
			cad=mensaje(void);
			while (*pcad = '\0')
			{
				if (*pcad < 33  || (*pcad > 34 && *pcad < 44) || (*pcad > 44 && *pcad < 48) || (*pcad > 57 && *pcad < 63) || (*pcad > 63 && *pcad < 97) || *pcad > 122)
				{
					printf("Algun caracter de los que ha introducido no es correcto.\n");
					cad[N]=mensaje(void); // hay algun caracter incorrecto , llama a la funcion otra vez 
				}
				pcad++;
			}
			
			printf("Se enciende un LED verde.\n");
			imprimir(&cad);
		}
		printf("\n");
		opcion=menu(void);//Llamar a funci�n de men� de nuevo para pedir la letra.
		
	} while (opcion != '*');
	system("pause");
}

char menu(void)
{
	int opcion;
	printf("Indique el motivo de su mensaje. Pulse la letra a si es un mensaje de alerta o socorro, o la letra b si es cualquier otro tipo de mensaje: ");
	printf("\nSi desea salir del programa introduzca '*' ");
	scanf_s("%c", &opcion);
	return (opcion);
}
char mensaje(void)
{
	char cad[N];
	printf("Introduzca su mensaje (todo en minusculas). Puedes introducir numeros, espacios, comas, ?, "" y puntos si lo desea: ");
	gets_s(cad);
	return (cad[N]);
}
char mayusculas(char letra)
{
	char salida;
	salida= 'a'+ letra-'A';
	return salida;
	
}


void imprimir(char *cad )
{
	char *pcad;
	pcad = cad;
	while (*pcad != '\0') //�mejor cada letra con printf, o asignando la codificaci�n Morse a cada letra para luego imprimirlo en un puts?
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
