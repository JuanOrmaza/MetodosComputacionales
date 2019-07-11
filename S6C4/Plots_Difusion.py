import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

datos=np.genfromtxt("datos2.txt")
x=np.linspace(0,1,100)
y=np.linspace(0,1,100)
x,y = np.meshgrid(x,y)
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(x, y, datos, linewidth=0, antialiased=True)
plt.title("Placa")
ax.set_zlabel("Temperatura [°C]")
ax.set_xlabel("x[m]")
ax.set_ylabel("y[m]")
plt.savefig("placatemp.png")