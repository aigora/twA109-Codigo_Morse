#include <stdio.h>
#include<windows.h>

/*Hacer un programa que imprima los números enteros de A a B, contando de m en m. Los
valores de A y B serán asignados dentro del programa en código, mediante la inicialización de
las variables en su declaración. Por ejemplo, A=8 y B=19. El valor de m será introducido por el
usuario desde el teclado. Si el usuario introduce un valor de m menor que 1, el programa se lo
volverá a pedir de forma reiterada hasta que el usuario introduzca un número mayor o igual
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
