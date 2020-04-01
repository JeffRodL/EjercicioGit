
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

//al igual que con la anterior, se trabajan con funciones recursivas tomando siempre un caso base.
float suma2(float);
int main(){
	//Variable que digitará el usuario de hasta dónde quiere su sumatoria.
        float n;

        printf("\nIngrese un valor hasta donde quiere su sumatoria:");
        scanf("%f", &n);

	//Puede existir el caso que el usuario intente agregar un número invalido por eso agregamos este ciclo
	//while que le dirá que debe ingresar un número aceptable.
        if(n <= 1){
                while( n<=1){
                printf("\nIngrese un valor aceptado que sea positivo:");
                scanf("%f", &n);}
                if(n>1){
                printf("\nEl resultado de la sumatoria es: %.2f \n", suma2(n));
                }

        }else{
	//si el usuario agrega un valor acepdato, la máquina imprimirá el resultado
        printf("\nEl resultado de la sumatoria es: %.2f \n", suma2(n));
        }



        return 0;
}
//Función de recursión con el valor inicial para poder determinar los siguientes.
float suma2(float x){
        if(x == 2){
                x = 3;
        }
        else{
                x = (suma2(x-1)+(3/(x-1)));
        	
	}

return x;
}          
