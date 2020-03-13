/* Autor: 
//Compilador: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
//Fecha: jue mar 12 19:54:23 CST 2020
//Resumen se digita un numero y se dice si este es primo o no.
//Entrada:int
//Salida: res
*/

//librearias
#include <stdio.h>
//numerar los pasos del pseudocodigo

int main()
{

	int primo=0,i,n; 				//Vamos a establecer nuestras variables. La variable primo esta igualada a 0 lo que indica donde empieza.
					
	
	printf("ingrese un numero\n");			//Pedimos al usuario que ingrese algun valor cualquiera.
	scanf("%d", &n);				//Y la maquina lo recibe.
	
	
	for (i=1;i<(n+1); i++){				//utilizamos la funcion for comenzando desde 1, la cual sera menor a n+1, la cual luego se le incrementa 1. 
		if(n%i==0){				//nos preguntamos si el residuo entre ellos es 0.
			primo++;			//entonces incrementar la variable primo.
		}
	}

	if(primo!=2){					//si la variable primo (ya nuestro resultado anterior) es igual a 2 entonces	
		printf("Su numero no es primo\n");	//Decir que nuestro numero no es primo
	}else{						//De lo contrario
		printf("Su numero si es primo\n");	//Decir que si es primo
	}

	return 0;
}
	
