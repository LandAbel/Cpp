#include "Rental.h"

int Rental::total_cost(const int& numberOfMonths)
{
	return numberOfMonths * mCostPerMonth;
}


bool Rental::is_reserved() const
{
	return mReserved;
}


bool Rental::reserve(const int& numberOfMonths)
{
	if (mReserved)
		return false;
	else
		mReservedForThisLong = numberOfMonths;
	mReserved = true;
	return mReserved;
}

void Rental::set_reservation(const int& length)
{
	mReservedForThisLong = length;
}

int Rental::get_reservation() const
{
	return mReservedForThisLong;
}
