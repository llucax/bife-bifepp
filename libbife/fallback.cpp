// vim: set expandtab tabstop=4 shiftwidth=4:

#include "fallback.h"
#include <sstream>

using std::stringstream;
using namespace bife;

#ifdef DEBUG
#include <iostream>
using std::cerr;
using std::endl;
#endif

Fallback::Fallback(void) {
#ifdef DEBUG
    cerr << "In Fallback::Fallback();" << endl;
#endif
}

Fallback::Fallback(const Hash& attrs): Container(attrs) {
#ifdef DEBUG
    cerr << "In Fallback::Fallback(attrs = {" /* TODO << attrs */ << "});" << endl;
#endif
}

Fallback::Fallback(const Hash& attrs, Widget* content): Container(attrs, content) {
    // FIXME - this->content.push_back(content);
#ifdef DEBUG
    cerr << "In Fallback::Fallback(attrs = {" /* TODO << attrs */
        << "}, content = {" /* TODO << content */ << "});" << endl;
#endif
}

Fallback::Fallback(Widget* content, const Hash& attrs): Container(content, attrs) {
    // FIXME - this->content.push_back(content);
#ifdef DEBUG
    cerr << "In Fallback::Fallback(content = {" /* TODO << content */
        << "}, attrs = {" /* TODO << attrs */ << "});" << endl;
#endif
}

Fallback::~Fallback(void) {
#ifdef DEBUG
    cerr << "In Fallback destructor." << endl;
#endif
}

/*
string Fallback::render(HIT& hit) {
    stringstream out;
    out << "Fallback = attributes: [";
    for (Hash::iterator i = attrs.begin(); i != --attrs.end(); i++) {
        out << i->first << ": " << i->second << ", ";
    }
    Hash::iterator i = --attrs.end();
    out << i->first << ": " << i->second << "] ";
    out << "content: [" << renderContent(hit) << "]";
    return out.str();
}
*/
