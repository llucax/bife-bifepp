
LIBBIFE_DIR=../libbife

DEBUG=-Wall #-g3 -DDEBUG
CPPFLAGS=-fPIC $(DEBUG)
LDFLAGS=-L$(LIBBIFE_DIR) -lbife -shared

all: translate.so

translate.o: translate.h translate.cpp
translate_loader.o: translate_loader.cpp

TARGETS=translate.o translate_loader.o
translate.so: $(TARGETS)
	$(CXX) $(DEBUG) $(LDFLAGS) -o translate.so $(TAGETS)

clean:
	@rm -f *.o translate.so

