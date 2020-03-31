
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

float suma2(float);
int main(){

        float n;

        printf("\nIngrese un valor hasta donde quiere su sumatoria:");
        scanf("%f", &n);

        if(n <= 1){
                while( n<=1){
                printf("\nIngrese un valor aceptado que sea positivo:");
                scanf("%f", &n);}
                if(n>1){
                printf("\nEl resultado de la sumatoria es: %.2f \n", suma2(n));
                }

        }else{

        printf("\nEl resultado de la sumatoria es: %.2f \n", suma2(n));
        }



        return 0;
}

float suma2(float x){
        if(x == 2){
                x = 3;
        }
        else{
                x = (suma2(x-1)+(3/(x-1)));
        	
	}

return x;
}          
