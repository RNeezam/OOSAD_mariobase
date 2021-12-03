#pragma once
#ifndef _LEVELMAP_H
#define _LEVELMAP_h

#include "Constants.h"

class LevelMap
{
public:
	LevelMap(int map[MAP_HEIGHT][MAP_WIDTH]);//! size of the map 13*16
	~LevelMap();
	int GetTileAt(unsigned int h, unsigned int w);
	void ChangeTileAt(unsigned int row, unsigned int column, unsigned int newValue);
private:
	int** mMap; //! using 2 Dimentioanl array 
};
#endif // !_LEVELMAP_H

