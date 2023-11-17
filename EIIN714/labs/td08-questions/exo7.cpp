#include <iostream>
using namespace std;

string &do_something(string s)
{
	s = s+'!';
	return s;
}


int main()
{
	string s = "toto";
	cout << s << endl;

	do_something(s);
	cout << s << endl;

	string s2 = do_something(s);
	cout << s2 << endl;

	cout << &s << endl;
	cout << &s2 << endl;

	return 0;
}
