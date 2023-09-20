#pragma once
#include "RealEstate.h"
#include "Rental.h"
#include <ostream>

class Garage : public Rental, public RealEstate
{
public:
	Garage(const double& area, const int& costprsqm, const bool& heated, const bool& car = 0, const int& reservedfor = 0);

	int get_cost() const override;
	int total_cost(const int& numberOfMonths) override;
	bool is_reserved() const override;
	bool reserve(const int& numberOfMonths) override;

	void move_car();

	friend std::ostream& operator<<(std::ostream& outputStream, const Garage& garage);

private:
	double mArea;
	int mCostPerSqrmtr;
	bool mHeated;
	bool mParkedIn;

	int abs() override { return 0; }
	int abst() override { return 0; }
};