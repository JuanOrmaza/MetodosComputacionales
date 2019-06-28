#include<iostream>

using namespace std;

int main()
{
    int a;
    cout<<"ingrese un numero entero positivo";
    cin>>a;
    double f;
    f=1;
    for(int i=1; i<=a; i++){
        f=f*i;
    }
    cout<<"el valor del factorial es: "<<f;
}