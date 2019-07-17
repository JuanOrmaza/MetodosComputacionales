#Ejercicio 0
#Lean el capitulo 5 del Landau (ver el programa del curso).

import numpy as np
import matplotlib.pyplot as plt

#Ejercicio 1
# Usando los generadores de numeros aleatorios de numpy (https://docs.scipy.org/doc/numpy-1.15.1/reference/routines.random.html):
# a) Genere 1000 numeros aleatorios que sigan una distribucion uniforme y esten entre -10 y 10. Haga un histograma y guardelo sin mostrarlo en un archivo llamado uniforme.pdf

numal=np.random.uniform(-10,10,1000)
plt.figure(figsize=(10,10))
plt.hist(numal, 40, density=True)
plt.title("Distribucion uniforme")
plt.savefig("uniform.pdf")

# a) Genere 1000 numeros aleatorios que sigan una distribucion gausiana centrada en 17 y de sigma 5. Haga un histograma y guardelo sin mostrarlo en un archivo llamado gausiana.pdf

mu, sigma = 17, 5 
numgaus =np.random.normal(mu, sigma, 1000)
plt.clf()
plt.figure(figsize=(10,10))
plt.hist(numgaus, 40, density=True)
plt.title("Distribucion gausiana")
plt.savefig("gausiana.pdf")



# Ejercicio 2
# Escriba un programa en Python que: 
# Genere puntos aleatorios distribuidos uniformemente dentro de un cuadrado de lado 30.5. Grafique sus puntos y guarde la grafica sin mostrarla en un archivo llamado cuadrado.pdf. 

unx=np.random.uniform(0,30.5,1000)
uny=np.random.uniform(0,30.5,1000)
plt.clf()
plt.figure(figsize=(10,10))
plt.scatter(unx,uny)
plt.title("cuadrado con distribucion uniforme")
plt.savefig("cuadrado.pdf")

# Genere puntos aleatorios distribuidos uniformemente dentro de circulo de radio 23. Grafique sus puntos y guarde la grafica sin mostrarla en un archivo llamado circulo.pdf. 

unx2=np.random.uniform(-30,30,2000)
uny2=np.random.uniform(-30,30,2000)
x3=[]
y3=[]
for i in range(unx2.size):
    if(((unx2[i]**2+uny2[i]**2)**(1/2))<23):
        x3.append(unx2[i])
        y3.append(uny2[i])
plt.clf()
plt.figure(figsize=(10,10))
plt.scatter(x3,y3,s=1.7)
plt.title("circulo con distribucion uniforme")
plt.savefig("circulo.pdf")

# Ejercicio 3 
# Lean sobre caminatas aleatorias.

# Ejercicio 4
# Tome los puntos distribuidos aleatoriamente dentro del cuadrado y haga que cada punto siga una caminata aleatoria de 100 pasos. 
# La magnitud de los pasos de esta caminata debe seguir una distribucion gaussiana centrada en el punto y de sigma igual a 0.25
# Implemente condiciones de frontera periodicas: si un punto se "sale" de cuadrado por un lado, "entra" por el otro 

xfin=[]
yfin=[]
for i in range(unx.size):
    puntox=unx[i]
    puntoy=uny[i]
    for j in range(100):
        pasx= np.random.normal(0, 0.25, 1)
        pasy= np.random.normal(0, 0.25, 1)
        puntox+=pasx[0]
        if(puntox>30.5):
            puntox-=30.5
        if(puntox<0):
            puntox+=30.5
        puntoy+=pasy[0]
        if(puntoy>30.5):
            puntoy-=30.5
        if(puntoy<0):
            puntoy+=30.5
                    
    xfin.append(puntox)
    yfin.append(puntoy)
    


# Grafique la distribucion final de puntos y guarde dicha grafica sin mostrarla en un archivo llamado DistCaminata.pdf

plt.clf()
plt.figure(figsize=(10,10))
plt.scatter(xfin,yfin)
plt.title("cuadrado con distribucion uniforme despues de caminatas")
plt.savefig("DistCaminata.pdf")

# Grafique la caminata de UNO de sus puntos y guarde dicha grafica sin mostrarla en un archivo llamado puntoCaminata.pdf

