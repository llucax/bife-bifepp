// vim: set expandtab tabstop=4 shiftwidth=4:

#include "libbife/chit.h"
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
    CHIT tpl;
    cout << "Parser example:" << endl;
    cout << "===============" << endl;
    try {
        Parser parser("translate.translate");
        parser.parse_file(file);
        // Text is returned in utf-8 encoding.
        cout << parser.root->render(tpl) << endl;
    } catch (exception e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    } catch (string e) {
        cerr << "Error: " << e << endl;
        return 2;
    } catch (const char* e) {
        cerr << "Error: " << e << endl;
        return 3;
    } catch (...) {
        cerr << "Unknown error!!!" << endl;
        return -1;
    }
    return 0;
}
