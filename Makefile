CC = g++
CFLAGS = -Wall -pedantic -std=c++11

programa: main.o abb.o avl.o heapsort.o
	$(CC) $(CFLAGS) main.o abb.o avl.o heapsort.o -o programa

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

abb.o: abb.cpp
	$(CC) $(CFLAGS) -c abb.cpp

avl.o: avl.cpp
	$(CC) $(CFLAGS) -c avl.cpp

heapsort.o: heapsort.cpp
	$(CC) $(CFLAGS) -c heapsort.cpp

clean:
	rm *.o programa