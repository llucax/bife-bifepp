
CPPFLAGS=-g3 -Wall -I/usr/include/libxml++-1.0 -I/usr/include/libxml2 -DDEBUG
#CPPFLAGS=-O3 -Wall -I/usr/include/libxml++-1.0 -I/usr/include/libxml2

LDFLAGS=-lxml++-0.1 #-lxml

TAGETS=hit.o ghit.o chit.o widget.o container.o fallback.o string.o translate.o parser.o

all: main

main: $(TAGETS)

parser_test: $(TAGETS)

hit.o: hit.h hit.cpp

clean:
	@rm -f *.o main parser_test
