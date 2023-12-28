CC = g++
CFLAGS = -Wall
LIBS = -lsimlib
target = main


all: main

main: src/main.cpp
	$(CC) src/main.cpp $(CFLAGS) $(LIBS) -o $(target)


run : main
	./$(target)

doc: 
	$(MAKE) -C doc

clean:
	rm -fr main.out
