// vim: set et ts=4 sw=4:

#include <string>
#include <iostream>

using namespace std;

int main(void) {
    string s1 = "base_translate";
    string::size_type pos = s1.find(".");
    if (pos == string::npos) {
        cerr << "Dot not found in: " << s1 << endl;
    }
    s1 = "base.translate";
    pos = s1.find(".");
    if (pos == string::npos) {
        cerr << "Dot not found in: " << s1 << endl;
        return 1;
    } else {
        cerr << "Dot at position " << pos << " in: " << s1 << endl;
    }
    string s2(s1, 0, pos);
    cout << "Module name: " << s2 << endl;
    string s3 = s1.substr(pos + 1, s1.length() - 1);
    cout << "Module name: " << s3 << endl;
    return 0;
}
