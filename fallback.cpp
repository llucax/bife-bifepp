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

Fallback::Fallback(const string& name): name(name) {
#ifdef DEBUG
    cerr << "In Fallback::Fallback(name = '" << name << "');" << endl;
#endif
}

Fallback::Fallback(const string& name, const Hash& attrs):
        Container(attrs), name(name) {
#ifdef DEBUG
    cerr << "In Fallback::Fallback(name = '" << name
        << "', attrs = {" /* TODO << attrs */ << "});" << endl;
#endif
}

Fallback::Fallback(const string& name, const Hash& attrs, Widget* content):
        Container(attrs, content), name(name) {
    // FIXME - this->content.push_back(content);
#ifdef DEBUG
    cerr << "In Fallback::Fallback(name = '" << name
        << "', attrs = {" /* TODO << attrs */
        << "}, content = {" /* TODO << content */ << "});" << endl;
#endif
}

Fallback::Fallback(const string& name, Widget* content, const Hash& attrs):
        Container(content, attrs), name(name) {
    // FIXME - this->content.push_back(content);
#ifdef DEBUG
    cerr << "In Fallback::Fallback(name = '" << name
        << "', content = {" /* TODO << content */
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
