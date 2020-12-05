TARGET_EXEC ?= a.out

FLAGS ?= -std=c++2a -pedantic-errors

$(TARGET_EXEC): main.cpp player.o offense.o defense.o special.o
	g++ $(FLAGS) $^ -o $@

player.o: player.cpp player.h
	g++ $(FLAGS) $< -o $@ -c
offense.o: offense.cpp offense.h
	g++ $(FLAGS) $< -o $@ -c
defense.o: defense.cpp defense.h
	g++ $(FLAGS) $< -o $@ -c
special.o: special.cpp special.h
	g++ $(FLAGS) $< -o $@ -c

clean:
	find . -type f -name '*.o' -delete
	rm a.out