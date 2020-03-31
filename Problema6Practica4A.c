
/* Autor: 
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
Fecha: lun mar 30 23:52:04 CST 2020
Resumen Se calcula la sumatoria del inciso A.
Entrada:numero entero
Salida: numero entero
*/
//librearias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//numerar los pasos del pseudocodigo

float suma1(float);
int main(){

	float n;
	
	printf("\nIngrese un valor hasta donde quiere su sumatoria:");
	scanf("%f", &n);
	
	if(n <= 0){
		while( n<=0){
		printf("\nIngrese un valor aceptado que sea positivo:");
		scanf("%f", &n);}
		if(n>0){
		printf("\nEl resultado de la sumatoria es: %.2f \n", suma1(n));
		}

	}else{

	printf("\nEl resultado de la sumatoria es: %.2f \n", suma1(n));
	}

	

	return 0;	
}

float suma1(float x){
	if(x == 1){
		x = -2;
	} 
	else{
		x = (suma1(x-1)+(x*x*(x-3)));
	}

return x;
}
