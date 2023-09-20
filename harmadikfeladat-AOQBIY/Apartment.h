#pragma once
#include "Flat.h"
#include "Rental.h"

class Apartment : public Flat, public Rental	//Alberlet
{
public:
	Apartment(const double& area, const int& rooms, const int& costpersqrmtr, const int& people = 0, const int& reservedfor = 0);

	int total_cost(const int& numberOfMonths) override;
	bool is_reserved() const override;
	bool reserve(const int& numberOfMonths) override;

	bool move_in(const int& noOfPeople) override;


	friend std::ostream& operator<<(std::ostream& outputStream, const Apartment& apartment);

private:
	int mReservedFor;

	int abst() override { return 0; };
};