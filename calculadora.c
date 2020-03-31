/*
Autor: geotoj
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
Compilado: gcc calculadora.c -o calculadora
Fecha: jue feb 13 10:11:05 CST 2020
Librerias: stdio
Resumen: Calcula dos numeros enteros ingresados, regresando de forma automatica 4 operaciones basicas 
Entrada:	Dos numeros enteros
Salida:	cuatro numeros enteros
*/

//Librerias
#include <stdio.h>

//1) inicia la funcion main como un entero
int main(){
//2) definir variables de entrada y de salida como enteros
int x,y,res;
//3) pedir los dos numeros enteros
printf("Bienvenido a mi calculadora de enteros, ingrese dos numeros enteros\n");
printf("Ingrese el primer valor: ");
scanf("%i",&x);
printf("Ingrese el segundo valor: ");
scanf("%i",&y);
//4) realizar las 4 operaciones basicas con enteros
res=x+y;
printf("La suma es %i, ",res);
res=x-y;
printf("la resta es %i, ",res);
res=x*y;
printf("el producto es %i, ",res);
res=x/y;
printf("la division es %i.\n",res);
}
