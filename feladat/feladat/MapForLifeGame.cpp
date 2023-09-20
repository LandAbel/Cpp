// includes necessary libraries for the code to work
#include "MapForLifeGame.h"
#include <random>
#include <vector>
#include <iostream>
using namespace std;

// sets up a random device and a default random engine
random_device randDev;
default_random_engine randEngine(randDev());

// sets up a uniform integer distribution with a range of 1 to 10
uniform_int_distribution<int> uniformal_dist(1, 10);


// constructor for creating a game map with a given x coordinate (cube shape)
MapForLifeGame::MapForLifeGame(const int coordinateX)
	: mcoordinateX(coordinateX)
	, mcoordinateY(coordinateX)
{
	CreateMap(mcoordinateX, mcoordinateY);
}

// constructor for creating a game map with given x and y coordinates (rectangle shape)
MapForLifeGame::MapForLifeGame(const int coordinateX, const int coordinateY)
	: mcoordinateX(coordinateX)
	, mcoordinateY(coordinateY)
{
	CreateMap(mcoordinateX, mcoordinateY);
}

// constructor for creating a game map with a given x coordinate and a probability of cell being alive (cube shape)
MapForLifeGame::MapForLifeGame(const int coordinateX, const double Probability)
	: mcoordinateX(coordinateX)
	, mcoordinateY(coordinateX)
{
	CreateMap(mcoordinateX, mcoordinateY, Probability);
}

// constructor for creating a game map with given x and y coordinates and a probability of cell being alive (rectangle shape)
MapForLifeGame::MapForLifeGame(const int coordinateX, const int coordinateY, const double Probability)
	: mcoordinateX(coordinateX)
	, mcoordinateY(coordinateY)
{
	CreateMap(mcoordinateX, mcoordinateY, Probability);
}

// constructor for creating a game map with a given height, width, top, left coordinate and a small map
MapForLifeGame::MapForLifeGame(const int height, const int width, const int top, const int left, vector<vector<int>> smallMap)
	: mcoordinateX(height)
	, mcoordinateY(width)
{
	CreateMap(mcoordinateX, mcoordinateY, 0);//0 probability
	int row_offset = top, col_offset = left;
	for (const auto& row : smallMap) {
		for (const auto& val : row) {
			mMap[row_offset][col_offset++] = val;
		}
		row_offset++;
		col_offset = left;
	}
}
// This function calculates the sum of neighboring cells of a given cell.
int MapForLifeGame::HelpWithGenerations(const int i, const int j) {
	int sum = 0;
	const int xStart = max(i - 1, 0);// Calculate the starting row index for neighboring cells.
	const int xEnd = min(i + 1, mcoordinateX - 1);// Calculate the ending row index for neighboring cells.
	const int yStart = max(j - 1, 0);// Calculate the starting column index for neighboring cells.
	const int yEnd = min(j + 1, mcoordinateY - 1);// Calculate the ending column index for neighboring cells.

	for (int x = xStart; x <= xEnd; x++) {
		for (int y = yStart; y <= yEnd; y++) {
			if (x == i && y == j) continue;// Skip the current cell.
			sum += mMap[x][y];
		}
	}

	return sum;
}
// function to calculate the next generation of the game
void MapForLifeGame::NextGeneration() {

	bool anyAlive = false;

	// create a new map to hold the next generation
	vector<vector<int>> newMap(mcoordinateX, vector<int>(mcoordinateY, 0));

	for (int i = 0; i < mcoordinateX; i++) {
		for (int j = 0; j < mcoordinateY; j++) {
			int sum = HelpWithGenerations(i, j);
			// determine the current cell's state
			int cell = mMap[i][j];
			if (cell) {
				if (sum == 2 || sum == 3) {
					newMap[i][j] = 1;
					anyAlive = true;
				}
			}
			else {
				if (sum == 3) {
					newMap[i][j] = 1;
					anyAlive = true;
				}
			}
		}
	}
	// Update the map with the new generation
	mMap = newMap;
	// Set the Dead flag if no cells are alive
	Dead = !anyAlive;
	// Increment the current generation counter
	mCurrentGen++;
}

// This function creates a new map for the game of life with random cells.
void MapForLifeGame::CreateMap(const int CoordX, const int CoordY, const double Prob) {

	mMap.resize(CoordX);

	// Loop through all cells in the map and set them to either alive or dead randomly
	for (int i = 0; i < CoordX; i++) {
		mMap[i].resize(CoordY);
		for (int j = 0; j < CoordY; j++) {
			mMap[i][j] = (uniformal_dist(randEngine) <= Prob * 10) ? 1 : 0;
		}
	}
}
// This function displays the current state of the game of life in the console.
void MapForLifeGame::Display() {
	// Clear the console
	system("cls");
	// Get the dimensions of the map
	int width = mcoordinateY;
	int height = mcoordinateX;
	//Top of the map
	cout << "+" << string(width * 2 - 1, '-') << "+\n";
	for (int y = 0; y < height; y++) {
		cout << "|";//left side of the map
		for (int x = 0; x < width; x++) {
			if (mMap[y][x]) cout << "# ";//# marks the living cells
			else cout << ". ";
		}
		cout << "|\n";//right side of the map
	}
	//Bottom of the map
	cout << "+" << string(width * 2 - 1, '-') << endl;
	//Current gen
	cout << "Generation:\t" << mCurrentGen << "\n\nPress [RETURN] for the next generation...";
	//Wait until Enter pressed
	cin.get();
}
// This function returns the current generation number.
int MapForLifeGame::ActualLevel() const {
	return mCurrentGen;
}