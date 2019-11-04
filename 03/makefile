FLAGS += -O2 -Werror -std=c++14 -fsanitize=undefined
.PHONY: all clean run test

all: main

main: main.o matrix.o
	g++ $< $(FLAGS) -o $@

main.o: aloc.cpp
	g++ $< $(FLAGS) -c -o $@

matrix.o: matrix.h
		g++ $< $(FLAGS) -c -o $@

run:
	./main

test:
	python3 ./test.py

clean:
	rm -rf *.o
