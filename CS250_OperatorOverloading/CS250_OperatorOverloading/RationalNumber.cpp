//Caleb Turner
//RationalNumber.cpp
#include <cstdlib>
#include <iostream> 
#include <stdexcept>
#include <ostream>
#include "RationalNumber.h"
using namespace std;

// RationalNumber constructor sets n and d and calls reduction
RationalNumber::RationalNumber(int n, int d) {
	numerator = n;

	// validate denominator
	if (d > 0) {
		denominator = d;
	}
	else {
		throw invalid_argument("Denominator cannot be 0");
	}

	reduction(); // invokes function reduction
}

// overloaded + operator

// STEP 3
RationalNumber RationalNumber::operator+(const RationalNumber& right)
{
	RationalNumber* result = new RationalNumber;
	result->numerator = (numerator * right.denominator + denominator * right.numerator);
	result->denominator = denominator * right.denominator;
	result->reduction();
	return *result;

}
// overloaded - operator

// STEP 4
RationalNumber RationalNumber::operator-(const RationalNumber& right)
{
	RationalNumber* result = new RationalNumber;
	result->numerator = (numerator * right.denominator - denominator * right.numerator);
	result->denominator = denominator * right.denominator;
	result->reduction();
	return *result;
}
// overloaded * operator

// STEP 5
RationalNumber RationalNumber::operator*(const RationalNumber& right)
{
	RationalNumber* result = new RationalNumber;
	result->numerator = numerator * right.numerator;
	result->denominator = denominator * right.denominator;
	result->reduction();
	return *result;
}
// overloaded / operator

// STEP 6
RationalNumber RationalNumber::operator/(const RationalNumber& right)
{
	RationalNumber* result = new RationalNumber;
	result->numerator = numerator * right.denominator;
	result->denominator = denominator * right.numerator;
	result->reduction();
	return *result;
}
// overloaded < operator

// STEP 7
bool RationalNumber::operator<(const RationalNumber& right) const {
	return ((numerator*right.denominator)<(denominator*right.numerator));
}
// overloaded > operator
bool RationalNumber::operator>(const RationalNumber& gr) const {
	return gr < *this;
}

// overloaded <= operator
bool RationalNumber::operator<=(const RationalNumber& ler) const {
	return !(*this > ler);
}

// overloaded >= operator
bool RationalNumber::operator>=(const RationalNumber& ger) const {
	return !(*this < ger);
}

// overloaded == operator
bool RationalNumber::operator==(const RationalNumber& er) const {
	return numerator == er.numerator && denominator == er.denominator;
}

// overloaded != operator
bool RationalNumber::operator!=(const RationalNumber& ner) const {
	return !(*this == ner);
}


// function reduction definition
void RationalNumber::reduction() {
	int gcd{ 1 };  // greatest common divisor;
	int largest{ (numerator > denominator) ? numerator : denominator };

	for (int loop{ 2 }; loop <= largest; ++loop) {
		if (numerator % loop == 0 && denominator % loop == 0) {
			gcd = loop;
		}
	}

	numerator /= gcd;
	denominator /= gcd;
}

// friend function overloading <<

// STEP 8
ostream& operator<<(ostream& outStream, const RationalNumber& number)
{
	if (number.denominator == 1)
		outStream << number.numerator;
	else
		outStream << number.numerator << "/" << number.denominator;
	return outStream;
}