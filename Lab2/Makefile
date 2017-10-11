CC = g++
CFLAGS = -std=c++11 -pthread
HFILES= semaphore.h
CFILES = semaphore.cpp rend.cpp

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: rend.o
	$(CC) -o rend rend.o $(CFLAGS) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL

CLEAN:
	rm *.o