xpunto=[]
ypunto=[]
num= np.random.randint(0,1000,1)
xinit=unx[num[0]]
yinit=uny[num[0]]

for j in range(100):
    pasox= np.random.normal(0, 0.25, 1)
    pasoy= np.random.normal(0, 0.25, 1)
    
    xinit+=pasox[0]
    if(xinit>30.5):
        xinit-=30.5
    if(xinit<0):
        xinit+=30.5
        
    yinit+=pasoy[0]
    if(yinit>30.5):
        yinit-=30.5
    if(yinit<0):
        yinit+=30.5
        
        
    xpunto.append(xinit)
    ypunto.append(yinit)
    


plt.clf()
plt.figure(figsize=(10,10))
plt.plot(xpunto,ypunto,ls='--')
plt.title("caminata para punto aleatorio")
plt.savefig("puntoCaminata.pdf")


# Repita el proceso para sigma = 0.00025 y sigma= 2.5. Grafique la caminata de UNO de sus puntos para los distintos sigmas y guardela sin mostrarla en sigmaCaminata.pdf

xpunto1=[]
ypunto1=[]
xpunto2=[]
ypunto2=[]
xinit1=unx[10]
yinit1=uny[10]
xinit2=unx[10]
yinit2=uny[10]

for j in range(100):
    pasox= np.random.normal(0, 2.5, 1)
    pasoy= np.random.normal(0, 2.5, 1)
    
    xinit1+=pasox[0]
    if(xinit1>30.5):
        xinit1-=30.5
    if(xinit1<0):
        xinit1+=30.5
        
    yinit1+=pasoy[0]
    if(yinit1>30.5):
        yinit1-=30.5
    if(yinit1<0):
        yinit1+=30.5
        
        
    xpunto1.append(xinit1)
    ypunto1.append(yinit1)
    
for j in range(100):
    pasox= np.random.normal(0, 0.00025, 1)
    pasoy= np.random.normal(0, 0.00025, 1)
    
    xinit2+=pasox[0]
    if(xinit2>30.5):
        xinit2-=30.5
    if(xinit2<0):
        xinit2+=30.5
        
    yinit2+=pasoy[0]
    if(yinit2>30.5):
        yinit2-=30.5
    if(yinit2<0):
        yinit2+=30.5
        
        
    xpunto2.append(xinit2)
    ypunto2.append(yinit2)
    


plt.clf()
plt.figure(figsize=(10,10))
plt.plot(xpunto1,ypunto1,ls='--',label="sigma=2.5",c="blue")
plt.plot(xpunto2,ypunto2,ls='--',label="sigma=0.00025",c="red")
plt.legend()
plt.title("caminata para punto aleatorio con sigmas distintos")
plt.savefig("sigmaCaminata.pdf")

# Repita el proceso para condiciones abiertas: si un punto se "sale" del cuadrado deja de ser considerado en la simulacion.


# Si le queda tiempo puede:

##################################################################################################################################################################
############################################################ Ejercicio  ##########################################################################
##################################################################################################################################################################

#difusion: una gota de crema en un Cafe.
#
#Condiciones iniciales:
#Cafe: 10000 particulas distribuidas uniformemente dentro de un circulo de radio igual a raiz de 230
#Crema: 100 particulas distribuidas uniformemente dentro de un circulo de radio igual a raiz de 2
#
#Nota: si su codigo se esta demorando mucho en correr, puede usar 1000 particulas de cafe en vez de 10000.
#
# 1) Haga una grafica de las condiciones iniciales donde los dos tipos de particulas tengan distintos colores. Guarde dicha grafica sin mostrarla en CafeLecheIni.pdf

#cafe
cafx=np.random.uniform(-236**0.5,236**0.5,10000)
cafy=np.random.uniform(-236**0.5,236**0.5,10000)
#crema
cremx=np.random.uniform(-2.1**0.5,2.1**0.5,100)
cremy=np.random.uniform(-2.1**0.5,2.1**0.5,100)

xcaf=[]
ycaf=[]
xcrem=[]
ycrem=[]

#filtro 1
for i in range(cafx.size):
    if(((cafx[i]**2+cafy[i]**2)**(1/2))<235**0.5):
        xcaf.append(cafx[i])
        ycaf.append(cafy[i])
