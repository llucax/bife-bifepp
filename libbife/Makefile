
DEBUG=-Wall #-g3 -DDEBUG
CPPFLAGS=-fPIC $(DEBUG)
LDFLAGS=-shared

all: libbife.so

hit.o: hash.h hit.h hit.cpp
ghit.o: hit.o ghit.h ghit.cpp
chit.o: ghit.o chit.h chit.cpp

widget.o: hit.o widget.h widget.cpp
string.o: widget.o string.h string.cpp
container.o: widget.o container.h container.cpp
fallback.o: container.o fallback.h fallback.cpp

TAGETS=hit.o ghit.o chit.o widget.o string.o container.o fallback.o
libbife.so: $(TAGETS)
	$(CXX) $(DEBUG) $(LDFLAGS) -o libbife.so $(TAGETS)

clean:
	@rm -f *.o libbife.so

