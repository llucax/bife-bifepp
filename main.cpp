// vim: set expandtab tabstop=4 shiftwidth=4:

#include <string>
#include <iostream>
#include <sstream>
#include "hit.h"
#include "ghit.h"
#include "chit.h"
#include "string.h"

using namespace std;
using namespace bife;

int main(void) {
    const string indent = "    ";
    Hash vars;
    vars["NOMBRE"] = "Luca man";
    vars["EDAD"]   = "21";

    cout << "HIT example:" << endl;
    cout << "============" << endl;
    HIT h;
    cout << indent << h.parse("test", vars) << endl << endl << endl;

    cout << "GHIT example:" << endl;
    cout << "=============" << endl;
    vars["NOMBRE"] = "Pedro";
    vars["EDAD"]   = "26";
    GHIT g("./././");
    cout << "We are using the default group: '" << g.getGroup() << "'." << endl;
    cout << indent << g.parse("test", vars) << endl;
    g.pushGroup("tpldir");
    cout << "We start using the '" << g.getGroup() << "' group." << endl;
    cout << indent << g.parse("test2", vars) << endl;
    cout << "We stop using '";
    cout << g.popGroup() << "' group, and go back to default one ('";
    cout << g.getGroup() << "')." << endl;
    cout << indent << g.parse("test", vars) << endl << endl << endl;

    cout << "CHIT example:" << endl;
    cout << "=============" << endl;
    CHIT chit("././././././", ".tpl.html");
    const int n = 65;
    for (int i = n; i < (n+10); i++) {
        stringstream ssi, ssc;
        ssi << i;
        ssc << char(i);
        vars["NOMBRE"] = "Chit gay " + ssc.str();
        vars["EDAD"]   = ssi.str();
        cout << indent << chit.parse("test", vars) << endl;
    }

    cout << "bife::String example:" << endl;
    cout << "=====================" << endl;
    string s = "std::string";
    String a("Un string");
    String b = "Otro string";
    //String c = s;
    cout << "s: '" << s << "' - "
        << "a: '" << a << "' - "
        << "b: '" << b << endl;
    cout << "a.render(): '" << a.render(chit) << "' - "
        << "b.render(): '" << b.render(chit) << endl;
}
