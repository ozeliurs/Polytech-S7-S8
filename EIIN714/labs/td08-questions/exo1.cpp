#include <iostream>
using namespace std;

int main()
{
	string s = "toto";
	cout << s << endl;				// toto

	string *pt_s;					// declaration d'un pointeur sur string

	cout << (*pt_s) << endl;		// Attention ! pt_s n'est pas initialise
									// (*pt_s) est une erreur de segmentation

	cout << pt_s << endl;			// 0x0000000
	cout << &pt_s << endl;			// Adresse valide de pt_s

	pt_s = &s;						// pt_s pointe sur s
	cout << pt_s << endl;			// Adresse valide de pt_s
	cout << &pt_s << endl;			// toto

	return 0;
}
