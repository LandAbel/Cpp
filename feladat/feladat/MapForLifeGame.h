#pragma once
#include <vector>
using namespace std;

class MapForLifeGame
{
public:
	MapForLifeGame(const int coordinateX);
	MapForLifeGame(const int coordinateX, const int coordinateY);
	MapForLifeGame(const int coordinateX, const double Probability);
	MapForLifeGame(const int coordinateX, const int coordinateY, const double Probability);
	MapForLifeGame(const int Height, const int Width, const int Top, const int Left, vector<vector<int>> smMap);

	void CreateMap(const int coordinateX, const int coordinateY, const double Probability = 0.1);

	void NextGeneration();

	int HelpWithGenerations(const int i, const int j);

	bool Dead;

	void Display();
	
	int ActualLevel()const;

private:
	vector<vector<int>> mMap;
	int mcoordinateX;
	int mcoordinateY;
	int mCurrentGen=1;

};