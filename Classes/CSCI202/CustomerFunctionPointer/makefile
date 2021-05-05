TARGET_EXEC ?= a.out

FLAGS ?= -std=c++20 -pedantic-errors

$(TARGET_EXEC): main.cpp customer.o
	g++ $(FLAGS) $^ -o $@

customer.o: customer.cpp customer.h
	g++ $(FLAGS) $< -o $@ -c

clean:
	find . -type f -name '*.o' -delete
	rm a.out
