// vim: set expandtab tabstop=4 shiftwidth=4:

#include "translate.h"
#include "../libbife/fallback.h"
#include "../libbife/widget.h"
#include "../libbife/hash.h"
#include <algorithm>
#include <string>

using bife::Translate;
using bife::Fallback;
using bife::Widget;
using bife::Hash;
using std::string;

/**
 * Widget constructor.
 *
 * @param  name  Name of the widget to construct.
 * @param  attrs Widget's attributes.
 * @return A new Widget.
 */
extern "C"
Widget* bife_widget_constructor(const string& name, const Hash& attrs) {
    string cn = name;
    std::transform(cn.begin(), cn.end(), cn.begin(), std::tolower);
    if (cn == "translate") {
        return new Translate(attrs);
    } else {
        return NULL;
    }
}

/**
 * Widget destructor.
 *
 * @param w The widget to destroy.
 */
extern "C"
void bife_widget_destructor(Widget* w) {
	    delete w;
}
