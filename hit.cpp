// vim: set expandtab tabstop=4 shiftwidth=4:

#include "hit.h"

#ifdef DEBUG
#include <iostream>
#endif

string HIT::getFileName(string blockname) {
    return string(root + '/' + blockname + postfix);
}

string HIT::getFileContent(string filename) {
    stringbuf buff;
    ifstream in(filename.c_str());
    // FIXME - Verificar apertura.
    if (!in) {
#ifdef DEBUG
        cerr << "Can't read template file '" << filename << "'." << endl;
#endif
        return buff.str();
    }
    while (in.get(buff)) {
        in.ignore();
    }
    in.close();
    return buff.str();
}

HIT::HIT(string root, string postfix): root(root), postfix(postfix) {}

string HIT::parse(string blockname, Hash& vars) {
    string content = getFileContent(getFileName(blockname));
    for (Hash::iterator i = vars.begin(); i != vars.end(); i++) {
        string key = "{" + i->first +  "}";
        int pos = -1;
        while ((pos = content.find(key)) != -1) {
#ifdef DEBUG
            cout << "Founded at pos " << pos << ", key '" << key << "' (len: "
                << key.length() << "). Will be replaced with '" << i->second
                << "'" << endl;
#endif
            content.replace(pos, key.length(), i->second);
#ifdef DEBUG
            cout << "New content: " << content << endl << endl << endl;
#endif
        }
    }
    return content;
}

