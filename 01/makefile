FLAGS += -O2 -Werror -std=c++14 -fsanitize=undefined
.PHONY: all clean run test

all: main

main: main.o
	g++ $< $(FLAGS) -o $@

main.o: task2.cpp
	g++ $< $(FLAGS) -c -o $@

run:
	./main

test:
	python3 ./check.py

clean:
	rm -rf *.o
