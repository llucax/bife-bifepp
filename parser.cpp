// vim: set expandtab tabstop=4 shiftwidth=4:

#include "parser.h"
#include <sstream>

using std::stringstream;
using namespace bife;

#ifdef DEBUG
#include <iostream>
using std::cerr;
using std::endl;
#endif

void Parser::on_start_document(void) {
#ifdef DEBUG
    cerr << "In Parser::on_start_document();" << endl;
#endif
}

void Parser::on_end_document(void) {
#ifdef DEBUG
    cerr << "In Parser::on_end_document();" << endl;
#endif
}

void Parser::on_start_element(const string& name, const AttributeMap& attrs) {
#ifdef DEBUG
    cerr << "In Parser::on_start_element(name = '" << name << "', attrs = [";
    if (attrs.size()) {
        Hash::const_iterator last = attrs.end();
        last--;
        for (Hash::const_iterator i = attrs.begin(); i != last; i++) { //last; i++) {
            cerr << i->first << ": '" << i->second << "', ";
        }
        cerr << last->first << ": '" << last->second << "'";
    }
    cerr  << "]);" << endl;
#endif
/*
    stringstream out;
    out << "widget = attributes: [";
    if (attrs.size()) {
        Hash::const_iterator last = attrs.end();
        last--;
        for (Hash::const_iterator i = attrs.begin(); i != last; i++) { //last; i++) {
            out << i->first << ": '" << i->second << "', ";
        }
        out << last->first << ": '" << last->second << "'";
    }
    out << "]);" << endl;
    return out.str();
*/
}

void Parser::on_end_element(const string& name) {
#ifdef DEBUG
    cerr << "In Parser::on_end_element('" << name << "');" << endl;
#endif
}

void Parser::on_characters(const string& chars) {
#ifdef DEBUG
    cerr << "In Parser::on_characters('" << chars << "');" << endl;
#endif
}

void Parser::on_comment(const string& text) {
#ifdef DEBUG
    cerr << "In Parser::on_comment('" << text << "');" << endl;
#endif
}

void Parser::on_warning(const string& warn) {
#ifdef DEBUG
    cerr << "In Parser::on_warning('" << warn << "');" << endl;
#endif
}

void Parser::on_error(const string& error) {
#ifdef DEBUG
    cerr << "In Parser::on_error('" << error << "');" << endl;
#endif
}

void Parser::on_fatal_error(const string& error) {
#ifdef DEBUG
    cerr << "In Parser::on_fatal_error('" << error << "');" << endl;
#endif
}

void Parser::on_validity_error(const string& error) {
#ifdef DEBUG
    cerr << "In Parser::on_validity_error('" << error << "');" << endl;
#endif
}

void Parser::on_validity_warning(const string& warn) {
#ifdef DEBUG
    cerr << "In Parser::on_validity_warning('" << warn << "');" << endl;
#endif
}

Parser::Parser(void): root(NULL) {
#ifdef DEBUG
    cerr << "In Parser::Parser();" << endl;
#endif
}

//Parser::Parser(const Hash& attrs): attrs(attrs) {
//#ifdef DEBUG
//    cerr << "In Parser::Parser(attrs = {" /* TODO << attrs */ << "});" << endl;
//#endif
//}

Parser::~Parser(void) {
#ifdef DEBUG
    cerr << "In Parser destructor." << endl;
#endif
}
/*
Parser::operator string(void) const {
    stringstream out;
    return out.str();
}
*/
