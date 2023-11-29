CC = g++
CFLAGS = -Wall
LIBS = -lsimlib

main: src/main.cpp
	$(CC) src/main.cpp $(CFLAGS) $(LIBS) -o main.out

clean:
	rm -fr main.out