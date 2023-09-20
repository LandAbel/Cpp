#pragma once
#include "Flat.h"
#include "Garage.h"
#include <vector>

using namespace std;

class SemiDetachedHouse		//Tarsashaz
{
public:
	SemiDetachedHouse(const int& flats = 4, const int& garages = 4);

	bool add_flat(const Flat& flat);
	bool add_garage(const Garage& garage);
	int all_people() const;
	int total_value() const;
	vector<Flat> get_flats() const;
	vector<Garage> get_garages() const;

private:
	int mMaxFlats;
	int mMaxGarages;
	vector<Flat> mFlats;
	vector<Garage> mGarages;
};