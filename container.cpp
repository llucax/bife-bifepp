// vim: set expandtab tabstop=4 shiftwidth=4:

#include "container.h"
#include <sstream>

using std::stringstream;
using namespace bife;

#ifdef DEBUG
#include <iostream>
using std::cerr;
using std::endl;
#endif

Container::Container(void) {
#ifdef DEBUG
    cerr << "In Container::Container();" << endl;
#endif
}

Container::Container(Hash attrs): Widget(attrs) {
#ifdef DEBUG
    cerr << "In Container::Container(attrs = {" /* TODO << attrs */ << "});" << endl;
#endif
}

Container::Container(Hash attrs, Widget& content): Widget(attrs) {
    // FIXME - this->content.push_back(content);
#ifdef DEBUG
    cerr << "In Container::Container(attrs = {" /* TODO << attrs */
        << "}, content = {" /* TODO << content */ << "});" << endl;
#endif
}

Container::Container(Widget& content, Hash attrs): Widget(attrs) {
    // FIXME - this->content.push_back(content);
#ifdef DEBUG
    cerr << "In Container::Container(content = {" /* TODO << content */
        << "}, attrs = {" /* TODO << attrs */ << "});" << endl;
#endif
}

Container::~Container(void) {
#ifdef DEBUG
    cerr << "In Container destructor." << endl;
#endif
}

/*
string Container::render(HIT& hit) {
    stringstream out;
    out << "container = attributes: [";
    for (Hash::iterator i = attrs.begin(); i != --attrs.end(); i++) {
        out << i->first << ": " << i->second << ", ";
    }
    Hash::iterator i = --attrs.end();
    out << i->first << ": " << i->second << "] ";
    out << "content: [" << renderContent(hit) << "]";
    return out.str();
}
*/

string Container::renderContent(HIT& hit) {
    stringstream out;
    for (Content::iterator i = content.begin(); i != content.end(); i++) {
        out << i->render(hit);
    }
    return out.str();
}
