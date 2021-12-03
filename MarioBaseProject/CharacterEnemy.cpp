#include "CharacterEnemy.h"

CharacterEnemy::CharacterEnemy(SDL_Renderer* renderer, string imagepth,
	Vector2D startPosition, LevelMap* map) : Character(renderer, imagepth, startPosition, map)
{}

CharacterEnemy::~CharacterEnemy()
{}

void CharacterEnemy::Update(float deltaTime, SDL_Event e)
{
	mMovingLeft = true;
	
	Character::Update(deltaTime, e);
}