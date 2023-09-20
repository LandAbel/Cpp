#include "Fractional.h"
#include <string>
Fractional::Fractional(const int16_t numerator, const uint16_t denominator)
	:mNumerator(numerator)
	,mDenominator(denominator)
{
	if (mDenominator==0)
	{
		throw runtime_error("Division by Zero");
	}
}

Fractional::Fractional(const int16_t number)
	:Fractional(number,1)//godbolt.org 
{
}
ostream& operator<<(ostream& outputStream, const Fractional& fractional) 
{
	outputStream << fractional.mNumerator << " / " << fractional.mDenominator;
	return outputStream;
}
Fractional Fractional:: operator+(const Fractional& other) const
{
	Fractional result = *this;

	result += other;

	return result;
}
Fractional operator+(const int16_t rhs, const Fractional& lhs) 
{
	return lhs+rhs;
}
void Fractional::operator+=(const Fractional& other)
{
	//*this = *this + other; felesleges Fractonalt hoz létre
	mNumerator = mNumerator * other.mDenominator + mDenominator * other.mNumerator;
	mDenominator *= other.mDenominator;
}
bool Fractional::operator<(const Fractional& other)const 
{
	return mNumerator * other.mDenominator < other.mNumerator * mDenominator;
}
bool Fractional::operator==(const Fractional& other)const 
{
	return mNumerator * other.mDenominator == other.mNumerator* mDenominator;
}
bool Fractional::operator!=(const Fractional& other)const 
{
	return !(*this == other);
}
bool Fractional::operator<=(const Fractional& other)const 
{
	return *this < other || *this == other;

}
Fractional::operator double() const 
{
	return static_cast<double>(mNumerator) / mDenominator;//Ezt nem szeretjük (double)mNumerator
}
Fractional::operator bool() const 
{
	return mNumerator;
}
Fractional Fractional::Parse(const string& s) 
{
	const auto position=s.find('/');
	if (position != string::npos)
	{
		const auto numeratorString = s.substr(0, position);
		const auto denominatorString = s.substr(position + 1);
		return Fractional(stoi(numeratorString), stoi(denominatorString));
	}
	throw invalid_argument("No slash has found.");
}
