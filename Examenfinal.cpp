#include<iostream>
#include<string>
#include<math.h>
#include<stdlib.h>
using namespace std;

//Constantes
const float G=6.693e-11;
const float RT=6.37e6;
const float MT=5.9736e24;
const float R=287.06;
const float L=6.5e-3;
const float g0=9.81;
const float T0=288.15;
const float P0=101325;
float delta = 0.01;
float tiempos(float E0, float TSFC, float mf0);
float dens;
float fric;
class Cohete
{
private:
    float E0, TSFC, CD, A, m0, mf0, y, vel;
public:
    Cohete(float y, float vel, float E0,float TSFC, float CD, float A, float m0, float mf0);

    float mf;
    float despegar();
    float densidad();
    float gravedad();
    float friccion();
    float tiempo();
    float masa();
    float alturamax();

};





Cohete::Cohete(float _y, float _vel, float _E0,float _TSFC, float _CD, float _A, float _m0, float _mf0){

        _y = y;
        _vel = vel;
        _E0 = E0;
        _TSFC = TSFC;
        _CD = CD;
        _A = A;
        _m0 = m0;
        _mf0 = mf0;
}

float Cohete::despegar(){

    friccion();
    masa();
    float mc;
    float delta=0.01;

    mc = mf0 + mf;
    FILE * datos = fopen("data.txt", "w");
    for (int t = 0; t < 1000; t++)
    {
        y = y + delta*vel;
        vel = vel + (E0/mc)- (fric/mc) -g0;
        if (mf0<=0)
        {
            mf0 = 0;
            E0 = 0;
        }else
        {
            mf0 = mf0 + delta*(-TSFC*E0);
    
        }
            

        
            fprintf(datos, "%.4f\n", y);
    }

        
        fclose(datos);


    FILE * datoss = fopen("datas.txt", "w");
    for (int t = 0; t < 1000; t++)
    {
        y = y + delta*vel;
        vel = vel + (E0/mc)- (fric/mc) -g0;
        if (mf0<=0)
        {
            mf0 = 0;
            E0 = 0;
        }else
        {
            mf0 = mf0 + delta*(-TSFC*E0);
    
        }
            

        
            fprintf(datos, "%.4f\n", vel);
    }

        
        fclose(datos);


FILE * pipe = popen("gnuplot -persist","w");
fprintf(pipe, "plot 'data.txt'\n");
fprintf(pipe, "plot 'datas.txt'\n");

    pclose(pipe);


        return y;
}

float Cohete::masa(){


    mf = mf0 -TSFC*E0*delta;

    return mf;
}


float Cohete::densidad(){
    
    float dens;

//La condición es que y>T0/L. Cuando sea superada esa condición, densidad=0

    if(T0/L<y){ //Si supera esa altura
        dens=0;
    }else{       //De lo contrario
    dens = P0/(R*T0)*pow(g0/(R*L),(1-(L*y/T0)));
}
    return dens;
}


float Cohete::gravedad(){
    float g;

    g = G*MT/pow(2,(RT+y));

    return g;
}

float Cohete::friccion(){
    float fric;

if(T0/L<y){ //Si supera esa altura
        dens=0;
    }else{       //De lo contrario
    dens = P0/(R*T0)*pow(g0/(R*L),(1-(L*y/T0)));
    fric = 0.5*dens*CD*A*vel*vel;
}
    return fric;
}

float Cohete::tiempo(){
    float tiemp;
    //Para encontrar el tiempo solamente podemos separar t de la función. 
    //mf(t)=mf0-TSFC*E0*t=0

    tiemp = mf0/(-TSFC*E0);

    cout<<"El tiempo en segundos donde el cohete se le acaba el combustible:"<<tiemp<<endl;

    return tiemp;
}

float Cohete::alturamax(){

float ymax;

for (int i = 0; i < 100; i++)
{
    /* code */
    if (mf0<=0)
    {
        mf0=0;
        E0=0;
    }else{
        mf0 = mf0 + delta*(-TSFC*E0);
    }

    if(y>ymax){
        ymax=y;
    }
    
}
    cout<<"La altura máxima es"<<ymax<<endl;

return ymax;

}

//Una solución al calculo del tiempo cuando se queda sin combustible

float tiempos(float E0, float TSFC, float mf0){
    float tiem;
        tiem = mf0/(-TSFC*E0);

        return tiem;
}

int main(void){

    float t1,t2,t3;

    //Para el cohete1
    float E01 = 3e7;
    float TSFC1 = 3.248e-14;
    float CD1 = 61.27;
    float A1 = 201.06;
    float m01 = 1.1e5;
    float mf01 = 1.5e6;

    //Para el cohete2
    float E02 = 2.7e7;
    float TSFC2 = 2.248e-14;
    float CD2 = 61.27;
    float A2 = 201.06;
    float m02 = 1.1e5;
    float mf02 = 1.5e6;

    //Para el cohete3
    float E03 = 2.5e7;
    float TSFC3 = 2.248e-14;
    float CD3 = 70.25;
    float A3 = 215.00;
    float m03 = 1.8e5;
    float mf03 = 2.1e6;


    //Tengo problemas con el tiempo :(( a veces me salen numeros y a veces solo dice -inf
    //intenté cambiar de float a double pero no ayudó :c y no sé cual es mi error.

    Cohete cohete1(0, 0, 3e7, 3.248e-14, 61.27, 201.06, 1.1e5, 1.5e6);
    cohete1.tiempo();

    Cohete cohete2(0, 0, 2.7e7, 2.248e-14, 61.27, 201.06, 1.1e5, 1.5e6);
    cohete2.tiempo();

    Cohete cohete3(0,0, 2.5e7, 2.248e-14, 70.25, 215, 1.8e5, 2.1e6);
    cohete3.tiempo();

    t1 = tiempos(E01, TSFC1, mf01);
    printf("El tiempo para el primer cohete:%.4f\n",t1);

    t2 = tiempos(E02, TSFC2, mf02);
    printf("El tiempo para el segundo cohete:%.4f\n",t1);

    t3 = tiempos(E03, TSFC3, mf03);
    printf("El tiempo para el tercer cohete:%.4f\n",t1);

    cohete1.alturamax();
    
    int ok;
    printf("De quién quiere ver las gráficas? escriba el número del cohete(1,2,3)");
    scanf("%i", &ok);
    if(ok==1){
        cohete1.despegar();
    }else{
        if(ok==2){
            cohete2.despegar();
        }else{
            if(ok==3){
                cohete3.despegar();
            }
        }
    }





    return 0;
}