#include <iostream>
#include <math.h>
using namespace std;

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
    int puntosT;
    puntosT=0.1/dt;
    
    // vectores:
    
    double x[puntos];
    double phi[puntos];
    phi[0]=0;
    phi[puntos]=0;
    //comentar la siguiente linea para dejar la linea en reposo
    phi[puntos/2]=A0;
    for(int i=1;i<puntos;i++){
        if(i<puntos/2){
            phi[i]=(A0/(longitud/2))*dx*i;
        }
        if(i>puntos/2){
            phi[i]=2*A0-(A0/(longitud/2))*dx*i;
        }
    }
    cout<< 2000<<",";
    for(int i=0;i<puntos;i++){
        x[i]=i*dx;
        cout<< x[i] << ",";
    }
    cout<<endl;
        
    
    double futuroinicial[puntos];
    futuroinicial[0]=0;
    futuroinicial[puntos]=0;
    for(int i=1; i<puntos-1; i++){
        futuroinicial[i]=(r2/2)*(phi[i+1]+phi[i-1]-2*phi[i])+phi[i];
    }
    
    double pasado[puntos];
    double futuro[puntos];
    for(int i=0; i<puntos;i++){
        futuro[i]=futuroinicial[i]; 
        pasado[i]=phi[i];
    }

    for(int t=0;t<puntosT;t++){
        for(int j=1;j<puntos-1;j++){
            futuro[j]=r2*(phi[j+1]+phi[j-1]-2*phi[j])-pasado[j]+2*phi[j];
        }
        
        for(int i=0; i<puntos;i++){
            pasado[i]=phi[i];
            phi[i]=futuro[i];                
        }
        
        //para extremo libre, quite el comentario
        //phi[0]=futuro[1];
        //para perturbacion inicial con coseno quite el comentario
        //phi[0]=A0*sin((3*c*t*dt*3.1415)/longitud);
        
            if(t%50==0){
                cout<<t*dt<<",";
                for(int k=0;k<puntos;k++){
                    cout<<phi[k]<<",";
                }
                cout<<endl;
            }
     }
     return 0;
}    

double *tambor(){
float  lados;    
lados=1.0;
float deltax;
deltax=0.005;
float vc;
vc=300.0;
float tfinal;
tfinal=0.1;


}
