EXE = mutual.o
CC = g++
CFLAGS = -std=c++11 -pthread -o
DEBUGFLAG = -g -std=c++11 -pthread -o
HFILES= semaphore.h
CFILES = mutual.cpp

all:
	$(CC) $(CFLAGS) $(EXE) $(CFILES)
clean:
	rm *.o
debug:
	$(CC) $(DEBUGFLAG) $(EXE) $(CFILES)
