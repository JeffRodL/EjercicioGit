/* Autor: 
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
Fecha: mar mar 31 13:15:09 CST 2020
Resumen Programa que solicita una matrix de 3x3 y despliega los siguiente: suma, resta, multiplicación, transpuesta, inversa, determinante, reducción por Gauss y reducción por gauss jordan.
Entrada:Matriz de 3x3
Salida: numeros enteros o decimales.
*/
//librearias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define k
//numerar los pasos del pseudocodigo

int main(){

int c, i, j, m;
int matA[3][3]={{0}};
int matB[3][3]={{0}};
int multi[3][3]={{0}};
int suma, det;
int a=matA[0][0], b=matA[0][1], v=matA[0][2];
int d=matA[1][0], f=matA[1][1], g=matA[1][2];
int h=matA[2][0], n=matA[2][1], z=matA[2][2];


printf("\nA continuación se harán varios calculos de matrices.");

//creación de la matriz MatA.

for(i=0; i<3; i++){
	for(j=0; j<3;j++){
	printf("\nA continuación deberá colocar los datos que llevará su matriz en fila:%i \ny columna: %i\n",i+1,j+1);
	scanf("%i",&matA[i][j]);
	}
}


//creación de la matriz MatB

for(i=0; i<3; i++){
	for(j=0; j<3; j++){
	
		printf("\nA continuación deberá colocar los datos que llevará su segunda matriz en fila:%i \nY columna:%i\n",i+1,j+1);
		scanf("%i", &matB[i][j]);
	}
}


//Presentación de las matrices.



//Primera matriz
	printf("\n Primera matriz:\n");
	for(i=0;i<3;i++){
	printf("\n");
	for(j=0;j<3;j++){
		printf("%6i", matA[i][j]);
	}	
	}

//segunda matriz

	printf("\n Segunda matriz:\n");
	for(i=0;i<3;i++){
		printf("\n");
	
	for(j=0; j<3; j++){
		printf("%6i", matB[i][j]);
		}
	}


//multiplicación por una constante


printf("\nIngresar el valor de una constante para multiplicarla por las matrices:");
scanf("%i",&c);

printf("\nMultiplicación por constante\n");
for(i=0;i<3;i++){
	printf("\n");
	for(j=0; j<3; j++){
		printf("%6i", c*matA[i][j]);
	}
}


//suma de matrices

printf("\nSuma entre la matriz A y la matriz B\n");
for(i=0;i<3;i++){
	printf("\n");
	for(j=0;j<3;j++){
		printf("%6i",(matB[i][j]+matB[i][j]));
	}
}

//resta  de matrices.

printf("\nResta entre la matriz A y la matriz B");
for(i=0;i<3;i++){
        printf("\n");
        for(j=0;j<3;j++){
                printf("%6i",(matB[i][j]-matB[i][j]));
        }
}

//multiplicación de matrices (una tercera iteración para almacenar la suma de las multiplicaciones)

for(i=0; i<3; i++){
	printf("\n");
	for(j=0; j<3; j++){
		for(m=0; m<3; m++){
			suma += matA[j][m]*matB[m][i];
		}
		multi[j][i]=suma;
	}
}

//regresamos a las mismas iteraciones

printf("\nMultiplicación entre la matriz A y la matriz B");
for(i=0;i<3;i++){
	printf("\n");
	for(j=0; j<3; j++){
		printf("%6i", multi[i][j]);
	}
}



//Determinante de la primera matriz MatA
//se le asignan valores a cada elemento de una matriz de 3x3 para evitar complicaciones.



det=(a*((f*z-(g*n))))-(b*(d*z-g*h))+(v*(d*n-f*h));

printf("\n \t La determinante de la matriz a es: %i\n", det);

//Transpuesta de la matriz MatB. 
//así como en la vida real la transpuesta es una traslación de componentes, acá se hace lo mismo.

printf("\nTranspuesta de la segunda matriz MatB");
for(i=0;i<3;i++){
	printf("\n");
	for(j=0;j<3;j++){
	printf("%6i", matB[j][i]);
	}
}

//Inversa de la matriz MatA
//Es necesario encontrar la adjunta para encontrar la inversa

printf("Inversa de la primera matriz A\n");

for(i=0; i<3; i++);{
	printf("\n");
	for(j=0;j<3; j++){
	printf("%6i",((matA[(j+1)%3][(i+1)%3]*matA[(j+2)][(i+2)%3])-(matA[(j+1)%3][(i+2)%3]*matA[(j+2)%3][(i+1)%3]))/det); 
	}
}






}
