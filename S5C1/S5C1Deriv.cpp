#include <iostream>
#include <math.h>
using namespace std;
double derivada(int *x)
{
    int s;
    s=sizeof(x)/sizeof(x[0]);
    int der[s];
    for(int i=1;i<s;i++){
        der[i]=(x[i]-x[i-1])/2 ;
    }
    int *point;
    point=der;
    return *point;
}

int main()
{
    int x[100];
    double inicio;
    double fin;
    double num;
    cout<<"de un numero para el inicio del intervalo: "<<endl;
    cin>>inicio;
    cout<<"de un numero para el fin del intervalo: "<<endl;
    cin>>fin;
    cout<<"de un numero de puntos para el intervalo: "<<endl;
    cin>>num;
    double h;
    h=(fin-inicio)/(num);
    for(int i=0;i<num;i++){
        x[i]=inicio+i*h;
    }
    int *p;
    p=x;
    derivada(p);
    for(int i=0; i<100; i++){
        cout>>*p;
        p++;
    }
}