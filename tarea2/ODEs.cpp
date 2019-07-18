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
     
    float posy[puntos];
    float vely[puntos];
    
    
    t[0]=0.0;
    posx[0]=x0;
    posy[0]=y0;
    velx[0]=xprima1;
    vely[0]=yprima1;
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
        
    float posy[puntos];
    float vely[puntos];
        
    
    t[0]=0.0;
    t[1]=dt;
    posx[0]=x0;
    posy[0]=y0;
    velx[0]=xprima1;
    vely[0]=yprima1;
    posx[1] = posx[0] + dt*velocidad(velx[0]);
    posy[1] = posy[0] + dt*velocidad(vely[0]);
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


float runge(float x0,float y0,float vx0,float vy0,float dt,int num)
{
    //inicio
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
        
    posx[0]=x0;
    posy[0]=y0;
    velx[0]=xprima1;
    vely[0]=yprima1;
    fuerx[0]=xprima2;
    fuery[0]=yprima2;
    t[0]=0;
       
    for(int i=1; i<puntos; i++){
        
        t[i]=t[i-1]+dt;
        
        //primer paso
        float posx_1 = posx[i-1] + (dt/2)*velocidad(velx[i-1]);
        float posy_1 = posy[i-1] + (dt/2)*velocidad(vely[i-1]);
        float velx_1 = velx[i-1] + (dt/2)*fuerza(posx_1,posy_1);
        float vely_1 = vely[i-1] + (dt/2)*fuerza(posy_1,posx_1); 
        float forx_1 = fuerza(posx_1,posy_1);
        float fory_1 = fuerza(posy_1,posx_1);
        
        //segundo paso
        
        float posx_2 = posx[i-1] + (dt/2)*velx_1;
        float posy_2 = posy[i-1] + (dt/2)*vely_1;
        float velx_2 = velx[i-1] + (dt/2)*fuerza(posx_2,posy_2);
        float vely_2 = vely[i-1] + (dt/2)*fuerza(posy_2,posx_2); 
        float forx_2 = fuerza(posx_2,posy_2);
        float fory_2 = fuerza(posy_2,posx_2);
        
        //tercer paso
        
        float posx_3 = posx[i-1] + (dt)*velx_2;
        float posy_3 = posy[i-1] + (dt)*vely_2;
        float velx_3 = velx[i-1] + (dt)*fuerza(posx_3,posy_3);
        float vely_3 = vely[i-1] + (dt)*fuerza(posy_3,posx_3); 
        float forx_3 = fuerza(posx_3,posy_3);
        float fory_3 = fuerza(posy_3,posx_3);
        
        //promedio
        float promediovelx = (1.0/6.0)*(velx[i-1] + 2.0*velx_1 + 2.0*velx_2 + velx_3);
        float promediovely = (1.0/6.0)*(vely[i-1] + 2.0*vely_1 + 2.0*vely_2 + vely_3);   
        float promediofuerx = (1.0/6.0)*(fuerx[i-1] + 2.0*forx_1 + 2.0*forx_2 + forx_3);
        float promediofuery = (1.0/6.0)*(fuery[i-1] + 2.0*fory_1 + 2.0*fory_2 + fory_3);
            
            
        posx[i]=posx[i-1]+dt*promediovelx;
        posy[i]=posy[i-1]+dt*promediovely;
        velx[i]=velx[i-1]+dt*promediofuerx;
        vely[i]=vely[i-1]+dt*promediofuery;
        
    }
    ofstream outfile;
    outfile.open("datosrunge"+to_string(num)+".txt");
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
    runge(x0,y0,vx0,vy0,dt3,1);
    runge(x0,y0,vx0,vy0,dt3,2);
    runge(x0,y0,vx0,vy0,dt3,3);
    
}



        
        
        
        
        
        
        
        
