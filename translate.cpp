// vim: set expandtab tabstop=4 shiftwidth=4:

#include "translate.h"
#include <sstream>

using std::stringstream;
using namespace bife;

#ifdef DEBUG
#include <iostream>
using std::cerr;
using std::endl;
#endif

Translate::Translate(const string& name): Fallback(name) {
#ifdef DEBUG
    cerr << "In Translate::Translate(name = '" << name << "');" << endl;
#endif
}

Translate::Translate(const string& name, const Hash& attrs): Fallback(name, attrs) {
#ifdef DEBUG
    cerr << "In Translate::Translate(name = '" << name
        << "', attrs = {" /* TODO << attrs */ << "});" << endl;
#endif
}

Translate::Translate(const string& name, const Hash& attrs, Widget* content):
        Fallback(name, attrs, content) {
    // FIXME - this->content.push_back(content);
#ifdef DEBUG
    cerr << "In Translate::Translate(name = '" << name
        << "', attrs = {" /* TODO << attrs */
        << "}, content = {" /* TODO << content */ << "});" << endl;
#endif
}

Translate::Translate(const string& name, Widget* content, const Hash& attrs):
        Fallback(name, content, attrs) {
    // FIXME - this->content.push_back(content);
#ifdef DEBUG
    cerr << "In Translate::Translate(name = '" << name
        << "', content = {" /* TODO << content */
        << "}, attrs = {" /* TODO << attrs */ << "});" << endl;
#endif
}

Translate::~Translate(void) {
#ifdef DEBUG
    cerr << "In Translate destructor." << endl;
#endif
}

string Translate::render(HIT& tpl) {
    stringstream out;
    if (false /* TODO tpl.exists(name, '')*/) {
        Hash a = attrs;
        a["CONTENT"] = renderContent(tpl);
        out << tpl.parse(name, attrs /* TODO ,"", "" */);
    } else {
        out << "<" << name;
        for (Hash::iterator i = attrs.begin(); i != attrs.end(); i++) {
            out << " " << i->first << "=\"" << i->second << "\"";
        }
        string c = renderContent(tpl);
        if (c.empty()) {
            out << " />";
        } else {
            out << ">" << c << "</" << name << ">";
        }
    }
    return out.str();
}

