#pragma once
#include "RealEstate.h"
#include <string>
class Flat : public RealEstate	//Lakas
{
public:
	Flat(const double& area, const int& rooms, const int& people, const int& costpersqrmtr);


	virtual bool move_in(const int& noOfPeople);

	int get_cost() const override;
	int get_costpersqrm() const;
	int get_people() const;
	int get_rooms() const;
	int get_area() const;


	friend std::ostream& operator<<(std::ostream& outputStream, const Flat& flat);


private:
	double mArea;
	int mRooms;
	int mPeople;
	int mCostPerSqrmtr;

	int abs() override { return 0; };
};