import numpy as np
import matplotlib.pyplot as plt

datos = np.genfromtxt('datos.txt')
plt.clf()
plt.figure()
plt.plot(datos[:,0], datos[:,1], label='coseno')
plt.legend()
plt.plot(datos[:,0], datos[:,2], label='derivada')
plt.legend()
plt.savefig('S5C1PLOT.pdf')