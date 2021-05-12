TARGET_EXEC ?= a.out

FLAGS ?= -std=c++20 -pedantic-errors -Wall -O3

$(TARGET_EXEC): main.cpp menu.o book.o customer.o library.o
	g++ $(FLAGS) $^ -o $@


menu.o: menu.cpp menu.h
	g++ $(FLAGS) $< -o $@ -c

book.o: book.cpp book.h
	g++ $(FLAGS) $< -o $@ -c

customer.o: customer.cpp customer.h
	g++ $(FLAGS) $< -o $@ -c

library.o: library.cpp library.h
	g++ $(FLAGS) $< -o $@ -c

clean:
	find . -type f -name '*.o' -delete
	rm a.out
