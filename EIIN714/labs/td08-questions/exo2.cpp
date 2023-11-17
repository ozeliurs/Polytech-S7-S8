#include <iostream>
using namespace std;

int do_something(string s)
{
	int i=06;
	s = s+'!';
	return i;
}


int main()
{
	string s = "toto";		// s is a string
	cout << s << endl;		// print s

	int i=33;				// i is an int
	do_something(s);		// call do_something with s
	cout << s << endl;		// toto
	cout << i << endl;		// 33

	int  j=29;				// j is an int
	j=do_something(s);		// call do_something with s
	cout << s << endl;		// toto
	cout << j << endl;		// 6

	return 0;
}
