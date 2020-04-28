#this is a comment line
#first makefile for particle explosion class

run: main.o screen.o
	g++ -o run screen.o main.o -lSDL2

main.o: main.cpp screen.h
	g++ -c main.cpp

screen.o: screen.cpp
	g++ -c screen.cpp -lSDl2

clean:
	rm *.o run
