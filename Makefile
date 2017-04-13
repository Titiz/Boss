COMPILER=g++
LIBINCLUDE=./include/
LDFLAGS=-lsfml-window -lsfml-graphics -lanax -lsfml-system

all:
	mkdir -p build 
	$(COMPILER) -c src/main.cpp -std=c++11 -I $(LIBINCLUDE) -o build/main.o
	$(COMPILER) -o build/main.o $(LDFLAGS) -Wall 

clean:
	rm -r build
