all: a.out datos.txt OrmazaJuanAlejandro_cuerdayTambor.cpp Plots_cuerdayTambor.py

a.out: OrmazaJuanAlejandro_cuerdayTambor.cpp
	g++ OrmazaJuanAlejandro_cuerdayTambor.cpp
    
datos.txt: a.out
	./a.out > datos.txt

Plots_cuerdayTambor.py: datos.txt
	python Plots_cuerdayTambor.py
