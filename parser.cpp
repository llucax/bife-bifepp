// vim: set expandtab tabstop=4 shiftwidth=4:

#include "widget.h"
#include "container.h"
#include "fallback.h"
#include "string.h"
#include "parser.h"
#include <sstream>
#include <dlfcn.h>

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
    stack.push(fb_create(name, attrs));
}

void Parser::on_end_element(const string& name) {
#ifdef DEBUG
    cerr << "In Parser::on_end_element('" << name << "');" << endl;
#endif
    Widget* cur = stack.top();
    stack.pop();
    // If is the last widget, it's the root widget.
    if (stack.empty()) {
        root = cur;
    // If is not the last widget, we add it as content of his parent.
    } else {
        Container* par = dynamic_cast<Container*>(stack.top());
        // If the parent is a Container, we add curent widget as content.
        if (par) {
            par->append(cur);
        // If not, we raise an exception TODO
        } else {
            throw "Trying to add content to a non-container widget.";
        }
    }
}

void Parser::on_characters(const string& chars) {
#ifdef DEBUG
    cerr << "In Parser::on_characters('" << chars << "');" << endl;
#endif
    if (!stack.empty()) {
        Container* cur = dynamic_cast<Container*>(stack.top());
        // If we are in a Container, we add curent string widget as content.
        if (cur) {
            cur->append(new String(chars));
        // If not, we raise an exception TODO
        } else {
            throw "Trying to add content to a non-container widget.";
        }
    } else {
        // FIXME - investigar si tiene sentido.
        throw "Characters with no tags!!!?!?!?!";
    }
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

Parser::Parser(void): fb_create(NULL), fb_destroy(NULL), root(NULL) {
#ifdef DEBUG
    cerr << "In Parser::Parser();" << endl;
#endif
    void* fb = dlopen("./translate.so", RTLD_NOW | RTLD_GLOBAL); // TODO - mas rapido: RTLD_LAZY);
    if (!fb) {
        throw string("No se puede cargar el plug-in: ") + dlerror();
    }
    fb_create  = (create_t*)dlsym(fb, "create");
    fb_destroy = (destroy_t*)dlsym(fb, "destroy");
    if (!fb_create || !fb_destroy) {
        throw string("No se puede cargar el creador del plug-in: ") + dlerror();
    }
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
