/* Autor: 
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
Fecha: lun mar 30 17:58:05 CST 2020
Resumen Programa que pide 5 números enteros y muestra de forma ascendente estos números.
Entrada:5 números enteros.
Salida: 5 números enteros ordenados de forma ascendente.
*/
//librearias
#include <stdio.h>
#include <stdlib.h>
//numerar los pasos del pseudocodigo

int main()
{
	//Declaramos las variables. El vector es de 5 elementos. i,j se utilizan para el ordenamiento y la variable
	//aux sirve para guardar temporalmente información de los vectores.
	int vector[5];
	int i, j, k, aux;


	//Pedimos que sean ingresados los 5 valores.
	printf("\nA Continuación se le pedirá ingresar el valor de 5 números que serán ordenados de menor a mayor \n Introducir primer número:");
	scanf("%i", &vector[0]);
        printf("\nIntroducir segundo número:");
	scanf("%i", &vector[1]);
	printf("\nIntroducir tercer número:");
	scanf("%i", &vector[2]);	
        printf("\nIntroducir cuarto número:"); 
        scanf("%i", &vector[3]);
        printf("\nIntroducir quinto número:");   
        scanf("%i", &vector[4]);

	
	//Lo que queremos es que los vectores se vayan ordenando uno por uno. Esto lo hacemos por medio de comparación del
	//vector j con el vector j+1. Si j es mayor que j+1 se les ordena cambiar. Así hasta tenerlos ordenanos de manera ascendente.
	for (i = 0; i < 5; ++i)
	{
		for (j = 0; j < 5; ++j)
		{

			if( vector[j] > vector[j+1])
			{
				aux = vector[j];
				vector[j] = vector[j+1];
				vector[j+1] = aux;

			}
		}
	}

	//imprimimos en un cliclo for para cada uno de los vectores.
	for( k = 0; k < 5; ++k)
	{
	 printf("%i\n", vector[k]);
	}


	return 0;

}
