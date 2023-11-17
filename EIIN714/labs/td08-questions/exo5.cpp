#include <iostream>
using namespace std;

string *do_something(string &s)
{
	string *pt_s = &s;
	s = s+'!';
	return pt_s;
}


int main()
{
	string s = "toto";
	cout << s << endl;

	do_something(s);
	cout << s << endl;

	string *pt_s = do_something(s);
	cout << (*pt_s) << endl;
	cout << (pt_s==&s) << endl;

	return 0;
}
