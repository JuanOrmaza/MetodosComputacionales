import numpy as np
import matplotlib.pyplot as plt

datos=np.genfromtxt('datos.txt')
plt.figure(figsize=(10,10))
plt.plot(datos[:,0],datos[:,1])
plt.xlabel('tiempo t[s]')
plt.ylabel('x(t)')
plt.savefig('grafica.png')