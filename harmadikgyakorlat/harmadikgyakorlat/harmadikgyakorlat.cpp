#include <iostream>
#include "Fractional.h"
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	const Fractional f1(3,4);
	Fractional f2(6, 8);
	try
	{
		Fractional f3(1, 0);
	}
	catch (const std::runtime_error& ex)
	{
		cout << ex.what() << endl;
	}

	Fractional f = 2 + f1;
	double d(f1);
	cout << d << endl;

	//if (f1)
	//{

	//}
	Fractional f4 = Fractional::Parse("3/4");
	cout << f4 << endl;
	//const Fractional f2(5);
	//cout << f1 << endl;
	//auto f3 = f1 + f2;
	//auto f4 = f1+3;
	//auto f5 = 3 + f1;
	//f2 += f1;
	//auto f4 = f1 + Fractional(3);mivel explicit az egy tagú konstruktorom van ezért nem lehet implicit hívást alkalmazni
	//vector<Fractional> v{ {3,4},{-1,2},{4,5},{6,7} };
	//sort(v.begin(), v.end());
	//if (f1==f2)
	//{
	//	cout << "Equals." << endl;
	//}
	//for (const auto& e:v)		
	//{
	//	cout << e << endl;
	//}
	//cout << f5 << endl;
	//<< egyenlõ a kettõvel hatványaival való szorzással
}