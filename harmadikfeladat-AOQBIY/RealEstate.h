#pragma once
class RealEstate	//Ingatlan
{
public:
	virtual int abs() = 0;

	virtual int get_cost() const { return mCost; }

private:
	int mCost;
};