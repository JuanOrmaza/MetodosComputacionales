#include <iostream>
using namespace std;
// funciones
double *futuro(double* a,double *b, int lon, double r)
{
    double *futuro= new double[lon];
    futuro[0]=0;
    futuro[lon]=0;
    for(int i=1; i<lon; i++){
        futuro[i]=r*(a[i+1]*+a[i-1]-2*a[i])-b[i]+2*a[i];
    }
    return futuro;
}  
double *futuroinit(double* a, int lon, double r)
{
    double *futuro= new double[lon];
    futuro[0]=0;
    futuro[lon]=0;
    for(int i=1; i<lon; i++){
        futuro[i]=r*(a[i+1]*+a[i-1]-2*a[i])+2*a[i];
    }
    return futuro;
}     

double *pasado(double* a,int lon)
{
    double *presente= new double[lon];
    for(int i=0; i<lon; i++){
        presente[i]=*(a+i);
    }
    return presente;
}
 //funcion main

int main()
{
    //condiciones iniciales
    
    double longitud;
    float dx;
    float c;
    float dt;
    float A0;
    int puntos;    
    longitud=1.0;
    dx=0.005;
    c=300.0;
    dt=(dx/c)*0.25;
    puntos=longitud/dx;
    A0=0.01;
    double r2;
    r2=((c*c)*(dt*dt))/(dx*dx);
    
    // vectores:
    
    double x[puntos];
    double phi[puntos];
    phi[0]=0;
    phi[puntos]=0;
    phi[puntos/2]=A0;
    for(int i=1;i<puntos;i++){
        if(i<puntos/2){
            phi[i]=(A0/(longitud/2))*dx*i;
        }
        if(i>puntos/2){
            phi[i]=2*A0-(A0/(longitud/2))*dx*i;
        }
    }
    // futuro, presente y pasado:
    double *futuroinicial;
    double *futuros;
    double *pasados;
    double futuro[puntos];
    double pasado[puntos];
    futuroinicial=futuroinit(phi,puntos,r2);
    
    for(int i=0;i<puntos;i++){
        futuro[i]=*(futuroinicial+i);
    }
    int counter;
    counter=0;
    for(int i=0;i<puntos;i++){
        counter++;
        for(int j=0;j<puntos;j++){
            pasados=pasado(phi,puntos);
            phi[j]=futuro[j];
            if(counter%5==0){
            cout<<x[i]<<" "<<;
            }
        }
    }
    return 0;
}    
    
