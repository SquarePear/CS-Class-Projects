TARGET_EXEC ?= a.out

FLAGS ?= -std=c++2a -pedantic-errors

$(TARGET_EXEC): main.cpp television.o
	g++ $(FLAGS) $^ -o $@

television.o: television.cpp television.h
	g++ $(FLAGS) $< -o $@ -c

clean:
	find . -type f -name '*.o' -delete
	rm a.out
