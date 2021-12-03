#pragma once
#ifndef _GAMESCREEN_LEVEL_1
#define _GAMESCREEN_LEVEL_1

#include <SDL.h>
#include "Commons.h"
#include "Gamescreen.h"
#include "Character.h"
#include "Collectible.h"
#include "CharacterMario.h"
#include "LevelMap.h"
#include "CharacterLuigi.h"
#include "CharacterEnemy.h"
#include "Coin.h"

class Texture2D;
class Character;

class GameScreenLevel1 : public GameScreen
{
public:
	Texture2D* mBackground;
public:
	GameScreenLevel1(SDL_Renderer* renderer);
	~GameScreenLevel1();
	void Render();
	void Update(float deltaTime, SDL_Event e);
public:
	bool SetUpLevel(); //! render all the obj and character
	void SetUpMap(); //! matching the 1 and 0 to setup the collision det
	LevelMap* mLevelMap;
	Character* mario;
	Character* luigi;
	Character* enemy;
	Collectible* coin;
	float mBackgroundYPos;
};

#endif // !_GAMESCREEN_LEVEL_1
