import numpy as np
import matplotlib.pyplot as plt
import imageio

datos= np.genfromtxt('datos.txt',delimiter=",")
print(np.shape(datos))
x=datos[0,1:201]

def plot_for_offset(i, datos):
    amp=datos[i,1:201]
    t=datos[1:1201,0]
    dt=datos[2,0]-datos[1,0]

    fig, ax = plt.subplots(figsize=(10,5))
    ax.plot(t, amp)
    ax.grid()
    ax.set(xlabel='tiempo ={}'.format(i*dt), ylabel='Amplitud',
           title='cuerda')

    ax.set_ylim(-0.02, 0.02)

    # Used to return the plot as an image rray
    fig.canvas.draw()       # draw the canvas, cache the renderer
    image = np.frombuffer(fig.canvas.tostring_rgb(), dtype='uint8')
    image  = image.reshape(fig.canvas.get_width_height()[::-1] + (3,))

    return image

kwargs_write = {'fps':20.0, 'quantizer':'nq'}
imageio.mimsave('./chevere.gif', [plot_for_offset(i, datos) for i in range(1,len(datos[:,0])-1)], fps=20)
