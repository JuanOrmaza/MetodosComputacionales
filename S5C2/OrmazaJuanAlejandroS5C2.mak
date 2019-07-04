all: a.out datos.txt grafica.py

a.out: OrmazaJuanAlejandroS5C2.cpp
	g++ OrmazaJuanAlejandroS5C2.cpp
    
datos.txt: a.out
	./a.out > datos.txt

grafica.py: datos.txt
	python grafica.py
