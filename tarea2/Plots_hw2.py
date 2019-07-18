#https://github.com/JuanOrmaza/MetodosComputacionales/tree/master/tarea2

import numpy as np
import matplotlib.pyplot as plt

#datos
datoseuler1=np.genfromtxt("datoseuler1.txt")
datoseuler2=np.genfromtxt("datoseuler2.txt")
datoseuler3=np.genfromtxt("datoseuler3.txt")
datosleap1=np.genfromtxt("datosleap1.txt")
datosleap2=np.genfromtxt("datosleap2.txt")
datosleap3=np.genfromtxt("datosleap3.txt")
datosrunge1=np.genfromtxt("datosrunge1.txt")
datosrunge2=np.genfromtxt("datosrunge2.txt")
datosrunge3=np.genfromtxt("datosrunge3.txt")
datosorbit=np.genfromtxt("EarthOrbit.dat")

#grafica1
plt.figure(figsize=(10,20))
plt.subplot(5,3,(1,3))
plt.plot(datosorbit[:,1],datosorbit[:,2])
plt.title("orbita datos earth orbit")
plt.subplot(5,3,4)
plt.plot(datoseuler1[:,1],datoseuler1[:,3])
plt.title("euler con dt=0.1")
plt.subplot(5,3,5)
plt.plot(datoseuler2[:,1],datoseuler2[:,3])
plt.title("euler con dt=0.01")
plt.subplot(5,3,6)
plt.plot(datoseuler3[:,1],datoseuler3[:,3])
plt.title("euler con dt=0.001")
plt.subplot(5,3,7)
plt.plot(datosleap1[:,1],datosleap1[:,3])
plt.title("leapfrog con dt=0.1")
plt.subplot(5,3,8)
plt.plot(datosleap2[:,1],datosleap2[:,3])
plt.title("leapfrog con dt=0.01")
plt.subplot(5,3,9)
plt.plot(datosleap3[:,1],datosleap3[:,3])
plt.title("leapfrog con dt=0.001")
plt.subplot(5,3,10)
plt.plot(datosrunge1[:,1],datosrunge1[:,3])
plt.title("runge kutta 4orden con dt=0.1")
plt.subplot(5,3,11)
plt.plot(datosrunge2[:,1],datosrunge2[:,3])
plt.title("runge kutta 4orden con dt=0.01")
plt.subplot(5,3,12)
plt.plot(datosrunge3[:,1],datosrunge3[:,3])
plt.title("runge kutta 4orden con dt=0.001")
plt.savefig("hola.png")

#energias
def energia(x,y,vx,vy):
    masa=3.00273e-6
    G=6.674*1e-11*(1/((1.496*1e11)**3))*1.989*1e30*(31536000**2)
    tam=len(x)
    ener=[]
    for i in range(tam):
        calculo=-G*masa*((x[i]**2+y[i]**2)**0.5)-(1/2)*masa*vx[i]**2-(1/2)*masa*vy[i]**2
        ener.append(calculo)
    return ener

                   
#moment angular
def momang(x,y,vx,vy):
    masa=3.00273e-6
    tam=len(x)
    mom=[]
    for i in range(tam):
        mom.append((masa*vx[i]+masa*vy[i])*((x[i]**2+y[i]**2)**0.5))
    return mom

#grafica2
plt.figure(figsize=(10,20))
plt.subplot(3,3,1)
plt.plot(datoseuler1[:,0],energia(datoseuler1[:,1],datoseuler1[:,3],datoseuler1[:,2],datoseuler1[:,4]))
plt.title("energia euler con dt=0.1")
plt.subplot(3,3,2)
plt.plot(datoseuler2[:,0],energia(datoseuler2[:,1],datoseuler2[:,3],datoseuler2[:,2],datoseuler2[:,4]))
plt.title("energia euler con dt=0.01")
plt.subplot(3,3,3)
plt.plot(datoseuler3[:,0],energia(datoseuler3[:,1],datoseuler3[:,3],datoseuler3[:,2],datoseuler3[:,4]))
plt.title("energia euler con dt=0.001")
plt.subplot(3,3,4)
plt.plot(datosleap1[:,0],energia(datosleap1[:,1],datosleap1[:,3],datosleap1[:,2],datosleap1[:,4]))
plt.title("energia leapfrog con dt=0.1")
plt.subplot(3,3,5)
plt.plot(datosleap2[:,0],energia(datosleap2[:,1],datosleap2[:,3],datosleap2[:,2],datosleap2[:,4]))
plt.title("energia leapfrog con dt=0.01")
plt.subplot(3,3,6)
plt.plot(datosleap3[:,0],energia(datosleap3[:,1],datosleap3[:,3],datosleap3[:,2],datosleap3[:,4]))
plt.title("energia leapfrog con dt=0.001")
plt.subplot(3,3,7)
plt.plot(datosrunge1[:,0],energia(datosrunge1[:,1],datosrunge1[:,3],datosrunge1[:,2],datosrunge1[:,4]))
plt.title("energia leapfrog con dt=0.1")
plt.subplot(3,3,8)
plt.plot(datosrunge2[:,0],energia(datosrunge2[:,1],datosrunge2[:,3],datosrunge2[:,2],datosrunge2[:,4]))
plt.title("energia leapfrog con dt=0.01")
plt.subplot(3,3,9)
plt.plot(datosrunge3[:,0],energia(datosrunge3[:,1],datosrunge3[:,3],datosrunge3[:,2],datosrunge3[:,4]))
plt.title("energia leapfrog con dt=0.001")
plt.savefig("hola2.png")
                   
       







