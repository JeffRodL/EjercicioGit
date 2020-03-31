/*
Autor:	Maynor Ballina
Compilador:	gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
Compilado:	gcc holamundo.c -o holamundo
fecha:	11-02-2020
librerias:	stdio
Resumen:	El programa al ejecutarse imprimira frase Hola Mundo.
*/

//incluye librerias
#include <stdio.h>
//1	inicia la funcion main como un entero
int main(){
//2	se utiliza la funcion printf agregando \n para agregar un final de carrera
	printf("Hola Mundo\n");
//3	se agrega la bandera de retorno 0 para definir que el programa corrio bien
	return 0;
}
