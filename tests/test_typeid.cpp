// vim: set et ts=4 sw=4:

#include <string>
#include <iostream>
#include <typeinfo>
#include <cxxabi.h>

using namespace std;

namespace tst {
class Test {
};
class Test2 {
};
}

namespace test {
class Test {
};
class MiTest {
};
}

string type(const type_info& type) {
    string ret;
    int status;
    char* demangle = abi::__cxa_demangle(type.name(),  0, 0, &status);
    if (status == 0) {
        ret = demangle;
        free(demangle);
    } else if (status == -3) {
        cerr << "Error: Invalid argument." << endl;
    } else if (status == -2) {
        cerr << "Error: " << type.name()
            << " is not a valid name under the C++ ABI mangling rules."
            << endl;
    } else if (status == -1) {
        cerr << "Error: Memory allocation problem." << endl;
    }
    return ret;
}
    

int main(void) {
    tst::Test t;
    tst::Test2 t2;
    test::Test t3;
    test::MiTest t4;
    cout << "cout es un '" << type(typeid(cout)) << "'." << endl;
    cout << "t es un '" << type(typeid(t)) << "'." << endl;
    cout << "t2 es un '" << type(typeid(t2)) << "'." << endl;
    cout << "t3 es un '" << type(typeid(t3)) << "'." << endl;
    cout << "t4 es un '" << type(typeid(t4)) << "'." << endl;
    cout << "tst::Test es un '" << type(typeid(tst::Test)) << "'." << endl;
    cout << "int es un '" << type(typeid(int)) << "'." << endl;

    int status;
    cout << abi::__cxa_demangle("_ZN4bife9TranslateC2Ev",  0, 0, &status) << endl;
    cout << abi::__cxa_demangle("_ZN4bife9TranslateD0Ev",  0, 0, &status) << endl;
    cout << abi::__cxa_demangle("_ZN4bife9TranslateD0Ev",  0, 0, &status) << endl;
    cout << abi::__cxa_demangle("_ZN4bife9TranslateD1Ev",  0, 0, &status) << endl;
    cout << abi::__cxa_demangle("_ZN4bife9TranslateC2ERKSt3mapISsSsSt4lessISsESaISt4pairIKSsSsEEE", 0, 0, &status) << endl;
    //void* dlh = dlopen(sharedObject.c_str(), RTLD_LAZY);
    //Widget* w = (Widget*)dlsym(dlh, "_ZN4bife9TranslateD2Ev");
}
