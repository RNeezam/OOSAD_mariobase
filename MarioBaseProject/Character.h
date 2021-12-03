#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <SDL.h>
#include <iostream>
#include "Commons.h"
#include <string>
#include "LevelMap.h"
using namespace std;

class Texture2D;

class Character
{
public:
	SDL_Renderer* mRenderer;
	Vector2D mPosition;
	Texture2D* mTexture;
	FACING mFacingDirection;

	bool mMovingLeft;
	bool mMovingRight;

	bool mJumping;
	bool mCanJump;
	float mJumpForce;
	float mCollisonRadius; //! circle type collision detection

	//! abstract method/function
	virtual void MoveLeft(float deltaTime);
	virtual void MoveRight(float deltaTime);
	virtual void ApplyGravity(float deltaTime);
	virtual void Jump();
public:
	Character(SDL_Renderer* renderer, string imagePath, Vector2D startPosition, LevelMap* map);
	~Character();
	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);
	void SetPosition(Vector2D newPosition);
	Vector2D getPosition();
	float GetCOllisionRadius();
	Rect2D GetCollisionBox();
	bool isJumping() { return mJumpForce; }
	void CancelJump() { mJumpForce = false; }
public:
	LevelMap* mCurrentLevelMap;
};
#endif // !CHARACTER_H

