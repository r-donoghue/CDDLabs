CC = g++
CFLAGS = -std=c++11 -pthread
CFILES = proCons.cpp

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: $(CFILES)
	$(CC) -o proCons $(CFILES) $(CFLAGS) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL

CLEAN:
	rm *.o
