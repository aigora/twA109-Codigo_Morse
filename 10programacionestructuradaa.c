#include <stdio.h>
#include<windows.h>

/*Hacer un programa que imprima los n�meros enteros de A a B, contando de m en m. Los
valores de A y B ser�n asignados dentro del programa en c�digo, mediante la inicializaci�n de
las variables en su declaraci�n. Por ejemplo, A=8 y B=19. El valor de m ser� introducido por el
usuario desde el teclado. Si el usuario introduce un valor de m menor que 1, el programa se lo
volver� a pedir de forma reiterada hasta que el usuario introduzca un n�mero mayor o igual
que 1. */

int main() 
{
	int A=1, B=17;
	int i,m,n=0;
	do
	{
	printf("Usuario introduzca un valor:\n");
	scanf("%d",&m);	
	}
	while(m<1);
	for(i=m;i<=B;i++)
	{
		n=n+m;
		if(n<=B)
		printf("%d\n",n);
	}
	

	system("pause");
	
}
