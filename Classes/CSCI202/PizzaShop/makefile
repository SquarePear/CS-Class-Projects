TARGET_EXEC ?= a.out

FLAGS ?= -std=c++2a -pedantic-errors -Wall -O3

$(TARGET_EXEC): main.cpp pizza.o
	g++ $(FLAGS) $^ -o $@

pizza.o: pizza.cpp pizza.h
	g++ $(FLAGS) $< -o $@ -c

clean:
	find . -type f -name '*.o' -delete
	rm a.out
