//: C03:StringizingExpressions.cpp
#include <iostream>
#include <cassert>
using namespace std;
#define P(A) cout << #A << ": " << (A) << endl;
int main() {
    int a = 1, b = 2, c = 3;
    P(a); P(b); P(c);
    P(a + b);
    assert(a + b == 3); // corta el programa si a + b != 3
    P((c - a)/b);
}
