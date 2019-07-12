all: a.out datos.txt Difusion.cpp Plots_Difusion.py clean1 clean2

a.out: Difusion.cpp
	g++ Difusion.cpp
    
datos.txt: a.out
	./a.out

Plots_Difusion.py: datos.txt
	python Plots_Difusion.py

clean1 :
	rm -f *.txt

clean2 :
	rm a.out