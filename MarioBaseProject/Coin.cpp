#include "Coin.h"

Coin::Coin(SDL_Renderer* renderer, string imagepth,
	Vector2D startPosition, LevelMap* map) : Collectible(renderer, imagepth, startPosition, map)
{}

Coin::~Coin()
{}

void Coin::Update(float deltaTime, SDL_Event e)
{
	
	Collectible::Update(deltaTime, e);
}