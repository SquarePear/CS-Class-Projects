TARGET_EXEC ?= a.out

FLAGS ?= -std=c++20 -pedantic-errors -Wall -O3

$(TARGET_EXEC): main.cpp package.o
	g++ $(FLAGS) $^ -o $@

package.o: package.cpp package.h
	g++ $(FLAGS) $< -o $@ -c

clean:
	find . -type f -name '*.o' -delete
	rm a.out
