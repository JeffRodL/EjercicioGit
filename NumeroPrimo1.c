
/* Autor: 
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
Fecha: jue mar 12 18:53:27 CST 2020
Resumen Programa que corrobora si el número ingresado es primo o no.
Entrada:primo
Salida: res
*/
//librearias
#include <stdio.h>
//numerar los pasos del pseudocodigo

#include<stdio.h>

int main(){
	int primo,i,a;
	a=0;

printf("Introduzca un número el cual será corroborado si es primo o no: .\n");
scanf("%d", &primo);

for( i=1; i<=primo; i++)
{
	if(primo%i==0)
		a++;
}


if(a==2);
{
{
printf("El número es primo .\n");
}else{
printf("El número no es primo .\n");
}
}
}


