import numpy as np
import matplotlib.pyplot as plt

datos= np.genfromtxt('datos.txt')
plt.figure()
plt.plot(datos[:,0],datos[:,1])
plt.savefig('grafica.png')