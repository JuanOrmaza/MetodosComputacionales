all: a.out Fourier.py ODEs.cpp Plots_hw2.py datosrunge3.txt clean1

a.out: ODEs.cpp
	g++ ODEs.cpp
    
datosrunge3.txt: a.out
	./a.out

Plots_hw2.py: datosrunge3.txt
	python Plots_hw2.py
	python Fourier.py

clean1 :
	rm a.out