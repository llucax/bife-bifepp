// vim: set expandtab tabstop=4 shiftwidth=4:

#include "widget.h"
#include <sstream>

using std::stringstream;
using namespace bife;

#ifdef DEBUG
#include <iostream>
using std::cerr;
using std::endl;
#endif

Widget::Widget(void) {
#ifdef DEBUG
    cerr << "In Widget::Widget();" << endl;
#endif
}

Widget::Widget(Hash attrs): attrs(attrs) {
#ifdef DEBUG
    cerr << "In Widget::Widget(attrs = {" /* TODO << attrs */ << "});" << endl;
#endif
}

Widget::~Widget(void) {
#ifdef DEBUG
    cerr << "In Widget destructor." << endl;
#endif
}

Widget::operator string(void) const {
    stringstream out;
    out << string("widget = attributes: [");
    Hash::const_iterator last = attrs.end();
    last--;
    for (Hash::const_iterator i = attrs.begin(); i != attrs.end(); i++) { //last; i++) {
        out << i->first << ": " << i->second << ", ";
    }
    out << last->first << ": " << last->second << "]";
    return out.str();
}

