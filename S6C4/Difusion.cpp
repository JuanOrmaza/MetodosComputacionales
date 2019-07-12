#include <iostream>
#include <fstream>
#include <iostream>
using namespace std;

int caso1()
{
    //condiciones iniciales
    float nu=1e-4;
    int longitud=1;
    float dx=0.01;
    int puntos=longitud/dx;
    double tmax=2500;
    float dt=((dx*dx)/nu)*0.25;
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
                placafut[i][j]=nu*(dt/(dx*dx))*((placa[i+1][j]+placa[i-1][j]+placa[i][j+1]+placa[i][j-1])-4*placa[i][j]) + placa[i][j];
            }
        }
        for(int i=1;i<puntos-1;i++){
            for(int j=1;j<puntos-1;j++){
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
        if(t==puntosT-1){
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
    return 0;
}

int caso2()
{
    //condiciones iniciales
    float nu=1e-4;
    int longitud=1;
    float dx=0.01;
    int puntos=longitud/dx;
    double tmax=2500;
    float dt=((dx*dx)/nu)*0.25;
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
                placafut[i][j]=nu*(dt/(dx*dx))*((placa[i+1][j]+placa[i-1][j]+placa[i][j+1]+placa[i][j-1])-4*placa[i][j]) + placa[i][j];
            }
        }
        for(int i=1;i<puntos-1;i++){
            for(int j=1;j<puntos-1;j++){
                placa[i][j]=placafut[i][j];
            }
        }
        
        for(int i=0;i<puntos;i++){
            placa[i][0]=placa[i][1];
            placa[i][puntos-1]=placa[i][puntos-2];
            placa[0][i]=placa[1][i];
            placa[puntos-1][i]=placa[puntos-2][i];
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
        if(t==puntosT-1){
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
    return 0;
}

int caso3()
{
    //condiciones iniciales
    float nu=1e-4;
    int longitud=1;
    float dx=0.01;
    int puntos=longitud/dx;
    double tmax=2500;
    float dt=((dx*dx)/nu)*0.25;
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
                placafut[i][j]=nu*(dt/(dx*dx))*((placa[i+1][j]+placa[i-1][j]+placa[i][j+1]+placa[i][j-1])-4*placa[i][j]) + placa[i][j];
            }
        }
        for(int i=1;i<puntos-1;i++){
            for(int j=1;j<puntos-1;j++){
                placa[i][j]=placafut[i][j];
            }
        }
        
        for(int i=0;i<puntos;i++){
            placa[i][0]=placa[i][puntos-2];
            placa[i][puntos-1]=placa[i][1];
            placa[0][i]=placa[puntos-2][i];
            placa[puntos-1][i]=placa[1][i];
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
        if(t==puntosT-1){
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
    return 0;
}

int main()
{
    cout<<"caso 1: fronteras fijas"<<endl<<"caso 2: fronteras abiertas"<<endl<<"caso 3: fronteras periodicas"<<endl;
    cout<<"indique con un numero que caso quiere, (solo puede escoger del 1 al 3): "<< endl;
    int x;
    cin>>x;
    if(x==1){
        caso1();
    }
    if(x==2){
        caso2();
    }
    if(x==3){
        caso3();
    }
}

