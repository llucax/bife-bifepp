// vim: set expandtab tabstop=4 shiftwidth=4:

#include "string.h"
#include <sstream>

using std::stringstream;
using namespace bife;

#ifdef DEBUG
#include <iostream>
using std::cerr;
using std::endl;
#endif
/*
String::String(void) {
#ifdef DEBUG
    cerr << "In String::String()." << endl;
#endif
}*/

String::String(const char* str): string(str) {
#ifdef DEBUG
    cerr << "In String::String('" << str << "')." << endl;
#endif
}

String::~String(void) {
#ifdef DEBUG
    cerr << "In String destructor." << endl;
#endif
}

string String::render(HIT& tpl) {
    return string(this->c_str());
}
