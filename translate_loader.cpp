#include "translate.h"
#include "widget.h"
#include "hash.h"

using bife::Translate;
using bife::Widget;
using bife::Hash;
using std::string;

// the types of the class factories
typedef bife::Widget* create_t(const string& name, const Hash&);
typedef void destroy_t(Widget*);

// the class factories
extern "C" Widget* create(const string& name, const Hash& attrs) {
	    return new Translate(name, attrs);
}
extern "C" void destroy(Widget* w) {
	    delete w;
}
