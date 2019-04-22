#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

void imprimir(char *); //FUNCIÓN PARA IMPRIMIR POR PANTALLA EL CODIGO MORSE 
char menu(); // FUNCIÓN PARA IMPLEMENTAR SI ES UN MENSAJE DE SOCORRO O NO.
void mensaje (char []); //FUNCIÓN PARA INTRODUCIR EL MENSAJE 
char mayusculas(char); // FUNCION PARA QUE , EN CASO DE UNA MAYUSCULA SE CONVIERTA A MINUSCULA.
int simbolo_ok (char );

int main()
{
	char cad[N];
	char opcion;
	
	do {
		opcion=menu();
		switch (opcion)
		{
			case 'a': mensaje(cad);// Instrucciones asociadas
			          printf("Se enciende un LED rojo.\n");
                      imprimir (cad);
					  break;
			case 'b': mensaje(cad);// Instrucciones asociadas
			          printf("Se enciende un LED verde.\n");
                      imprimir (cad);
					  break;
		}
		
	} while (opcion != '*');
	system("pause");
}

char menu()
{
  char opcion;
  do 
  {
	printf("Indique el motivo de su mensaje.");
    printf (" Pulse la letra a si es un mensaje de alerta o socorro,\n");
    printf(" o la letra b si es cualquier otro tipo de mensaje:\n ");
	printf("\nSi desea salir del programa introduzca '*': ");
	scanf("%c",&opcion); //scanf_s("%c", &opcion);
    fflush(stdin);

    if (opcion!='*' && opcion!='a' && opcion!='b')
	  printf("Ha marcado una letra incorrecta");

  } while (opcion!='*' && opcion!='a' && opcion!='b');
  
  return (opcion);
}


void mensaje (char c[])
{
  int i,resultado;

  do
  {
    printf("Introduzca su mensaje"); 
    printf (" Puedes introducir numeros, espacios, comas, !, ?, "" y puntos si lo desea: ");
    gets(c); // gets_s(c);
  
    resultado=1; 
    for (i=0;c[i]!='\0';i++)
      if (simbolo_ok(c[i]) == 0)
        resultado=0;
      else
         if (c[i]>='A' && c[i]<='Z')
             c[i]=mayusculas(c[i]);
    if (resultado==0)
      printf("Algun caracter de los que ha introducido no es correcto.\n");

  } while (resultado==0);
}


int simbolo_ok (char c)
{
  int resultado=0;  // Considero por defecto que no es válido
  if (c>='A' && c<='Z')
      resultado=1;
  else
    if (c>='a' && c<='z')
       resultado=1;
    else
      if (c>='0' && c<='9')
        resultado=1;
      else
         if (c=='.' || c==',' || c=='?' || c=='"' || c=='!')
           resultado=1;

   return resultado;
}

char mayusculas(char letra)
{
	char salida;
	salida= 'a'+ letra-'A';
	return salida;
	
}


void imprimir(char cad[] )
{
  int i;

 	for (i=0;cad[i]!='\0';i++)
	{
		switch (cad[i]) {
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
