#include <iostream>
using namespace std;

string do_something(string **s)
{
	string *s2 = *s;
	**s = *s2+'!';
	return **s;
}


int main()
{
	string s = "toto";
	cout << s << endl;

	do_something(&&s);
	cout << s << endl;

	string *s0 = &s;
	string s2 = do_something(&s0);
	cout << s2 << endl;

	cout << &s << endl;
	cout << &s2 << endl;

	return 0;
}
