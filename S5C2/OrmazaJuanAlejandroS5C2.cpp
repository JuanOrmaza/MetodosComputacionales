#include <iostream>
using namespace std;

double funcion(double a)
{
    return -a;
}

double *euler(int pts, double b)
{
    double *y= new double[pts];
    y[0]=1.0;
    for(int i=1; i<pts;i++){
        y[i]=y[i-1]+b*funcion(y[i-1]);
    }
    return y;
    
}

double *runge(int pts, double b)
{
    double *y= new double[pts];
    y[0] = 1.0;
    double k1;
    double k2;
    double k3;
    double k4;
    double promediok;
    for(int i=1; i<pts;i++){
        k1=b*funcion(y[i-1]);
        k2=b*funcion(y[i-1]+0.5*k1);
        k3=b*funcion(y[i-1]+0.5*k2);
        k4=b*funcion(y[i-1]+k3);
        promediok=(1.0/6.0)*(k1 + 2.0*k2 + 2.0*k3 + k4);
        y[i]=y[i-1]+promediok;
    }
    return y;
}

int main()
{
    double h;
    double xmin;
    double xmax;
    int puntos;
    h=0.01;
    xmin=0.0;
    xmax=2.0;
    puntos=(xmax-xmin)/h;
    double x[puntos];    
    x[0]=xmin;
    double *p;
    p=euler(puntos,h);
    double *p2;
    p2=runge(puntos,h);
    for(int i=1; i<puntos;i++){
        x[i]=x[i-1]+h;
        cout<< x[i] << " " << *(p+i) << " " << *(p2+i) << endl;
    }
        
}
