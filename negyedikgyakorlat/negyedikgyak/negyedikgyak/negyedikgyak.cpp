#include <iostream>
#include "vector.h"
using namespace std;

int main()
{
	//int a[5];
	//int b[] = { 3,4,5 };
	//int* c = new int[4];

	//delete[] c;

	nik::vector<int> v1;
	nik::vector<bool> v2(5);
	nik::vector<float> v3(4,3.14f);
	nik::vector<int> v4{ 1,2,3,5,7,9 };
	
	nik::vector<int> v5 = v4;//copy constructor

	v1 = v4;//copy assignment

	for (size_t i = 0; i < v4.size(); i++)
	{
		cout << v4[i] << endl;
	}
	for (size_t i = 0; i < v4.size(); i++)
	{
		v4[i] = 2 * i;
	}

	for (nik::vector<int>::iterator it = v4.begin(); it != v4.end(); ++it) 
	{
		cout << *it << endl;

	}
	for (const auto& current : v4) {
		cout << current << endl;
	}
	//cout << v4 << endl;
}
