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
 * Fallback constructor.
 *
 * @param  classname  Name of the class to construct.
 * @param  widgetname Name of the widget to construct.
 * @param  attrs      Widget's attributes.
 * @return A new Fallback widget.
 */
extern "C"
Fallback* fallback_constructor(const string& classname, const string& widgetname, const Hash& attrs) {
    string cn = classname;
    std::transform(cn.begin(), cn.end(), cn.begin(), std::tolower);
    if (cn == "translate") {
        return new Translate(widgetname, attrs);
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
void widget_destructor(Widget* w) {
	    delete w;
}
