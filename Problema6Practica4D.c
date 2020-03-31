
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

float suma4(float);
int main(){

        float n;

        printf("\nIngrese un valor hasta donde quiere su sumatoria:");
        scanf("%f", &n);

        if(n <= 1){
                while( n<=1){
                printf("\nIngrese un valor aceptado que sea positivo:");
                scanf("%f", &n);}
                if(n>1){
                printf("\nEl resultado de la sumatoria es: %.2f \n", suma4(n));
                }

        }else{

        printf("\nEl resultado de la sumatoria es: %.2f \n", suma4(n));
        }



        return 0;
}

float suma4(float x){
        if(x == 2){
                x = 0.70;
        }
        else{
                x = (suma4(x-1)+(0.1*(3*pow(2,(x-2))+4)));
        }

return x;
}          
