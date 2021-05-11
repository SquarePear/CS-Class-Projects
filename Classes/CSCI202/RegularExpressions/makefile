TARGET_EXEC ?= a.out

FLAGS ?= -std=c++20 -pedantic-errors -Wall -O3

$(TARGET_EXEC): main.cpp
	g++ $(FLAGS) $^ -o $@

clean:
	find . -type f -name '*.o' -delete
	rm a.out
