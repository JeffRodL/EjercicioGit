
/* Autor: 
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
Fecha: lun mar 30 22:04:16 CST 2020
Resumen Encontrar el factorial de un número entero.
Entrada:Numero entero
Salida: función recursiva
*/
//librearias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//numerar los pasos del pseudocodigo


long int factorial(int);
long int main()
{

	int numero, fact;
		
		//pedir al usuario que ingrese un número.
		printf("\nIngresar un número entero:");
		scanf("%d", &numero);

		//Llamando a nuestra función definida por el usuario.
		fact = factorial(numero);

		
		//Mostrar el factorial del número ingresado.
		printf("\nEl factorial es: %d!= %d\n", numero, fact);
		return 0;
}

long int factorial(int n)
{
	if(n==0) //Recordando que el factorial de 0 es 1 
	return(1);

	//Nuestra función de recursión.
	return(n*factorial(n-1));
}
