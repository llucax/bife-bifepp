// vim: set expandtab tabstop=4 shiftwidth=4:

#include "libbife/widget.h"
#include "libbife/container.h"
#include "libbife/fallback.h"
#include "libbife/string.h"
#include "parser.h"
//#include <sstream>
#include <dlfcn.h>

//using std::stringstream;
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
    if (fbClass.empty()) {
        throw string("Widget '") + name + "' not found and now using a fallback class.";
    } else {
        Fallback* fb;
        try {
            fb = dynamic_cast<Fallback*>(fbNew(fbClass, attrs));
            if (!fb) {
                throw string("Fallback widget '") + fbClass + " not found!";
            }
        } catch (...) {
            throw fbClass + " is not a Fallback Widget!";
        }
        fb->name = name;
        stack.push(fb);
    }
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

/*
Parser::Parser(void): fallbackConstructor(NULL), fallbackDestructor(NULL), root(NULL) {
#ifdef DEBUG
    cerr << "In Parser::Parser();" << endl;
#endif
    void* fb = dlopen("./translate.so", RTLD_LAZY); // XXX - así anda: RTLD_NOW | RTLD_GLOBAL);
    if (!fb) {
        throw string("No se puede cargar el plug-in: ") + dlerror();
    }
    fb_create  = (create_t*)dlsym(fb, "create");
    fb_destroy = (destroy_t*)dlsym(fb, "destroy");
    if (!fb_create || !fb_destroy) {
        throw string("No se puede cargar el creador del plug-in: ") + dlerror();
    }
}
*/

Parser::Parser(const string& fallback): fbNew(NULL), fbDel(NULL), root(NULL) {
#ifdef DEBUG
    cerr << "In Parser::Parser(fallback = '" << fallback << "');" << endl;
#endif
    if (!fallback.empty()) {
        string::size_type pos = fallback.find(".");
        if (pos == string::npos) {
            throw string("Fallback module not specified in fallback name: ") + fallback;
        }
        fbClass = fallback.substr(pos + 1, fallback.length() - 1);
        // Opens the fallback module.
        string modules_dir = "translate";
        string fb_module = modules_dir + "/" + fallback.substr(0, pos) + ".so";
        void* dlh = dlopen(fb_module.c_str(), RTLD_LAZY);
        if (!dlh) {
            throw string("No se puede cargar el plug-in: ") + dlerror();
        }
        fbNew = (Widget::Constructor*)dlsym(dlh, "bife_widget_constructor");
        fbDel = (Widget::Destructor*)dlsym(dlh, "bife_widget_destructor");
        if (!fbNew || !fbDel) {
            throw string("No se puede cargar el creador del plug-in: ") + dlerror();
        }
        // TODO - CLOSE dl handler, destroy objects.
    }
}

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
