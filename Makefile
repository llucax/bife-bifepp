
DEBUG=-g3 -DDEBUG -Wall
#CPPFLAGS=-g3 -Wall -I/usr/include/libxml++-1.0 -I/usr/include/libxml2 -DDEBUG
#CPPFLAGS=-O3 -Wall -I/usr/include/libxml++-1.0 -I/usr/include/libxml2

TAGETS=hit.o ghit.o chit.o widget.o container.o fallback.o string.o

all: parser_test

main: $(TAGETS)


CPPFLAGS=-fPIC $(DEBUG)

hit.o: hit.h hit.cpp
ghit.o: hit.o ghit.h ghit.cpp
chit.o: ghit.o chit.h chit.cpp

widget.o: widget.h widget.cpp
string.o: widget.o string.h string.cpp
container.o: widget.o container.h container.cpp
fallback.o: container.o fallback.h fallback.cpp

translate.o: translate.h translate.cpp
translate_loader.o: translate_loader.cpp
#.o: .o .h .cpp

# LIBBIFE
LIBBIFE_TARGETS=hit.o ghit.o chit.o widget.o string.o container.o fallback.o
libbife.so: $(LIBBIFE_TARGETS)
	$(CXX) $(DEBUG) -Wl,-soname,libbife.so -shared -o libbife.so $(LIBBIFE_TARGETS)

# TRANSLATE FALLBACK PLUG-IN
TRANSLATE_TARGETS=translate.o translate_loader.o
translate.so: libbife.so $(TRANSLATE_TARGETS)
	$(CXX) $(DEBUG) -L. -lbife -Wl,-soname,translate.so -shared -o translate.so $(TRANSLATE_TARGETS)


# Parser example.
PARSER_FLAGS=-I/usr/include/libxml++-1.0 -I/usr/include/libxml2
parser.o: parser.h parser.cpp
	$(CXX) $(DEBUG) $(PARSER_FLAGS) -c parser.cpp
parser_test.o: parser_test.cpp
	$(CXX) $(DEBUG) $(PARSER_FLAGS) -c parser_test.cpp

PARSER_TARGETS=parser.o parser_test.o
parser_test: translate.so $(PARSER_TARGETS)
	$(CXX) $(DEBUG) $(PARSER_FLAGS) -L. -lxml++-0.1 -ldl -lbife -o parser_test $(PARSER_TARGETS)
	@echo
	@echo ----------------------------------------------
	@echo export LD_LIBRARY_PATH=.
	@echo to use ./parser_test

clean:
	@rm -f *.o main parser_test
