FLAGS ?= -std=c++2a -pedantic-errors

all: server.out client.out

server.out: server.cpp shared.o
	g++ $(FLAGS) $^ -o $@

client.out: client.cpp shared.o
	g++ $(FLAGS) $^ -o $@

shared.o: shared.cpp shared.h
	g++ $(FLAGS) $< -o $@ -c

clean:
	rm shared.o
	rm server.out
	rm client.out