#pragma once

class Rental	//Berelheto
{
public:
	virtual int abst() = 0;

	virtual int total_cost(const int& numberOfMonths);
	virtual bool is_reserved() const;
	virtual bool reserve(const int& numberOfMonths);

	void set_reservation(const int& length);
	int get_reservation() const;

private:
	int mCostPerMonth;
	int mReservedForThisLong;
	bool mReserved;
};