all :	soldier.o
	g++ -g -pedantic-errors main.cpp soldier.o
soldier.o : soldier.h soldier.cpp
	g++ -g -pedantic-errors soldier.cpp -o soldier.o -c
clean :
	rm a.out