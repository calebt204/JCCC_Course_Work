#include <iostream> 
#include "RationalNumber.h"
using namespace std;

int main() {
	RationalNumber c(7, 3);
	RationalNumber d(3, 9);

	RationalNumber x = c + d; // test overloaded operators + and =
	cout << c << " + " << d << " = " << x << "\n";
	
	x = c - d; // test overloaded operators - and =
	cout << c << " - " << d << " = " << x << "\n";

	x = c * d; // test overloaded operators * and =
	cout << c << " * " << d << " = " << x << "\n";

	x = c / d; // test overloaded operators / and =
	cout << c << " / " << d << " = " << x << "\n";

	cout << boolalpha;
	cout << c << " > " << d << " is " << (c > d) << "\n";
	cout << c << " < " << d << " is " << (c < d) << "\n";
	cout << c << " >= " << d << " is " << (c >= d) << "\n";
	cout << c << " <= " << d << " is " << (c <= d) << "\n";
	cout << c << " == " << d << " is " << (c == d) << "\n";
	cout << c << " != " << d << " is " << (c != d) << "\n";

	cin.ignore();
	cin.get();
	
}
