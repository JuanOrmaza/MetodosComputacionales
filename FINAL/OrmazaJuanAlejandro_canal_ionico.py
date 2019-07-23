import matplotlib.pyplot as plt
import numpy as np

datos=np.genfromtxt("Canal_ionico.txt")

def area(r):
    return np.pi*r**2

xguess=np.mean(datos[:,0])
yguess=np.mean(datos[:,1])
rguess=0.1
pasos=1000
sigmax,sigmay,sigmar=0.01,0.01,0.1

def MCMC(xg,yg,rg,pasos,sigmax,sigmay,sigmar,datx,daty):
    xnuevos=[]
    ynuevos=[]
    rnuevos=[]
    xviejo=xg
    yviejo=yg
    rviejo=rg
    for i in range(pasos):
        xnuevo=np.random.normal(xviejo,sigmax,1)[0]
        ynuevo=np.random.normal(yviejo,sigmay,1)[0]
        rnuevo=np.random.normal(rviejo,sigmar,1)[0]
        alfa=area(rnuevo)/area(rviejo)
        distr=1000
        for j in range(len(datx)):
            calculor=((datx[j]-xnuevo)**2+(daty[j]-ynuevo)**2)**0.5
            if(calculor<distr):
                distr=calculor
        if(alfa>1 and area(rnuevo)<area(distr)):
            xnuevos.append(xnuevo)
            ynuevos.append(ynuevo)
            rnuevos.append(rnuevo)
            xviejo=xnuevo
            yviejo=ynuevo
            rviejo=rnuevo
        else:
            beta=np.random.uniform(0,1,1)[0]
            if(beta<alfa and area(rnuevo)<area(distr)):
                xnuevos.append(xnuevo)
                ynuevos.append(ynuevo)
                rnuevos.append(rnuevo)
                xviejo=xnuevo
                yviejo=ynuevo
                rviejo=rnuevo
            elif(beta>alfa and area(rviejo)<area(distr)):
                xnuevos.append(xviejo)
                ynuevos.append(yviejo)
                rnuevos.append(rviejo)
    ropt=0
    xopt=0
    yopt=0
    tam=len(xnuevos)
    for k in range(tam):
        for j in range(len(datx)):
            calculor=((datx[j]-xnuevos[k])**2+(daty[j]-ynuevos[k])**2)**0.5
            if(area(calculor)>area(rnuevos[k]) and rnuevos[k]>ropt):
                ropt=rnuevos[k]
                xopt=xnuevos[k]
                yopt=ynuevos[k]
        
    return ropt, xopt, yopt


x,y,r=MCMC(xguess,yguess,rguess,pasos,sigmax,sigmay,sigmar,datos[:,0],datos[:,1])
plt.figure()
fig, ax = plt.subplots()
plt.axis('equal')
circle1 = plt.Circle((x, y), r, color='r',fill=False)
ax.add_artist(circle1)
plt.scatter(x,y)
plt.scatter(datos[:,0],datos[:,1])
plt.savefig("Canal.png")

            
            
            
            
            
            
            
            
            
            
            
            
            
            
            