#filtro 2
for i in range(cremx.size):
    if(((cremx[i]**2+cremy[i]**2)**(1/2))<2**0.5):
        xcrem.append(cremx[i])
        ycrem.append(cremy[i])

        
plt.clf()
plt.figure(figsize=(10,10))
plt.scatter(xcaf,ycaf,s=1.7,c='saddlebrown',label='cafe')
plt.scatter(xcrem,ycrem,s=1.7,c='black',label='crema')
plt.title("cafe con crema")
plt.legend()
plt.savefig("CafeLecheIni.pdf")




#2) Todas las particulas deben hacer una caminata aleatoria de 1000 pasos. Los pasos en las coordenadas x y deben seguir una distribucion gausiana de sigma 2.5. Si va a usar coordenadas polares elija un sigma apropiado.

#3) Condiciones de frontera: implemente unas condiciones tales que si la particulas "sale" del circulo, usted vuelva a dar el paso. Si no puede implementar solo las condiciones antes descritas, debe al menos escribir comentarios explicando que hace cada linea de codigo de las condiciones propuestas (comentado abajo)

cafefinx=[]
cafefiny=[]
cremfinx=[]
cremfiny=[]

for i in range(len(xcaf)):
    pcafx=xcaf[i]
    pcafy=ycaf[i]
    for j in range(1000):
        pasx= np.random.normal(0, 2.5, 1)
        pasy= np.random.normal(0, 2.5, 1)
        
        pcafx+=pasx[0]
        pcafy+=pasy[0]
        
        if((pcafx**2+pcafy**2)>230**0.5):
            pcafx-=pasx[0]
            pcafy-=pasy[0]
            
    cafefinx.append(pcafx)
    cafefiny.append(pcafy)                
    
for i in range(len(xcrem)):
    pcremx=xcrem[i]
    pcremy=ycrem[i]
    for j in range(1000):
        pasx= np.random.normal(0, 2.5, 1)
        pasy= np.random.normal(0, 2.5, 1)
        
        pcremx+=pasx[0]
        pcremy+=pasy[0]
                
        if((pcremx**2+pcremy**2)>230**0.5):
            pcremx-=pasx[0]
            pcremy-=pasy[0]
            
    cremfinx.append(pcremx)
    cremfiny.append(pcremy)
    

# 4) Haga una grafica de las posiciones finales de las particulas despues de la caminata donde los dos tipos de particulas tengan distintos colores. Guarde dicha grafica sin mostrarla en CafeLecheFin.pdf


plt.clf()
plt.figure(figsize=(10,10))
plt.scatter(cafefinx,cafefiny,c='saddlebrown')
plt.scatter(cremfinx,cremfiny,c='black')
plt.title("cafe con crema despues de caminatas")
plt.savefig("CafeLecheFin.pdf")


import numpy as np
import matplotlib.pylab as plt


#Una posible implementacion de condiciones de frontera. Trate de hacer la suya propia sin usar esta. 
#Si usa esta (obtiene menos puntos) debe comentar cada una de las lineas explicando en palabras que hace el codigo. Debe tambien naturalmente usar los nombres de variables que uso en el resto de su codigo propio.
#indexcafe=np.where((xcafenuevo*xcafenuevo+ycafenuevo*ycafenuevo)>230)
#indexcrema=np.where((xcremanuevo*xcremanuevo+ycremanuevo*ycremanuevo)>230)
#while(len(indexcafe[0])>1):
#	xcafenuevo[indexcafe]=xcafe[indexcafe] + np.random.normal(0,sigma)
#	ycafenuevo[indexcafe]=ycafe[indexcafe] + np.random.normal(0,sigma)
#	indexcafe=np.where((xcafenuevo*xcafenuevo+ycafenuevo*ycafenuevo)>=230)
#while(len(indexcrema[0])>1):
#	xcremanuevo[indexcrema]=xcrema[indexcrema] + np.random.normal(0,sigma)
#	ycremanuevo[indexcrema]=ycrema[indexcrema] + np.random.normal(0,sigma)
#	indexcrema=np.where((xcremanuevo*xcremanuevo+ycremanuevo*ycremanuevo)>=230) 



	
