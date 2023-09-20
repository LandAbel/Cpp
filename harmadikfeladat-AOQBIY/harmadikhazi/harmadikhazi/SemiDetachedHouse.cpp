#include "SemiDetachedHouse.h"

SemiDetachedHouse::SemiDetachedHouse(const int& flats, const int& garages)
	: mMaxFlats(flats)
	, mMaxGarages(garages)
{
}


bool SemiDetachedHouse::add_flat(const Flat& flat)
{
	if (mFlats.size() + 1 > mMaxFlats)
	{
		return false;
	}

	mFlats.push_back(flat);
	return true;
}


bool SemiDetachedHouse::add_garage(const Garage& garage)
{
	if (mGarages.size() + 1 > mMaxGarages)
	{
		return false;
	}

	mGarages.push_back(garage);
	return true;
}


int SemiDetachedHouse::all_people() const
{
	int ppl = 0;

	for (const auto& house : mFlats)
		ppl += house.get_people();

	return ppl;
}


int SemiDetachedHouse::total_value() const
{
	int tcost = 0;

	for (const auto& house : mFlats)
	{
		if (house.get_people() > 0)
			tcost += house.get_cost();
	}

	return tcost;
}

vector<Flat> SemiDetachedHouse::get_flats() const
{
	return mFlats;
}

vector<Garage> SemiDetachedHouse::get_garages() const
{
	return mGarages;
}

