/*
Autor: jefferson
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
Compilado: gcc operadores.c -o operadores
Fecha: mar mar 3 09:12:15 CST 2020
Librerias: stdio, otras librerias
Resumen: tipos de operadores
Entrada:  varios variables
Salida:  varios variables
*/

//Incluir librerias
#include <stdio.h>
//Declarar variables globales

//numerar los pasos del pseudocodigo
//Incluir variables
#include<stdio.h>
//declarar variables globales
int main(){
	int x,y,res;
x=2;
y=4;

x += y;

printf("resultado suma %d, %d \n",x,y);
x -= y;
printf("resultado resta %d, %d \n",x,y);
x *= y;
printf("resultado multiplicaciòn %d, %d \n",x,y);
x /= y;
printf("resultado divisiòn %d, %d \n",x,y);
x %= y;
printf("resultado residuo %d, %d \n",x,y);
res = x+=y;
printf("resultado %d, %d, %d \n",res,x,y);
return 0;
}
