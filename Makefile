
CPPFLAGS=-g3 -Wall -DDEBUG
#CPPFLAGS=-O3 -Wall

TAGETS=hit.o ghit.o chit.o widget.o container.o fallback.o string.o

all: main

main: $(TAGETS)

hit.o: hit.h hit.cpp

clean:
	@rm -f *.o main
