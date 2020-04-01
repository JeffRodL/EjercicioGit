/* Autor: 
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
Fecha: mar mar 31 11:19:57 CST 2020
Resumen Programa que contiene un vector de 10 elementos con números pares del 1 al 20 y se pregunta cómo se quieren mostrar si de forma ascendente "a" o forma descendente "d".
Entrada:letra "a" o "d"
Salida: vectores ordenados de manera ascendente o descendente.
*/
//librearias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//numerar los pasos del pseudocodigo


int main(){
	
	//Declaración de Variables a utilizar.
	int vector[10]={2,4,6,8,10,12,14,16,18,20};
	int i, j, k;
	char x;

	printf("\nA continuación se mostrará un programa que ordenará un vector de 10 elementos con números pares del 1-20. Elegir si los quiere ver de forma ascendente (a) o forma descendente (d) \n¿ascendente o descendente?");
	
	scanf("%c", &x); //recogemos el valor que ingresa el usuario.
	
	//Por si el usuario se pasa de listo y agrega un valor incorrecto.
	while( x !='a' && x!='d'){
	
	printf("\nNo se continuará con el programa hasta que ingrese un valor vvalido. \n¿ascendente (a) o descendente (d)?");
	scanf("%c",&x);
	} 
	//Si el usuario hace lo correcto, el programa seguirá trabajando. Se ordena para forma descendente si el valor
	//ingresado es a 
	if(x=='a'){
		printf("\nForma ascendente:\n");
			for(i=0; i<=9; i++){
			for(j=i+1; j<=9; j++){
				if(vector[i]>vector[j]){
				
					x=vector[i];
					vector[i]=vector[j];
					vector[j]=x;	
				}
			}
		}
		//Y se imprime el resultado dentro de un for, para que muestre para cada vector.
		for(i=0; i<=9; i++){
			printf("%i\n", vector[i]);
		}
	}
		//Lo mismo si el valor ingresado es una d, solamente que aquí se mostrará en forma descendente.
	if(x == 'd'){
		printf("\nForma descendente:\n");
		for(i=0; i<9; i++){
		
			for(j=i+1; j<=9; j++){
					
			if( vector[i]<vector[j]){
			x = vector[i];
			vector[i] = vector[j];
			vector[j] = x;
				

			}
		}
	}
	//así mismo se vuelve a imprimir dentro de un for para dar un valor a cada vector.
	for(i=0; i<=9; i++){
		printf("\n%i",vector[i]);
	}
	}
	
	return 0;

}
