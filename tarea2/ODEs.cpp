#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

float velocidad(float vel){
    return vel;
}

float fuerza(float a, float b){
    float masasol= 1.989*1e30;
    float yr=31536000.0;
    float G=6.674*1e-11*(1/((1.496e11)*(1.496e11)*(1.496e11)))*masasol*(yr*yr);
    return -(G*a)/pow(a*a+b*b,3/2);
}


float Euler(float x0,float y0,float vx0,float vy0,float dt,int num){
    float xprima1=velocidad(vx0);
    float xprima2=fuerza(x0,y0);
    float yprima1=velocidad(vy0);
    float yprima2=fuerza(y0,x0);
    int puntos = 20/dt;
    float t[puntos];
    
    float posx[puntos];
    float velx[puntos];
    float fuerx[puntos];
    
    float posy[puntos];
    float vely[puntos];
    float fuery[puntos];
    
    
    t[0]=0.0;
    posx[0]=x0;
    posy[0]=y0;
    velx[0]=xprima1;
    vely[0]=yprima1;
    fuerx[0]=xprima2;
    fuery[0]=yprima2;
    for(int i=1; i<puntos; i++){
        t[i] = t[i-1] + dt;
        posx[i] = posx[i-1] + dt*velocidad(velx[i-1]);
        velx[i] = velx[i-1] + dt*fuerza(posx[i-1],posy[i-1]);
        posy[i] = posy[i-1] + dt*velocidad(vely[i-1]);
        vely[i] = vely[i-1] + dt*fuerza(posy[i-1],posx[i-1]);
    }
    ofstream outfile;
    outfile.open("datoseuler"+to_string(num)+".txt");
    for(int i=0; i<puntos; i++){
        outfile<<t[i]<<" "<<posx[i]<<" "<<velx[i]<<" "<<posy[i]<<" "<<vely[i]<<endl;
    }
}

float leapfrog(float x0,float y0,float vx0,float vy0,float dt,int num){
    float xprima1=velocidad(vx0);
    float xprima2=fuerza(x0,y0);
    float yprima1=velocidad(vy0);
    float yprima2=fuerza(y0,x0);
    int puntos = 20/dt;
    float t[puntos];
    
    float posx[puntos];
    float velx[puntos];
    float fuerx[puntos];
    
    float posy[puntos];
    float vely[puntos];
    float fuery[puntos];
    
    
    t[0]=0.0;
    t[1]=dt;
    posx[0]=x0;
    posy[0]=y0;
    velx[0]=xprima1;
    vely[0]=yprima1;
    posx[1] = posx[0] + dt*velocidad(velx[0]);
    posy[1] = posy[0] + dt*velocidad(vely[0]);
    fuerx[0]=xprima2;
    fuery[0]=yprima2;
    velx[1] = velx[0] + dt*fuerza(posx[0],posy[0]);
    vely[1] = vely[0] + dt*fuerza(posy[0],posx[0]);
    for(int i=2; i<puntos; i++){
        t[i] = t[i-1] + dt;
        posx[i] = posx[i-2] + 2*dt*velocidad(velx[i-1]);
        velx[i] = velx[i-2] + 2*dt*fuerza(posx[i-1],posy[i-1]);
        posy[i] = posy[i-2] + 2*dt*velocidad(vely[i-1]);
        vely[i] = vely[i-2] + 2*dt*fuerza(posy[i-1],posx[i-1]);
    }
    ofstream outfile;
    outfile.open("datosleap"+to_string(num)+".txt");
    for(int i=0; i<puntos; i++){
        outfile<<t[i]<<" "<<posx[i]<<" "<<velx[i]<<" "<<posy[i]<<" "<<vely[i]<<endl;
    }
}



int main()
{
    //condiciones iniciales
    float x0 = 0.1163;
    float y0 = 0.9772;
    float vx0 = -6.35;
    float vy0 = 0.606;
    float dt1=0.01;
    float dt2=0.001;
    float dt3=0.0001;
    Euler(x0,y0,vx0,vy0,dt1,1);
    Euler(x0,y0,vx0,vy0,dt2,2);
    Euler(x0,y0,vx0,vy0,dt3,3);
    leapfrog(x0,y0,vx0,vy0,dt1,1);
    leapfrog(x0,y0,vx0,vy0,dt2,2);
    leapfrog(x0,y0,vx0,vy0,dt3,3);
    
}


/*
float runge(float x0,float y0,float vx0,float vy0,float dt)
{
    //inicio
    float xprima1=velocidad(vx0);
    float xprima2=fuerza(x0,y0);
    float yprima1=velocidad(vy0);
    float yprima2=fuerza(y0,x0);
    float t[puntos];
       
    //primer paso
    float x1 = x0 + dt/2;
    float vx1 = vx0 + 
*/   
       
         /*
    k_1_prime1 = func_prime_1(x_old,y1_old, y2_old)
    k_1_prime2 = func_prime_2(x_old,y1_old, y2_old)
    
    #first step
    x1 = x_old+ (h/2.0)
    y1_1 = y1_old + (h/2.0) * k_1_prime1
    y2_1 = y2_old + (h/2.0) * k_1_prime2
    k_2_prime1 = func_prime_1(x1, y1_1, y2_1)
    k_2_prime2 = func_prime_2(x1, y1_1, y2_1)
    
    #second step
    x2 = x_old + (h/2.0)
    y1_2 = y1_old + (h/2.0) * k_2_prime1
    y2_2 = y2_old + (h/2.0) * k_2_prime2
    k_3_prime1 = func_prime_1(x2, y1_2, y2_2)
    k_3_prime2 = func_prime_2(x2, y1_2, y2_2)
    
    
    #third
    x3 = x_old + h
    y1_3 = y1_old + h * k_3_prime1
    y2_3 = y2_old + h * k_3_prime2
    k_4_prime1 = func_prime_1(x3, y1_3, y2_3)
    k_4_prime2 = func_prime_2(x3, y1_3, y2_3)
    
    #fourth step
    average_k_1 = (1.0/6.0)*(k_1_prime1 + 2.0*k_2_prime1 + 2.0*k_3_prime1 + k_4_prime1)
    average_k_2 = (1.0/6.0)*(k_1_prime2 + 2.0*k_2_prime2 + 2.0*k_3_prime2 + k_4_prime2)
    
    x_new = x_old + h
    y_1_new = y1_old + h * average_k_1
    y_2_new= y2_old + h * average_k_2
    return x_new, y_1_new, y_2_new
    
    
    
    
    
    
    x[0]   = min_x
y_1[0] = 1.0
y_2[0] = 0.0    

for i in range(1,n_points):
    x[i],y_1[i],y_2[i] = RungeKuttaFourthOrderStep(x[i-1], y_1[i-1], y_2[i-1])
*/
        
        
        
        
        
        
        
        
        
