
LIBBIFE_DIR=libbife

DEBUG=-Wall -g3 -DDEBUG
CPPFLAGS=-I/usr/include/libxml++-1.0 -I/usr/include/libxml2 $(DEBUG)
LDFLAGS=-L$(LIBBIFE_DIR) -lxml++-0.1 -ldl -lbife

all: parser_test

# Parser example.
parser.o: parser.h parser.cpp
parser_test.o: parser_test.cpp

parser_test: parser.o parser_test.o

clean:
	@rm -f *.o parser_test

