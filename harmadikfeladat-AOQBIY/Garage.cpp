#include "Garage.h"

Garage::Garage(const double& area, const int& costprsqm, const bool& heated, const bool& car, const int& reservedfor)
	: mArea(area)
	, mCostPerSqrmtr(costprsqm)
	, mHeated(heated)
	, mParkedIn(car)
{
	Rental::set_reservation(reservedfor);
}


int Garage::get_cost() const
{
	return mArea * mCostPerSqrmtr;
}


int Garage::total_cost(const int& numberOfMonths)
{
	if (mHeated)
	{
		return get_cost() * numberOfMonths * 1.5;
	}

	return get_cost() * numberOfMonths;
}


bool Garage::is_reserved() const
{
	if (mParkedIn || Rental::get_reservation() > 0)
	{
		return true;
	}

	return false;
}


bool Garage::reserve(const int& numberOfMonths)
{
	if (Rental::reserve(numberOfMonths))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Garage::move_car()
{
	if (mParkedIn)
	{
		mParkedIn = false;
	}
	else
	{
		mParkedIn = true;
	}
}

std::ostream& operator<<(std::ostream& outputStream, const Garage& garage)
{
	outputStream << "GARAGE /  "
		<< "Area: " << garage.mArea << "m2 | "
		<< "Cost per m2: " << garage.mCostPerSqrmtr << " | "
		<< "Is heated: " << garage.mHeated << " | "
		<< "Reserved: " << garage.is_reserved() << " | "
		<< "Parked in: " << garage.mParkedIn
		<< "  /";
	return outputStream;
}
