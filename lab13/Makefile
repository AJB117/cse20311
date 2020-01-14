project: project.o pokemon.o move.o
	g++ -g project.o pokemon.o move.o gfx2.o -lX11 -std=c++11 -o project

project.o: project.cpp pokemon.h move.h
	g++ -c -g -std=c++11 project.cpp -o project.o

pokemon.o: pokemon.cpp pokemon.h move.h
	g++ -c -g -std=c++11 pokemon.cpp -o pokemon.o

move.o: move.cpp move.h
	g++ -c -g -std=c++11 move.cpp -o move.o

clean:
	rm -f project.o