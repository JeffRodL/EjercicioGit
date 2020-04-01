
/* Autor: 
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
Fecha: lun mar 30 20:21:54 CST 2020
Resumen Se ingresan dos vectores en R3 y se da el resultado de la magnitud de ellos, el producto escalar, vectorial  y suma.
Entrada:Numeros enteros o decimales.
Salida: Numeros enteros o decimales.
*/
//librearias
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//numerar los pasos del pseudocodigo

float main(){

	//Declaración de variables de caracter flotante, esto nos permite trabajar en los decimales.
	float vector1[3];
	float vector2[3];
	
	//Pedimos al usuario ingresar los valores de cada componente de los dos vectores y son almacenados en un vector.
	printf("\n A continuación se le solicitará ingresar 2 vectores en R3 para calcular su magnitud, suma, producto escalar y vectorial de estos. \nIngresar valor de la coordenada en x para el primer vector:");
	scanf("%f", &vector1[0]);
	printf("\nIngresar valor de la coordenada y para el primer vector. y1:");
	scanf("%f", &vector1[1]);
	printf("\nIngresar valor de la coordenada z para el primer vector. z1:");
        scanf("%f", &vector1[2]);
	printf("\nIngresar valor de la coordenada x para el segundo vector. x2:");
        scanf("%f", &vector2[0]);
	printf("\nIngresar valor de la coordenada x para el segundo vector. y2:");
        scanf("%f", &vector2[1]);
	printf("\nIngresar valor de la coordenada y para el segundo vector. z2:");
        scanf("%f", &vector2[2]);

	//definimos las siguientes funciones para la magnitud.
	float mag1 = sqrt((vector1[0]*vector1[0])+(vector1[1]*vector1[1])+(vector1[2]*vector1[2]));
	float mag2 = sqrt((vector2[0]*vector2[0])+(vector2[1]*vector2[1])+(vector2[2]*vector2[2]));
	//Suma de los vectores
	float suma1 = (vector1[0]+vector2[0]);
	float suma2 = (vector1[1]+vector2[1]);
	float suma3 = (vector1[2]+vector2[2]);
	
	//Producto escalar entre los vectores.
	float ps = ((vector1[0]*vector2[0]) + (vector1[1]*vector2[1]) + (vector1[2]*vector2[2]));
	
	//Funciones para el producto vectorial entre ellos. Al ser en R3 esto siempre funcionará.
	float pvx = ((vector1[1]*vector2[2])-(vector2[1]*vector1[2]));
	float pvy = ((vector1[0]*vector2[2])-(vector2[0]*vector1[2]));
	float pvz = ((vector1[0]*vector2[1])-(vector2[1]*vector1[1]));

	//Imprimimos el resultado.
	printf("\nLa magnitud del primer vector es:%f", mag1);
	printf("\nLa magnitud del segundo vector es:%f", mag2);
	printf("\nLa suma del primer con el segundo vector es:(%f,%f,%f)", suma1, suma2, suma3);
	printf("\nEl producto escalar entre los dos vectores es:%f", ps);
	printf("\nEl producto vectorial entre los dos vectores es:(%f,%f,%f) \n", pvx, pvy, pvz);





return 0;
}
