// vim: set expandtab tabstop=4 shiftwidth=4:

#include "ghit.h"

GHIT::GHIT(string root, string postfix, string group) {
    HIT(root, postfix);
    this->group.push(group);
}

string GHIT::getFileName(string blockname) {
    return string(root + '/' + group.top() + '/' + blockname + postfix);
}

void GHIT::pushGroup(string group = "") {
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

