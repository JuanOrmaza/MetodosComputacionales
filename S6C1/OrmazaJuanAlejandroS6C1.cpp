#include <iostream>
using namespace std;

int main()
{
    int puntos;
    puntos=80;
    double x[puntos];
    double u[puntos];
    double ufut[puntos];
    int max;
    int min;    
    max=5;
    min=0;
    float dx;
    float dt;
    int velprop;
    velprop=1;
    dx=(max-min)/puntos;
    dt=(dx*0.25)/velprop;
    // condiciones inciales, en t=0:
    for(int i=0; i<puntos; i++){
        if(i*dx>0.75 && i*dx<1.25){
            u[i]=2;
        }
        else{
            u[i]=1;
        }
    }
    for(int j=1; j<puntos-1; j++){
        ufut[0]=1;
        ufut[puntos]=1;
        int counter;
        counter=0;
        for(int i=0; i<puntos-2; i++){
            ufut[i+1]=((velprop*dt)/dx)*(u[i]-u[i-1])+u[i];
        }
        counter++;
        if(counter%10=0){
        for(int i=1;i<puntos ;i++){
            cout<<x[i]<<" "<<ufut[i];
        }
        }
    }
    return 0;


}