all: a.out datos.txt plotsS5C1.py

a.out: S5C1Deriv.cpp
	g++ S5C1Deriv.cpp

datos.txt: a.out
	./a.out

plotsS5C1.py: datos.txt
	python plotsS5C1.py

