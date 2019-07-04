import numpy as np
import matplotlib.pyplot as plt

datos = np.genfromtxt('datos.txt')
plt.figure(figsize=(10,10))
plt.plot(datos[:,0],datos[:,1],label='euler')
plt.plot(datos[:,0],datos[:,2],label='runge-kutta')
plt.legend()
plt.xlabel('x')
plt.ylabel('y(x)')
plt.grid()
plt.savefig('grafica.png')