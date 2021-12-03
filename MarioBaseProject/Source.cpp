#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>
#include "Constants.h"
#include "Commons.h"
#include "Texture2D.h"
#include "GameScreenManager.h"
using namespace std;

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
GameScreenManager* gameScreenManager;
Uint32 gOldTime;
void Render();
bool InitSDL();
void CloseSDL();

bool InitSDL()
{
	if (SDL_Init(SDL_INIT_VIDEO < 0))
	{
		cout << "SDL did not initialize. ERROR: " << SDL_GetError();
		return false;
	}
	else
	{
		gWindow = SDL_CreateWindow("Mario Base Level",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN); //! upon window creating
		if (gWindow == NULL) //! check gWindow
		{
			cout << "Windows was not created.Error: " << SDL_GetError();
			return false;
		}
		//! initialize the gRenderer
		gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
		//! check gRenderer
		if (gRenderer != NULL)
		{
			int imageFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imageFlags)& imageFlags))
			{
				cout << "SDL_image count not initialize. Error: " << SDL_GetError();
				return false;
			}
		}
		else
		{
			cout << "Renderer count not initialize. Error: " << SDL_GetError();
			return false;
		}

		return true;
	}
}
void CloseSDL()
{
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	delete gameScreenManager;
	gameScreenManager = NULL;
	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;
	IMG_Quit();
	SDL_Quit();
}
bool Update()
{
	Uint32 newTime = SDL_GetTicks();
	SDL_Event e;
	SDL_PollEvent(&e);

	switch (e.type)
	{
	case SDL_QUIT:
		return true;
	case SDL_KEYUP:
		switch (e.key.keysym.sym)
		{
			case SDLK_q:
				return true;
		}
	}
	gameScreenManager->Update((float)(newTime - gOldTime) / 1000.0f, e);
	gOldTime = newTime;
	return false;
}
void Render()
{
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(gRenderer);
	gameScreenManager->Render();
	SDL_RenderPresent(gRenderer);
}
int main(int argc, char* args[])
{
	if (InitSDL())
	{
		gameScreenManager = new GameScreenManager(gRenderer, SCREEN_LEVEL1);
		gOldTime = SDL_GetTicks();
	}
	bool quit = false;
	while (!quit)
	{
		Render();
		quit = Update();
	}
	CloseSDL();
	return 0;
}