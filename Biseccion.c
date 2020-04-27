/* Autor: Jefferson Rodríguez León
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
Fecha: sab abr 25 15:55:15 CST 2020
Resumen De una función dada se trata de encontrar la raíz de ella por el método de bisección.
Entrada:
Salida: 
*/
//librearias
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//numerar los pasos del pseudocodigo


//Función para calcular la bisección
float bisec(float x1, float x2);

//Variables a utilizar 
float a1, a2, raiz;
//Número de Euler
float e = 2.7182;

float main(){

    //Indicamos al usuario lo que realizaremos
    printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
    printf("\nA continuación se presenta una función la cual se deberán encontrar\nlas raices por medio del método de bisección.");
    printf("\n\t\t f(x)=e^{-x²/2}-0.5");
    printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

    printf("\nEl intervalo a utilizar para este ejercicio será [0.5, 2]");
    //Intervalos a utilizar. Es necesario para el método de bisección que f(a1)*f(a2)<0 por lo que
    //para elegir estos valores, primero gráfique la función en gnuplot.
    a1 = 0.5;
    a2 = 2;

    //Obteniendo el resultado de la raiz 

    raiz = bisec(a1,a2);
    printf("\nLa raiz de la función es\n\tRaiz=%.4f",raiz);

    //Mostramos los resultados en gnuplot

    printf("\nA continuación se presenta la función con la herramienta de Gnuplot\n");

    FILE * pipe = popen("gnuplot -persist","w");
    fprintf(pipe, "set title 'Metodo de Bisección'\n");
    fprintf(pipe, "set xlabel 'x'\n");
    fprintf(pipe, "set ylabel 'y'\n");
    fprintf(pipe, "set xrange [-5:5]\n");
    fprintf(pipe, "set yrange [-2:4]\n");
    fprintf(pipe, "set label 'La raíz encontrada es = %.4f' at 0,1\n", raiz);
    fprintf(pipe, "set label 'f(x)=e^{-x²/2}-0.5' at -4,3.5\n");
    fprintf(pipe, "plot exp(-x**2/2)-0.5\n");

    pclose(pipe);


}

//Trabajamos en la función para determinar la raiz

float bisec(float x1,float x2){

    //Variables locales
    float m, fa1, fm, r;

    //El número de intervalors puede ser el que se desee. En este caso coloco 30 para un resultado aproximado
    for(int i=0; i<30; i++){
        //Definimos las funciones que se utilizan para el método de bisección

        m = (x1+x2)/2;

        fa1 = pow(e,(x1*x1/2))-0.5;
        fm = pow(e,(m*m/2))-0.5;

        r = fa1*fm;

        //Lo que nos interesa es ver este resultado si es r<0, r=0 o r>0 para ellos hacemos uso de if

        if(r>0){
            //Si el resultado es positivo, entonces x1 toma el valor m
            x1 = m; 
        } else if(r<0){
            //Si el resultado es negativo, entonces x2 toma el valor de m
            x2 = m;

        }
    return m;

    }
}
