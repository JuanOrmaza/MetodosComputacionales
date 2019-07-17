# Ejercicio 1

import numpy as np
import matplotlib.pylab as plt


# Use esta funcion que recibe un valor x y retorna un valor f(x) donde f es la forma funcional que debe seguir su distribucion. 
def mifun(x):
    x_0 = 3.0
    a = 0.01
    return np.exp(-(x**2))/((x-x_0)**2 + a**2)

def MH(sigma, pasos):
    xnuevos=[]
    xguess=np.random.uniform(-4,4,1)[0]
    for i in range(pasos):
        xnuevo=np.random.normal(xguess,sigma,1)[0]
        alfa=mifun(xnuevo)/mifun(xguess)
        if(alfa>1):
            xnuevos.append(xnuevo)
            xguess=xnuevo
        elif(alfa<1):
            beta=np.random.uniform(0,1,1)[0]
            if(beta<alfa):
                xnuevos.append(xnuevo)
                xguess=xnuevo
            if(beta>alfa):
                xnuevos.append(xguess)
    plt.clf()
    plt.figure()
    plt.hist(xnuevos,100,density=True)
    plt.savefig("histograma_"+str(sigma)+"_"+str(pasos)+".png")       


# Dentro de una funcion que reciba como parametros el numero de pasos y el sigma de la distribucion gausiana que va a usar para calcular el paso de su caminata, implemente el algortimo de Metropolis-Hastings. Finalmente, haga un histograma de los datos obtenidos y grafique en la misma grafica, la funcion de distribucion de probabilidad fx (Ojo, aca debe normalizar). Guarde la grafica sin mostrarla en un pdf. Use plt.savefig("histograma_"+str(sigma)+"_"+str(pasos)+".pdf"), donde sigma y pasos son los parametros que recibe la funcion. 

# Cuando haya verificado que su codigo funciona, use los siguientes parametros:

# sigma = 5, pasos =100000

MH(5,100000)

# sigma = 0.2, pasos =100000

MH(0.2,100000)

# sigma = 0.01, pasos =100000 

MH(0.01,100000)

# sigma = 0.1, pasos =1000 

MH(0.1,1000)

# sigma = 0.1, pasos =100000 

MH(0.1,100000)

# este puede ser muy demorado dependiendo del computador: sigma = 0.1, pasos =500000 

MH(0.1,500000)

# Al ejecutar el codigo, este debe generar 6 (o 5) graficas .pdf una para cada vez que se llama a la funcion.
