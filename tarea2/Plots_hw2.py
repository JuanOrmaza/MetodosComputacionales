#https://github.com/JuanOrmaza/MetodosComputacionales/tree/master/tarea2

import numpy as np
import matplotlib.pyplot as plt

datoseuler1=np.genfromtxt("datoseuler1.txt")
datoseuler2=np.genfromtxt("datoseuler2.txt")
datoseuler3=np.genfromtxt("datoseuler3.txt")
datosleap1=np.genfromtxt("datosleap1.txt")
datosleap2=np.genfromtxt("datosleap2.txt")
datosleap3=np.genfromtxt("datosleap3.txt")
datosorbit=np.genfromtxt("EarthOrbit.dat")


plt.figure(figsize=(10,20))
plt.subplot(4,3,(1,3))
plt.plot(datosorbit[:,1],datosorbit[:,2])
plt.title("orbita datos earth orbit")
plt.subplot(4,3,4)
plt.plot(datoseuler1[:,1],datoseuler1[:,3])
plt.title("euler con dt=0.1")
plt.subplot(4,3,5)
plt.plot(datoseuler2[:,1],datoseuler2[:,3])
plt.title("euler con dt=0.01")
plt.subplot(4,3,6)
plt.plot(datoseuler3[:,1],datoseuler3[:,3])
plt.title("euler con dt=0.001")
plt.subplot(4,3,7)
plt.plot(datosleap1[:,1],datosleap1[:,3])
plt.title("leapfrog con dt=0.1")
plt.subplot(4,3,8)
plt.plot(datosleap2[:,1],datosleap2[:,3])
plt.title("leapfrog con dt=0.01")
plt.subplot(4,3,9)
plt.plot(datosleap3[:,1],datosleap3[:,3])
plt.title("leapfrog con dt=0.001")
plt.savefig("hola.png")




