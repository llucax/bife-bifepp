// vim: set expandtab tabstop=4 shiftwidth=4:

//#include "chit.h"
#include "parser.h"
#include <sstream>
#include <iostream>
#include <string>

using namespace std;
using namespace bife;

int main(int argc, char* argv[]) {
    string file;
    if (argc < 2) {
        file = "test.xml";
    } else {
        file = argv[1];
    }
    //CHIT tpl;
    cout << "Parser example:" << endl;
    cout << "===============" << endl;
    try {
        Parser parser;
        parser.parse_file(file);
    } catch (exception e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}
