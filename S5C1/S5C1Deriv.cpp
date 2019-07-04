#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

double *derivada(double a[100], int b, double c)
{
    double* deriv= new double[b];
    for(int i=0;i<b-1;i++){
        deriv[i]=(a[i+1]-a[i])/c;
    }
    return deriv;
}

int main()
{
    double inicio;
    double fin;
    int num;
    cout<<"de un numero para el inicio del intervalo: "<<endl;
    cin>>inicio;
    cout<<"de un numero para el fin del intervalo: "<<endl;
    cin>>fin;
    cout<<"de un numero de puntos para el intervalo: "<<endl;
    cin>>num;
    cout<<endl;
    double x[num];
    double coseno[num];
    double h;
    h=(fin-inicio)/(num);
    for(int i=0;i<num;i++){
        x[i]=inicio+i*h;
    }
    for(int i=0;i<num;i++){
        coseno[i]=cos(*(x+i));
    }
    double *p;
    p=derivada(coseno,num,h);
    fstream file; 
    file.open("datos.txt", ios::out); 
    streambuf* stream_buffer_cout = cout.rdbuf();
    streambuf* stream_buffer_file = file.rdbuf();
    cout.rdbuf(stream_buffer_file);    
    for(int i=0;i<num;i++){
        cout<<*(x+i)<<" "<<*(coseno+i)<<" "<<*(p+i)<< endl;
    }
    
}