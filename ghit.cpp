// vim: set expandtab tabstop=4 shiftwidth=4:

#include "ghit.h"

using namespace bife;

#ifdef DEBUG
#include <iostream>
using std::cerr;
using std::endl;
#endif

GHIT::GHIT(string root, string postfix, string group): HIT(root, postfix) {
#ifdef DEBUG
    cerr << "In GHIT::GHIT(root = '" << root << "', postfix = '" << postfix
        << "', group = '" << group << "');" << endl;
#endif
    this->group.push(group);
}

GHIT::~GHIT(void) {
#ifdef DEBUG
    cerr << "In GHIT destructor." << endl;
#endif
}

string GHIT::getFileName(string blockname) {
    return string(root + '/' + group.top() + '/' + blockname + postfix);
}

void GHIT::pushGroup(string group) {
    this->group.push(group);
}

string GHIT::popGroup() {
    string g = group.top();
    group.pop();
    return g;
}

string GHIT::getGroup() {
    return group.top();
}

