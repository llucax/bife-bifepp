// vim: set expandtab tabstop=4 shiftwidth=4:

#include "chit.h"

using namespace bife;

#ifdef DEBUG
#include <iostream>
using std::cerr;
using std::endl;
#endif

CHIT::CHIT(const string& root, const string& postfix, const string& group):
        GHIT(root, postfix, group) {
#ifdef DEBUG
    cerr << "In CHIT::CHIT(root = '" << root << "', postfix = '" << postfix
        << "', group = '" << group << "');" << endl;
#endif
}

CHIT::~CHIT(void) {
#ifdef DEBUG
    cerr << "In CHIT destructor." << endl;
#endif
}

string CHIT::getFileContent(const string& filename) {
    Hash::iterator c = cache.find(filename);
    if (c == cache.end()) {
        cache[filename] = GHIT::getFileContent(filename);
        return cache[filename];
    } else {
        return c->second;
    }
}

