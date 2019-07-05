#include <iostream>
using namespace std;

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