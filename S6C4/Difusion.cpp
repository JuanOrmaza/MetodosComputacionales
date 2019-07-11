#include <iostream>
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    //condiciones iniciales
    float nu=1e-4;
    int longitud=1;
    float dx=0.01;
    int puntos=longitud/dx;
    double tmax=2500;
    float dt=(dx/nu)*0.25;
    int puntosT=tmax/dt;
    
    //crear placa inicial
   ofstream outfile;
   outfile.open("datos.txt");
    double placa[puntos][puntos];
    for(int i=0;i<puntos;i++){
        for(int j=0; j<puntos; j++){
            if(i*dx>=0.20 && i*dx<=0.40 && j*dx>=0.40 && j*dx<=0.6){
                placa[i][j]=100;
            }
            else{
                placa[i][j]=50;
            }
        }
    }
    for(int i=0;i<puntos;i++){
        for(int j=0;j<puntos;j++){
            outfile<<placa[i][j]<<" ";
        }
        outfile<<endl;
    }
    
    
    //transformacion de la matriz con el tiempo
    double placafut[puntos][puntos];
    
    for(int t=0; t<puntosT; t++)
    {
        for(int i=1;i<puntos-1;i++){
            for(int j=1;j<puntos-1;j++){
                placafut[i][j]=nu*dt*((placa[i+1][j]+placa[i-1][j]-placa[i][j+1]-placa[i][j-1])/(dx*dx)) + placa[i][j];
            }
        }
        for(int i=0;i<puntos;i++){
            for(int j=0;j<puntos;j++){
                placa[i][j]=placafut[i][j];
            }
        }
               
        if(t*dt==100){
        ofstream outfile;
        outfile.open("datos2.txt");
            for(int i=0;i<puntos;i++){
                for(int j=0;j<puntos;j++){
                    outfile<<placa[i][j]<<" ";
                }
                outfile<<endl;
            }
        }
        if(t*dt==1000){
        ofstream outfile;
        outfile.open("datos3.txt");
            for(int i=0;i<puntos;i++){
                for(int j=0;j<puntos;j++){
                    outfile<<placa[i][j]<<" ";
                }
                outfile<<endl;
            }
        }
        if(t==2){
        ofstream outfile;
        outfile.open("datos4.txt");
            for(int i=0;i<puntos;i++){
                for(int j=0;j<puntos;j++){
                    outfile<<placa[i][j]<<" ";
                }
                outfile<<endl;
            }
        }
    
    }
    
    
    

}