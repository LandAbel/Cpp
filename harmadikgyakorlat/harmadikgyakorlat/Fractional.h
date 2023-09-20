#pragma once
#include <cstdint>
#include <iostream>
#include <exception>
using namespace std;
class Fractional
{
public:
	Fractional() = default;
	Fractional(const int16_t number);//explicit
	Fractional(const int16_t numerator, const uint16_t denominator);//1 elemes létrehozás esetén így müködik elsõ megoldás 	Fractional(const int16_t numerator, const uint16_t denominator=1);

	Fractional operator+(const Fractional& other) const;
	void operator+=(const Fractional& other);

	bool operator==(const Fractional& other)const;
	bool operator!=(const Fractional& other)const;

	bool operator<(const Fractional& other)const;
	bool operator<=(const Fractional& other)const;

	explicit operator double() const;

	explicit operator bool() const;

	static Fractional Parse(const string& s);

	friend ostream& operator<<(ostream& outputStream, const Fractional& fractional);
private:
	int16_t mNumerator=0;
	uint16_t mDenominator=1;
};
Fractional operator+(const int16_t rhs, const Fractional& lhs);
