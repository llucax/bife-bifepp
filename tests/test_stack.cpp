#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main(void) {
	cout << "Pila comun..." << endl;
	stack<string> st;
	st.push("Hola mundo");
	string s1 = "String 1";
	st.push(s1);
	s1 += " <modificado>";
	cout << "Primer elemento: " << st.top() << endl;
	st.pop();
	cout << "Segundo elemento: " << st.top() << endl;
	st.pop();
	cout << endl;

	cout << "Pila de punteros..." << endl;
	stack<string*> stp;
	string s = "Hola mundo";
	stp.push(&s);
	//vp.push_back("Hola mundo");
	s1 = "String 1";
	stp.push(&s1);
	s1 += " <modificado>";
	while (!stp.empty()) {
		cout << *(stp.top()) << endl;
		stp.pop();
	}
	return 0;
}

