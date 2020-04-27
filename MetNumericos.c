/* Autor: Jefferson Rodríguez León
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
Fecha: sab abr 25 20:43:37 CST 2020
Resumen Programa que encuentra la función más cercana a base de datos recolectados experimentalmente.
Entrada:
Salida: 
*/
//librearias
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
//numerar los pasos del pseudocodigo

//La información recolectada de manera experimental será grabada en dos arrays
float vel[6]={1, 3, 8, 11, 14, 18};
float time[6]={2.1, 3.0, 5.2, 7.1, 9.2, 10.1};

//Las formulas a ocupar para el método de minimos cuadrados
float sx, sy, sxy, sxx;

//Variables para las funciones a utilizar en la aceleración y la velocidad inicial.
float ac, velocidad0;

//Funciones que vamos a utilizar: Velocidad inicial llamada vo (la intersección con el eje x), 
//Aceleracion llamada a (la pendiente) y las incertezas para el la velocidad inicial y la aceleración llamados errorA, errorV0.
float vo(float x1, float x2, float x3, float x4);
float a(float x1, float x2, float x3, float x4);
float errorA, errorV0;


//Variable a utilizar para el cálculo de incertezas

float beta;

//Variable a utilizar en el loop
int i;

//Variable para calcular el tiempo en el segundo 15
float resultado;

//Iniciamos nuestra función main

void main(void){
        //Variables para escribir en pantalla
        int i;
        float t, v;

        //Se dan las instrucciones de lo que se realizará
        printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
        printf("\nSe han tomado unos datos experimentalmente de velocidades y tiempo. Se requiere \nencontrar la función que mejor lo represente y así mismo encontrar la aceleración\ny la velocidad que el cuerpo tendrá después de haber transcurrido 15 segundos.");
        printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");

        printf("\nLos datos tomados se muestras a continuacion en una tabla, estos tienen una \n incerteza de más o menos 1:\n");
        printf("\n|Velocidad | Tiempo|");
        for(int i=0; i<6; i++){

                v = vel[i];
                t = time[i];

        printf("\n|%.1f    |    %.1f|\n",v,t);

        }


    //Procedemos a calcular las sumatorias que vamos a utilizar para el método de mínimos cuadrados.

        for(int i=0; i<6; i++){

        //Sumatoria de todos los tiempos llamada Sx
        sx = sx + time[i];

        //Sumatoria de todas las velocidades llamada Sy
        sy = sy + vel[i];

        //Sumatoria de los cuadrados de los tiempos llamado Sxx
        sxx = sxx + time[i]*time[i];

        //sumatoria del producto de los tiempos con las velocidades llamado sxy
        sxy = sxy + time[i]*vel[i];

    }
        printf("\nPara el metodo de mínimos cuadrados ocuparemos los siguientes datos\n \nΣt_i=%.2f\tΣv_i=%.2f\tΣt²_i=%.2f\tΣv_i*t_i=%.2f", sx, sy, sxx, sxy);

        
        //Mostramos los resultados de:

        //Pendiente (aceleración)
        ac = a(sx, sy, sxx, sxy);
        printf("\n\nEl valor de la aceleración (la pendiente) es\na=%.3f", ac);

        //Intersección (Velocidad inicial)
        velocidad0 = vo(sx, sy, sxx, sxy);
        printf("\nEl valor de la velocidad inicial (intersección en el eje x) es\nV0=%.3f", velocidad0);

        //Para calcular el error de la pendiente es necesario encontrar un beta 
        //cálculo de beta

        for(int i=0; i<6; i++){

            beta = beta - 2.943 + 1.98*time[i]-vel[i];
        }

    printf("\n\nConstante a utilizar para el cálculo de las incertezas\nbeta=%.4f", beta);

    //Incerteza para la pendiente (aceleración)

    errorA = sqrt(6/(6*sxx-sx*sx))*sqrt((beta*beta)/4);
    errorV0 = sqrt(sxx/(6*sxx-sx*sx))*sqrt((beta*beta)/4);
    printf("\nteniendo incertezas para lo siguiente:");
    printf("\nIncerteza para la aceleración = ±%.4f", errorA);
    printf("\nIncerteza para la velocidad inicial = ±%.4f\n",errorV0);

    //Se presentan los resultados al usuario
    
    printf("\n\n\nObteniendo así la siguiente función");
    printf("\n\t\tv=%.3f±%.4f+%.3ft±%.4f\n", velocidad0, errorV0, ac, errorA);

    printf("\nDonde la aceleración encontrada es");
    printf("\n\t\t a=%.3f",ac);

    printf("\n\nResolviendo a la pregunta cuál es la velocidad en el segundo 15, solo evaluamos");

    resultado = velocidad0 + ac*15;

    printf("\n\t\t V(15)=%.4f", resultado);
    
    printf("\n\n\nA continuación se mostrarán las gráficas con la herramienta\n de Gnuplot.\n");

    //Ahora vamos a crear las gráficas para mostrar los resultados.
    //Guardamos los datos obtenidos de manera experimental en un archivo txt

    FILE * datos = fopen("data.txt", "w");

    for(int i=0; i<6; i++){
        fprintf(datos, "%.1f\t%.1f\t1\n", time[i], vel[i]);
    }

    fclose(datos);

    //Abrimos un segundo puntero, este será directamente para plotear la función que encontramos y con el data.txt 
    //que acabamos de crear.


    FILE * pipe = popen("gnuplot -persist","w");
    fprintf(pipe, "set title 'Velocidad de un cuerpo con aceleración constante'\n");
    fprintf(pipe, "set xlabel 'Tiempo'\n");
    fprintf(pipe, "set ylabel 'Velocidad'\n");
    fprintf(pipe, "set label 'v=%.3f±%.4f+%.3ft±%.4f' at 3,10\n", velocidad0, errorV0, ac, errorA);
    fprintf(pipe, "plot 'data.txt' using 1:2:3 with errorbars, y=%.3f+%.3fx\n", velocidad0, ac);

    pclose(pipe);

    //Borramos el archivo .txt que creamos

    remove("data.txt");
}


//Función para encontrar la pendiente (aceleración)
float a(float x1, float x2, float x3, float x4){
    float aceleracion;
    aceleracion = ((6*x4)-(x1*x2))/((6*x3)-(x1*x1));

    return aceleracion;
    }

//Función para encontrar la intersecciñón en x (velocidad inicial)
float vo(float x1, float x2, float x3, float x4){
    float vel0;

    vel0 = ((x2*x3)-(x1*x4))/((6*x3)-(x1*x1));

    return vel0;
}

