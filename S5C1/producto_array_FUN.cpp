#include <iostream>
using namespace std;

double productoelemento(int *x, int *y)
{
    for(int i=0;i<5;i++)
    {
        cout<< (x[i])*(y[i]) << endl;
    }
}

double productopunto(int *x, int *y)
{
    double suma=0;
    for(int i=0;i<5;i++)
    {
        suma += x[i]*y[i];
    }
    cout<<"el producto punto es: " << suma << endl;
}


int main()
{
    int *p1;
    int *p2;
    int a[5] = {1,2,3,4,5};
    int b[5] = {10,20,30,40,50};
    p1=a;
    p2=b;
    productoelemento(p1,p2);
    productopunto(p1,p2);
}