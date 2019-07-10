import numpy as np
import matplotlib.pyplot as plt
import imageio

datos= np.genfromtxt('datos.txt',delimiter=",")
print(np.shape(datos))

# codigo de gif, utilizado bajo el permiso de Andres Florez:

def plot_for_offset(i, datos):
    amp=datos[i,1:201]
    t=datos[1:1201,0]
    x=datos[0,1:201]
    dt=datos[2,0]-datos[1,0]

    fig, ax = plt.subplots(figsize=(10,5))
    ax.plot(x, amp)
    ax.grid()
    ax.set(xlabel='tiempo [s]={}'.format(i*dt), ylabel='Amplitud',
           title='cuerda con amplitud inicial y extremos fijos')

    ax.set_ylim(-0.02, 0.02)

    # Used to return the plot as an image rray
    fig.canvas.draw()       # draw the canvas, cache the renderer
    image = np.frombuffer(fig.canvas.tostring_rgb(), dtype='uint8')
    image  = image.reshape(fig.canvas.get_width_height()[::-1] + (3,))

    return image

kwargs_write = {'fps':20.0, 'quantizer':'nq'}
imageio.mimsave('./chevere.gif', [plot_for_offset(i, datos) for i in range(1,80)], fps=20)
