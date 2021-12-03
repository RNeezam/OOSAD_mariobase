#pragma once
#ifndef _COIN_H
#define _COIN_H

#include "Collectible.h"
#include <SDL.h>
#include <string>

using namespace std;

class Coin : public Collectible
{
public:
	Coin(SDL_Renderer* renderer, string imagepth,
		Vector2D startPosition, LevelMap* map);
	~Coin();
protected:
	void Update(float deltaTime, SDL_Event e);
};

#endif // !_COIN_H
