TARGET_EXEC ?= a.out

FLAGS ?= -g -pedantic-errors

$(TARGET_EXEC): main.cpp beverage.o coffee.o energydrink.o soda.o tea.o
	g++ $(FLAGS) $^ -o $@

beverage.o: beverage.cpp beverage.h
	g++ $(FLAGS) $< -o $@ -c

coffee.o: coffee.cpp coffee.h beverage.o
	g++ $(FLAGS) $< -o $@ -c

energydrink.o: energydrink.cpp energydrink.h beverage.o
	g++ $(FLAGS) $< -o $@ -c

soda.o: soda.cpp soda.h beverage.o
	g++ $(FLAGS) $< -o $@ -c

tea.o: tea.cpp tea.h beverage.o
	g++ $(FLAGS) $< -o $@ -c

clean:
	find . -type f -name '*.o' -delete
	rm a.out