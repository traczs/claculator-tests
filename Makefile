CC = gcc

all: main run

main: src/main.c src/Calculator.c src/TestCalculator.c include/TestCalculator.h include/Calculator.h
	$(CC) -g -Wall -o bin/Lab2 src/main.c src/Calculator.c src/TestCalculator.c -Iinclude \
	
run: bin/Lab2
	./bin/Lab2

clean:
	rm -f *.o bin/Lab2

