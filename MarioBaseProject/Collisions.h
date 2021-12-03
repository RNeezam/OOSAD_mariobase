#pragma once
#ifndef _COLLISIONS
#define _COLLISIONS

#include <SDL_image.h>
#include "Commons.h"

class Character;
class Collectible;

class Collisions
{
public:
	~Collisions();
	static Collisions* Instance();
	bool Circle(Character* character1, Character* character2);
	bool Circle(Character* Character1, Character* Character2,Collectible* collectible2);
	bool Circle(Character* Character1, Character* Character2, Character* enemy);
	bool Box(Rect2D rect1, Rect2D rect2);
	bool Circle(Character * character1, Collectible * collectible);
private:
	Collisions();
	static Collisions* mInstance;
};

#endif // !_COLLISIONS

