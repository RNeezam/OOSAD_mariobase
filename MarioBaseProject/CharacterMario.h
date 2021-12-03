#pragma once
#ifndef _CHARACTER_MARIO_H
#define _CHARACTER_MARIO_H

#include "Character.h"
#include <SDL.h>
#include <string>

using namespace std;

class CharacterMario : public Character
{
public:
	CharacterMario(SDL_Renderer* renderer, string imagepth,
		Vector2D startPosition, LevelMap* map);
	~CharacterMario();
protected:
	void Update(float deltaTime, SDL_Event e);
};

#endif // !_CHARACTER_MARIO_H

