#include "CharacterMario.h"

CharacterMario::CharacterMario(SDL_Renderer* renderer, string imagepth,
	Vector2D startPosition, LevelMap* map) : Character(renderer, imagepth, startPosition, map)
{}

CharacterMario::~CharacterMario()
{}

void CharacterMario::Update(float deltaTime, SDL_Event e)
{
	switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_a:
			mMovingLeft = true;
			break;
		case SDLK_d:
			mMovingRight = true;
			break;
		case SDLK_SPACE:
			if (mCanJump)
			{
				Jump();
			}
		}
		break;
	case SDL_KEYUP:
		switch (e.key.keysym.sym)
		{
		case SDLK_a:
			mMovingLeft = false;
			break;
		case SDLK_d:
			mMovingRight = false;
			break;
		}
		break;
	}
	Character::Update(deltaTime, e);
}