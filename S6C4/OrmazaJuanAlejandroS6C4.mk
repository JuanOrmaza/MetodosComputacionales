all: a.out datos.txt Difusion.cpp Plots_Difusion.py

a.out: Difusion.cpp
	g++ Difusion.cpp
    
datos.txt: a.out
	./a.out

Plots_Difusion.py: datos.txt
	python Plots_Difusion.py
