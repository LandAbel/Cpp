#include "Apartment.h"
#include <iostream>

Apartment::Apartment(const double& area, const int& rooms, const int& costpersqrmtr, const int& people, const int& reservedfor)
	: Flat(area, rooms, people, costpersqrmtr)
	, mReservedFor(reservedfor)
{
}


int Apartment::total_cost(const int& numberOfMonths = 1)
{
	if (this->get_people() == 0)
	{
		return 1;
	}

	return (this->get_area() * this->get_costpersqrm() / this->get_people()) * numberOfMonths;
}


bool Apartment::is_reserved() const
{
	return mReservedFor > 0;
}


bool Apartment::reserve(const int& numberOfMonths)
{
	return this->Rental::reserve(numberOfMonths);
}


bool Apartment::move_in(const int& noOfPeople)
{
	const int totalPeople = get_people() + noOfPeople;
	const int maxPeople = get_rooms() * 8;
	const double maxOccupancy = get_area() / 2.0;

	if (!(maxPeople > totalPeople && totalPeople < maxOccupancy))
	{
		return false;
	}

	Flat::move_in(noOfPeople);
	return true;
}


std::ostream& operator<<(std::ostream& outputStream, const Apartment& apartment)
{
	outputStream << "APARTMENT /  "
		<< "Area: " << apartment.get_area() << "m2 | "
		<< "Rooms: " << apartment.get_rooms() << " | "
		<< "People: " << apartment.get_people() << " | "
		<< "Cost per m2: " << apartment.get_costpersqrm() << " | "
		<< "Reserved for: " << apartment.mReservedFor << "(moths)"
		<< "  /";
	return outputStream;
}
