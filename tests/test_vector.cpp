#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(void) {
	cout << "Vector comun..." << endl;
	vector<string> v;
	v.push_back("Hola mundo");
	string s1 = "String 1";
	v.push_back(s1);
	s1 += " <modificado>";
	for (vector<string>::const_iterator i = v.begin(); i != v.end(); i++) {
		cout << "Primer elemento: " << *i << endl;
	}
	cout << endl;

	cout << "Vector de punteros..." << endl;
	vector<string*> vp;
	string s = "Hola mundo";
	vp.push_back(&s);
	//vp.push_back("Hola mundo");
	s1 = "String 1";
	vp.push_back(&s1);
	s1 += " <modificado>";
	for (vector<string*>::const_iterator i = vp.begin(); i != vp.end(); i++) {
		cout << "Primer elemento: " << **i << endl;
	}
	return 0;
}

