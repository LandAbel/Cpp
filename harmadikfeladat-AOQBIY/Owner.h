#pragma once
#include <string>
#include "SemiDetachedHouse.h"

using namespace std;

class Owner
{
public:
	static void maintain(const string& path, vector<SemiDetachedHouse>& vec);

	vector<SemiDetachedHouse> get_houses();

private:
	vector<SemiDetachedHouse> mHouses;

	static void add2sdh(const string& line, SemiDetachedHouse& sdh);
	static void addAlbi(const vector<string>& albinfo, SemiDetachedHouse& sdh);
	static void addCsalbi(const vector<string>& csalbinfo, SemiDetachedHouse& sdh);
	static void addFlat(const vector<string>& flatInfo, SemiDetachedHouse& sdh);
	static void addGarazs(const vector<string>& garinfo, SemiDetachedHouse& sdh);
	static SemiDetachedHouse createSemiDetachedHouse(const string& s);

};
