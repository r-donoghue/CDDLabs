CC = g++
CFLAGS = -std=c++11 -pthread
HFILES= semaphore.h
CFILES = semaphore.cpp signal.cpp

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: mutual.o
	$(CC) -o mutual mutual.o $(CFLAGS) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL

CLEAN:
	rm *.o
