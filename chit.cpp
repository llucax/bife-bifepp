// vim: set expandtab tabstop=4 shiftwidth=4:

#include "chit.h"

CHIT::CHIT(string root, string postfix, string group) {
    GHIT(root, postfix, group);
}

string CHIT::getFileContent(string filename) {
    Hash::iterator c = cache.find(filename);
    if (c == cache.end()) {
        cache[filename] = GHIT::getFileContent(filename);
        return cache[filename];
    } else {
        return c->second;
    }
}

