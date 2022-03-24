#ifndef RATIONAL_NUMBER_H
#define RATIONAL_NUMBER_H
#include <string>
#include <ostream>

class RationalNumber {
public:
	RationalNumber(int = 0, int = 1); // default constructor
	RationalNumber operator+(const RationalNumber&); // addition
	RationalNumber operator-(const RationalNumber&); // subtraction
	RationalNumber operator*(const RationalNumber&); // multiplication
	RationalNumber operator/(const RationalNumber&); // division

	// relational operators
	bool operator<(const RationalNumber&) const;
	bool operator>(const RationalNumber&) const;
	bool operator<=(const RationalNumber&) const;
	bool operator>=(const RationalNumber&) const;

	// equality operators
	bool operator==(const RationalNumber&) const;
	bool operator!=(const RationalNumber&) const;

	// friend to overload <<
	friend std::ostream& operator<<(std::ostream&, const RationalNumber&);

private:
	int numerator; // private variable numerator
	int denominator; // private variable denominator
	void reduction(); // function for fraction reduction
};

#endif
