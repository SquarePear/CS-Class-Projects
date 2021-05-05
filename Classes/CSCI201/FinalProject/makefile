TARGET_EXEC ?= a.out

FLAGS ?= -std=c++20 -pedantic-errors

$(TARGET_EXEC): main.cpp game.o tank.o wall.o
	g++ $(FLAGS) $^ -o $@

tank.o: tank.cpp tank.h
	g++ $(FLAGS) $< -o $@ -c
game.o: game.cpp game.h
	g++ $(FLAGS) $< -o $@ -c
wall.o: wall.cpp wall.h
	g++ $(FLAGS) $< -o $@ -c

clean:
	find . -type f -name '*.o' -delete
	rm a.out