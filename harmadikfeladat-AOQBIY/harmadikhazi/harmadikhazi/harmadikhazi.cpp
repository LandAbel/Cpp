#include <iostream>

#include "Flat.h"
#include "Apartment.h"
#include "FamilyApartment.h"
#include "Garage.h"
#include "SemiDetachedHouse.h"
#include "Owner.h"

void HouseToStringConverter(const vector<SemiDetachedHouse>& vec)
{
	for (auto sdh : vec)
	{
		cout << "Flat(s):" << endl;
		for (const auto& fl : sdh.get_flats())
			cout << fl << endl;

		cout << endl << "Garage(s):" << endl;
		for (const auto& ga : sdh.get_garages())
			cout << ga << endl;
	}
}

int main()
{
//#pragma region SemiDetachedTest
//	Flat f(120, 5, 2, 250);
//	Flat f2(120, 5, 3, 250);
//	Flat f3(120, 5, 4, 250);
//	SemiDetachedHouse sdh(4, 2);
//	bool adding = sdh.add_flat(f);
//	bool adding2 = sdh.add_flat(f2);
//	bool adding3 = sdh.add_flat(f3);
//	int totalcost = sdh.total_value();
//	int ppl = sdh.all_people();
//	cout << adding << endl << adding2 << endl << adding3 << endl << totalcost << endl << ppl << endl;
//	cout << f << endl;
//	cout << f.get_cost() << endl;
//	cout << f.get_people() << endl;
//	cout << f.move_in(1) << endl;
//	cout << f.move_in(2) << endl;
//	cout << f.move_in(2) << endl;
//	cout << f.get_people() << endl;
//	cout << f << endl << endl;
//#pragma endregion


//#pragma region ApartmentTest
//
//	Apartment a(50, 3, 20);
//	cout << a << endl;
//	cout << a.get_people() << endl;
//	cout << a.is_reserved() << endl;
//	cout << a.total_cost(1) << endl;
//	cout << a.move_in(17) << endl;
//	cout << a.move_in(5) << endl;
//	cout << a.total_cost(1) << endl;
//	cout << a.total_cost(2) << endl;
//	cout << a << endl << endl;
//#pragma endregion


//#pragma region FamilyApartmentTest
//	FamilyApartment fa(60, 3, 10);
//	cout << fa << endl;
//	cout << fa.move_in(2) << endl;
//	cout << fa.child_born() << endl;
//	cout << fa << endl << endl;
//#pragma endregion


//#pragma region GarageTest
//	Garage g(10, 5, 0);
//	cout << g << endl;
//	cout << g.total_cost(1) << endl;
//	cout << g.reserve(2) << endl;
//	g.move_car();
//	cout << g << endl << endl;
//#pragma endregion


	Owner o;
	auto hazak = o.get_houses();
	o.maintain("Haz.txt", hazak);
	HouseToStringConverter(hazak);

	return 1;
}