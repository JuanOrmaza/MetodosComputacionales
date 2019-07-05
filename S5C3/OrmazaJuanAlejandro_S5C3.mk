all: a.out datos.txt OrmazaJuanAlejandro_S5C3_plots.py

a.out: OrmazaJuanAlejandro_S5C3_ODEs.cpp
	g++ OrmazaJuanAlejandro_S5C3_ODEs.cpp
    
datos.txt: a.out
	./a.out > datos.txt

OrmazaJuanAlejandro_S5C3_plots.py: datos.txt
	python OrmazaJuanAlejandro_S5C3_plots.py
