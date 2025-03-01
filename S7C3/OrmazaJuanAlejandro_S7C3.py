#Ejercicio 1 Terminar lo que hizo en clase + dos preguntas adicionales (en mayusculas en el texto)

import numpy as np
import matplotlib.pylab as plt


# 1) lea los datos de resorte.dat y almacenelos.
# 
datos=np.genfromtxt("resorte.dat")
temp=datos[:,0]
xes=datos[:,1]
# Los datos corresponden a las posiciones en x de un oscilador (masa resorte) en funcion del tiempo. La ecuacion de movimiento esta dada por  
# xt=a*np.exp(-gamma*t)*np.cos(omega*t)
# Donde a, gamma, y omega son parametros.

# 2) Implemente un algoritmo que le permita, por medio de estimacion bayesiana de parametros, encontrar los parametros correspondientes a los datos d. Para esto debe:

# 2a.) definir una funcion que reciba los parametros que se busca estimar y los datos de tiempo y retorne el modelo  

def funcion(a,b,c,t):
    xt=a*np.exp(-b*t)*np.cos(c*t)
    return xt

# 2b.) Definir una funcion que retorne la funcion de verosimilitud

def vero(a,b):
    chicuad=np.sum((a-b)**2)
    vr=np.exp(-0.5*chicuad)
    return vr

# 2c.) Caminata

def caminata(sigma1, sigma2, sigma3, ainit, gammainit, omegainit, pasos):
    anuevos=[]
    gammas=[]
    omegas=[]
    aguess=ainit
    gamguess=gammainit
    omegaguess=omegainit
    for i in range(pasos):
        anuevo=np.random.normal(aguess,sigma1,1)[0]
        gnuevo=np.random.normal(gamguess,sigma2,1)[0]
        onuevo=np.random.normal(omegaguess,sigma3,1)[0]
        alfa=vero(xes,funcion(anuevo,gnuevo,onuevo,temp))/vero(xes,funcion(aguess,gamguess,omegaguess,temp))
        if(alfa>1):
            anuevos.append(anuevo)
            gammas.append(gnuevo)
            omegas.append(onuevo)
            aguess=anuevo
            gamguess=gnuevo
            omegaguess=onuevo
        elif(alfa<1):
            beta=np.random.uniform(0,1,1)[0]
            if(beta<alfa):
                anuevos.append(anuevo)
                gammas.append(gnuevo)
                omegas.append(onuevo)
                aguess=anuevo
                gamguess=gnuevo
                omegaguess=onuevo
            if(beta>alfa):
                anuevos.append(aguess)
                gammas.append(gamguess)
                omegas.append(omegaguess)
    
    apropio=0
    gampropio=0
    ompropio=0
    lact=0
    for i in range(len(anuevos)):
        l=vero(xes,funcion(anuevos[i],gammas[i],omegas[i],temp))
        if(l>lact):
            apropio=anuevos[i]
            gampropio=gammas[i]
            ompropio=omegas[i]
            lact=l
    return apropio,gampropio,ompropio

#condiciones iniciales
aini=7.5
gammaini=0.6
omegaini=18.2
sigma1=1
sigma2=1
sigma3=1
#numero de pasos
iteraciones=100000

al,gam,om=caminata(sigma1, sigma2, sigma3, aini, gammaini, omegaini, iteraciones)


# 2d.) Seleccione los mejores parametros E IMPRIMA UN MENSAJE QUE DIGA: "LOS MEJORES PARAMETROS SON a=... gamma=... Y omgega=..."

print("Los mejores parametros son a= ", al,"gamma= ", gam," y omega= ",om)

# 2f.) Grafique sus datos originales y su modelo con los mejores parametros. Guarde su grafica sin mostrarla en Resorte.pdf

plt.figure()
plt.plot(temp,xes,label='datos observados')
plt.plot(temp,funcion(al,gam,om,temp),label='modelo resorte')
plt.title("Datos vs modelo (Resorte)")
plt.legend()
plt.savefig("Resorte.pdf")

# 3) SABIENDO QUE omega=np.sqrt(k/m), IMPRIMA UN MENSAJE DONDE EXPLIQUE SI PUEDE O NO DETERMINAR k Y m DE MANERA INDIVIDUAL USANDO EL METODO ANTERIOR. JUSTIFIQUE BIEN SU RESPUESTA (PUEDE ADEMAS HACER PRUEBAS CON EL CODIGO PARA RESPONDER ESTA PREGUNTA).

print("Si se sabe que omega=sqrt(k/m), no es posible determinar k y m de manera individual. La razon por la cual no se puede determinar es porque, aunque se sepa el valor de omega, k y m son desconocidos. Adicionalmente, la relacion k/m puede ser cumplida por multiples materiales, masas, resortes y/o disposiciones de los resortes.")











