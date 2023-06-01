CC = g++
CFLAGS = -Wall -pedantic -std=c++11

programa: main.o abb.o
	$(CC) $(CFLAGS) main.o abb.o -o programa

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

abb.o: abb.cpp
	$(CC) $(CFLAGS) -c abb.cpp

clean:
	rm *.o programa