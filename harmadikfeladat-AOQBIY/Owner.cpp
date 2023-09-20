#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "Owner.h"
#include "SemiDetachedHouse.h"
#include "Apartment.h"
#include "FamilyApartment.h"
#include "Garage.h"


vector<SemiDetachedHouse> Owner::get_houses()
{
	return mHouses;
}
void Owner::maintain(const string& path, vector<SemiDetachedHouse>& vec)
{
	SemiDetachedHouse sdh(4, 2);


	std::ifstream inputfile(path);
	if (!inputfile.is_open())
	{
		return;
	}

	string s;
	while (!inputfile.eof())
	{
		getline(inputfile, s);
		if (s.empty())
			continue;

		add2sdh(s, sdh);
	}

	vec.push_back(sdh);

	inputfile.close();
}

SemiDetachedHouse Owner::createSemiDetachedHouse(const string& s)
{
	// Extract data from the string and create a SemiDetachedHouse object
	// Assuming the format of the string is: "<rooms> <bathrooms>"
	stringstream ss(s);
	int rooms, bathrooms;
	ss >> rooms >> bathrooms;

	return SemiDetachedHouse(rooms, bathrooms);
}




void Owner::add2sdh(const string& line, SemiDetachedHouse& sdh)
{
	vector<string> elements;
	string element;
	stringstream ss(line);

	while (ss >> element)
	{
		elements.push_back(element);
	}

	if (!elements.empty())
	{
		string houseType = elements[0];
		elements.erase(elements.begin());

		if (houseType == "Alberlet")
		{
			addFlat(elements, sdh);
		}
		else if (houseType == "CsaladiApartman")
		{
			addFlat(elements, sdh);
		}
		else if (houseType == "Garazs")
		{
			addGarazs(elements, sdh);
		}
	}
}
void Owner::addFlat(const vector<string>& flatInfo, SemiDetachedHouse& sdh)
{
	vector<double> info(flatInfo.size());

	transform(flatInfo.begin(), flatInfo.end(), info.begin(),
		[](const string& s) { return stod(s); });

	Flat* flat;

	if (info.size() == 3)
		flat = new Apartment(info[0], info[1], info[2]);
	else if (info.size() == 4)
		flat = new FamilyApartment(info[0], info[1], info[2], info[3]);
	else
		return; // Invalid flatInfo size, do nothing

	sdh.add_flat(*flat);
	delete flat;
}


void Owner::addGarazs(const vector<string>& garinfo, SemiDetachedHouse& sdh)
{
	double length = stod(garinfo[0]);
	double width = stod(garinfo[1]);
	bool hasMotorizedDoor = garinfo[2] == "futott";

	Garage g(length, width, hasMotorizedDoor);
	sdh.add_garage(g);
}
