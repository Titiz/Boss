TARGET=main
COMPILER=g++
LIBINCLUDE=include/
LDFLAGS=-lsfml-window -lsfml-graphics -lanax -lsfml-system

all:
	$(COMPILER) -c src/$(TARGET).cpp -std=c++11 -I $(LIBINCLUDE) -o build/main.o
	$(COMPILER) build/$(TARGET).o -Wall $(LDFLAGS) -o $(TARGET)   

clean:
	rm -r build
