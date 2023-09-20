#include "Flat.h"
#include <iostream>

Flat::Flat(const double& area, const int& rooms, const int& people, const int& costpersqrmtr)
	: mArea(area)
	, mRooms(rooms)
	, mPeople(people)
	, mCostPerSqrmtr(costpersqrmtr)
{}



bool Flat::move_in(const int& noOfPeople)
{
	mPeople += noOfPeople;
	return true;
}


int Flat::get_cost() const
{
	return mArea * mCostPerSqrmtr;
}


int Flat::get_people() const
{
	return mPeople;
}


int Flat::get_rooms() const
{
	return mRooms;
}


int Flat::get_area() const
{
	return mArea;
}


int Flat::get_costpersqrm() const
{
	return mCostPerSqrmtr;
}


std::ostream& operator<<(std::ostream& outputStream, const Flat& flat)
{
	outputStream << "FLAT /  "
		<< "Area: " << flat.mArea << "m2 | "
		<< "Rooms: " << flat.mRooms << " | "
		<< "People: " << flat.mPeople << " | "
		<< "Cost per m2: " << flat.mCostPerSqrmtr
		<< "  /";
	return outputStream;
}
