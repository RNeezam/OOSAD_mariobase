#pragma once
#ifndef CHARACTER_ENEMY_H
#define CHARACTER_ENEMY_H

#include "Character.h"
#include <SDL.h>
#include <string>

using namespace std;

class CharacterEnemy : public Character
{
public:
	CharacterEnemy(SDL_Renderer* renderer, string imagepth,
		Vector2D startPosition, LevelMap* map);
	~CharacterEnemy();
protected:
	void Update(float deltaTime, SDL_Event e);
};

#endif // !_ENEMY_H
