#include "LevelMap.h"

LevelMap::LevelMap(int map[MAP_HEIGHT][MAP_WIDTH])//! size of the map 13*16
{
	//! initialize the 2D array
	mMap = new int*[MAP_HEIGHT];
	for (unsigned int i = 0; i < MAP_HEIGHT; i++)//! index 0 to 12
	{
		mMap[i] = new int[MAP_WIDTH];
	}
	//! populate the array, copy the pass in 2D array map values to the mMap
	for (unsigned int i = 0; i < MAP_HEIGHT; i++)//! index 0 to 12
	{
		for (unsigned int j = 0; j < MAP_WIDTH; j++)
		{
			mMap[i][j] = map[i][j];
		}
	}
}
LevelMap::~LevelMap()
{
	for (unsigned int i = 0; i < MAP_HEIGHT; i++)
	{
		delete mMap[i];
	}
	delete[] mMap;
}
int LevelMap::GetTileAt(unsigned int h, unsigned int w)
{     //       13				16
	if (h < MAP_HEIGHT && w < MAP_WIDTH)
	{
		return mMap[h][w];
	}
	return 0;
}
void LevelMap::ChangeTileAt(unsigned int row, unsigned int column, unsigned int newValue)
{
	mMap[row][column] = newValue;
}