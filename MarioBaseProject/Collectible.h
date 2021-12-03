#pragma once
#ifndef COLLECTIBLE_H
#define COLLECTIBLE_H

#include <SDL.h>
#include <iostream>
#include "Commons.h"
#include <string>
#include "LevelMap.h"
using namespace std;

class Texture2D;

class Collectible
{
public:
	SDL_Renderer* mRenderer;
	Vector2D mPosition;
	Texture2D* mTexture;
	

	float mCollisonRadius; //! circle type collision detection

public:
	Collectible(SDL_Renderer* renderer, string imagePath, Vector2D startPosition, LevelMap* map);
	~Collectible();
	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);
	void SetPosition(Vector2D newPosition);
	Vector2D getPosition();
	float GetCOllisionRadius();
	Rect2D GetCollisionBox();
	
public:
	LevelMap* mCurrentLevelMap;
};
#endif // !COLLECTIBLE_H


