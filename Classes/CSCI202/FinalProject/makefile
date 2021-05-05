TARGET_EXEC ?= a.out

FLAGS ?= -std=c++20 -pedantic-errors -Wall -O3

$(TARGET_EXEC): main.cpp book.o customer.o library.o
	g++ $(FLAGS) $^ -o $@

book.o: book.cpp book.h
	g++ $(FLAGS) $< -o $@ -c

customer.o: customer.cpp customer.h
	g++ $(FLAGS) $< -o $@ -c

library.o: library.cpp library.h
	g++ $(FLAGS) $< -o $@ -c

clean:
	find . -type f -name '*.o' -delete
	rm a.out
