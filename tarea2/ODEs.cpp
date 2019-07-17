#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

float velocidad(vel){
    return vel;
}

float fuerza(float a, float b){
    float masasol= 1.989*1e30;
    float G=6.674*1e-11;
    return -(G*masasol*a)/pow(a*a+b*b,3/2);
}

int main()
{
    //condiciones iniciales
    float x0 = 0.1163*1.496e11;
    float y0 = 0.9772*1.496e11;
    float vx0 = -6.35*(1.496e11/31536000);
    float vy0 = 0.606*(1.496e11/31536000);
    float dt1=0.1;
    float dt2=0.01;
    float dt3=0.001;
    
}




    
}

/*
double leapfrog(int tam, double dt)
{
    double *v= new double[tam];
    double *x= new double[tam];
    double *t= new double[tam];
    double k;
    double m;
    k=300.0;
    m=2.0;
    double km;
    km=k/m;
    x[0]=0.1;
    v[0]=(dt/2.0)*(km)*x[0];
    t[0]=0;
    for(int i=1;i<tam;i++){
        v[i]=-(2*dt)*(km)*x[i-1]+v[i-1];
        x[i]=2*dt*v[i]+x[i-1];
        t[i]=i*dt;
    }
    for(int i=0;i<tam;i++)
    {
        cout<<*(t+i)<<" "<<*(x+i)<<" "<<*(v+i)<<endl;
    }
    return 0;
}
*/

double runge( float x0,float y0,float vx0,float vy0,float dt)
{
    //inicio
    float xprima1=velocidad(vx0);
    float xprima2=fuerza(x0,y0);
    float yprima1=velocidad(vy0);
    float yprima2=fuerza(y0,x0);
       
    //primer paso
    float x1 = x0 + dt/2;
    float vx1 = vx0 + 
    
    /*
    k_1_prime1 = func_prime_1(x_old,y1_old, y2_old)
    k_1_prime2 = func_prime_2(x_old,y1_old, y2_old)
    
    #first step
    x1 = x_old+ (h/2.0)
    y1_1 = y1_old + (h/2.0) * k_1_prime1
    y2_1 = y2_old + (h/2.0) * k_1_prime2
    k_2_prime1 = func_prime_1(x1, y1_1, y2_1)
    k_2_prime2 = func_prime_2(x1, y1_1, y2_1)
    
    #second step
    x2 = x_old + (h/2.0)
    y1_2 = y1_old + (h/2.0) * k_2_prime1
    y2_2 = y2_old + (h/2.0) * k_2_prime2
    k_3_prime1 = func_prime_1(x2, y1_2, y2_2)
    k_3_prime2 = func_prime_2(x2, y1_2, y2_2)
    
    
    #third
    x3 = x_old + h
    y1_3 = y1_old + h * k_3_prime1
    y2_3 = y2_old + h * k_3_prime2
    k_4_prime1 = func_prime_1(x3, y1_3, y2_3)
    k_4_prime2 = func_prime_2(x3, y1_3, y2_3)
    
    #fourth step
    average_k_1 = (1.0/6.0)*(k_1_prime1 + 2.0*k_2_prime1 + 2.0*k_3_prime1 + k_4_prime1)
    average_k_2 = (1.0/6.0)*(k_1_prime2 + 2.0*k_2_prime2 + 2.0*k_3_prime2 + k_4_prime2)
    
    x_new = x_old + h
    y_1_new = y1_old + h * average_k_1
    y_2_new= y2_old + h * average_k_2
    return x_new, y_1_new, y_2_new
    */
}

/*
int main()
{
    double h=0.01;
    double tmax;
    double tmin;
    tmax=5;
    tmin=0;
    int size;
    size=(tmax-tmin)/h;
    leapfrog(size,h);
    return 0;
}

*/