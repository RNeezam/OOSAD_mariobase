#pragma once
#ifndef _CHARACTER_LUIGI_H
#define _CHARACTER_LUIGI_H

#include "Character.h"
#include <SDL.h>
#include <string>

using namespace std;

class CharacterLuigi : public Character
{
public:
	CharacterLuigi(SDL_Renderer* renderer, string imagepth,
		Vector2D startPosition, LevelMap* map);
	~CharacterLuigi();
protected:
	void Update(float deltaTime, SDL_Event e);
};

#endif // !_CHARACTER_LUIGI_H
