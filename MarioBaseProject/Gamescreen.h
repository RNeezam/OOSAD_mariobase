#pragma once
#ifndef _GAMESCREEN
#define _GAMESCREEN

#include <SDL.h>

class GameScreen
{
protected:
	SDL_Renderer* mRenderer;
public:
	GameScreen(SDL_Renderer* renderer);
	~GameScreen();
	//! compulsory for the sub clasess to be implement
	virtual void Render();
	virtual void Update(float deltatime, SDL_Event e);
};

#endif // !_GAMESCREEN
