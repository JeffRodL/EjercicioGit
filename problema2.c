/* Autor: 
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
Fecha: vie mar 27 20:02:51 CST 2020
Resumen Se pide al usuario ingresar 5 números los cuales serán ordenados de mandentes.
Entrada:Numeros enteros.
Salida: Numeros enteros.
*/
//librearias
#include <stdio.h>
//numerar los pasos del pseudocodigo
//
//
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int x,cont,z,i,tabla[100];

	i=0;

	for(x=1, x<=100; x++)
	{ 
		cont=0;
		for (z=1; z<=x; z++)
		{
			if(x%z==0)
			{ 
				cont++;
			}
		}

		if(cont==2 ||z==1||z==0)
		{
			tabla[i]=x;
			i++;
		}
	}

	for(x=0; x<i; x++)
	{
		printf("%d\n",tabla[x]);
	}

	return 0;
}	
