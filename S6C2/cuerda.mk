all: a.out datos.txt OrmazaJuanAlejandro_cuerda.cpp

a.out: OrmazaJuanAlejandro_cuerda.cpp
	g++ OrmazaJuanAlejandro_cuerda.cpp
    
datos.txt: a.out
	./a.out > datos.txt

Plots_cuerda.py: datos.txt
	python Plots_cuerda.py
