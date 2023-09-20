#pragma once
#include "Flat.h"

class FamilyApartment : public Flat		//CsaladiApartman
{
public:
	FamilyApartment(const double& area, const int& rooms, const int& costpersqrmtr, const int& people = 0, const int& children = 0);

	bool move_in(const int& noOfPeople) override;

	bool child_born();

	friend std::ostream& operator<<(std::ostream& outputStream, const FamilyApartment& FA);

protected:
	int mChildren;
};
