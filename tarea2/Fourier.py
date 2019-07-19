import numpy as np
import matplotlib.pylab as plt
from scipy.fftpack import fft, fftfreq, ifft2, fft2

cara1=plt.imread('cara_02_grisesMF.png')
cara2=plt.imread('cara_03_grisesMF.png')

trans1=np.fft.fft2(cara1)
trans2=np.fft.fft2(cara2)
frec1=np.fft.fftshift(trans1)
frec2=np.fft.fftshift(trans1)

from matplotlib.colors import LogNorm
plt.clf()
plt.figure(figsize=(20,16))
plt.suptitle("Transformadas de fourier", fontsize=20)
plt.subplot(1,2,1)
plt.title("cara 1 FFT")
plt.imshow(abs(trans1),norm=LogNorm())
plt.colorbar()
plt.subplot(1,2,2)
plt.title("cara 2 FFT")
plt.imshow(abs(trans2),norm=LogNorm())
plt.colorbar()
plt.savefig('FFtIm.png')

def filtroaltas(b,c):
    tam=np.shape(b)
    for i in range(tam[0]):
        for j in range(tam[1]):
            if abs(b[i,j])<c:
                b[i,j]=0
    return b

def filtrobajas(b,c):
    tam=np.shape(b)
    for i in range(tam[0]):
        for j in range(tam[1]):
            if abs(b[i,j])>c:
                b[i,j]=0
    return b


filtro1=filtrobajas(trans1,30)
filtro2=filtroaltas(trans2,70)

plt.clf()
plt.figure(figsize=(10,8))
plt.suptitle("frecuencias y filtros", fontsize=20)
plt.subplot(2,2,1)
plt.title(" frecuencias cara 1")
plt.imshow(abs(frec1),norm=LogNorm())
plt.colorbar()
plt.subplot(2,2,2)
plt.title("frecuencias cara 2")
plt.imshow(abs(frec2),norm=LogNorm())
plt.colorbar()
plt.subplot(2,2,3)
plt.title("cara 1 filtrada")
plt.imshow(abs(filtro1),norm=LogNorm())
plt.colorbar()
plt.subplot(2,2,4)
plt.title("cara 2 filtrada")
plt.imshow(abs(filtro2),norm=LogNorm())
plt.colorbar()
plt.savefig('fImProceso.png')

imagensuma=np.fft.ifftshift(filtro1)+np.fft.ifftshift(filtro2)
imagen=ifft2(imagensuma)

plt.clf()
plt.figure(figsize=(10,10))
plt.title("imagen hibrida")
plt.imshow(abs(imagen),norm=LogNorm(),cmap='gray')
plt.savefig("ImHybrid.png")

