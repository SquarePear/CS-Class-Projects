all :	nerfgun.o main.cpp
	g++ -g -pedantic-errors main.cpp nerfgun.o
nerfgun.o : nerfgun.h nerfgun.cpp
	g++ -g -pedantic-errors nerfgun.cpp -o nerfgun.o -c
clean :
	rm a.out