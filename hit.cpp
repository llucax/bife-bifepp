// vim: set expandtab tabstop=4 shiftwidth=4:

#include "hit.h"
#include <fstream>
#include <sstream>

using std::ifstream;
using std::stringbuf;
using namespace bife;

#ifdef DEBUG
#include <iostream>
using std::cerr;
using std::endl;
#endif

HIT::HIT(string root, string postfix): root(root), postfix(postfix) {
#ifdef DEBUG
    cerr << "In HIT::HIT(root = '" << root << "', postfix = '" << postfix << "')" << endl;
#endif
}

HIT::~HIT(void) {
#ifdef DEBUG
    cerr << "In HIT destructor." << endl;
#endif
}

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
        buff.sputc(in.get());
    }
    in.close();
    return buff.str();
}

string HIT::parse(string blockname, Hash& vars) {
    int pos;
    string key;
    string content = getFileContent(getFileName(blockname));
    for (Hash::iterator i = vars.begin(); i != vars.end(); i++) {
        key = "{" + i->first +  "}";
        while ((pos = content.find(key)) != -1) {
#ifdef DEBUG2
            cerr << "Founded at pos " << pos << ", key '" << key << "' (len: "
                << key.length() << "). Will be replaced with '" << i->second
                << "'" << endl;
#endif
            content.replace(pos, key.length(), i->second);
#ifdef DEBUG2
            cerr << "New content: " << content << endl << endl << endl;
#endif
        }
    }
    return content;
}

