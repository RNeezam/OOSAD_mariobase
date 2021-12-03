#pragma once
#ifndef _GAMESCREEN_MANAGER
#define _GAMESCREEN_MANAGER

#include <SDL.h>
#include "Commons.h"

class GameScreen;

class GameScreenManager
{
private:
	SDL_Renderer* mRenderer;
	GameScreen* mCurrentScreen;
public:
	GameScreenManager(SDL_Renderer* renderer, SCREENS startScreen);
	~GameScreenManager();
	void Render();
	void Update(float deltatime, SDL_Event e);
	void ChangeScreen(SCREENS newScreen);
};

#endif // !_GAMESCREEN_MANAGER
