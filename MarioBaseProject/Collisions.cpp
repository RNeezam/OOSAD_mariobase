#include "Collisions.h"
#include "Character.h"
#include "Collectible.h"

//! initialize the static attribute 
Collisions* Collisions::mInstance = NULL;

Collisions::Collisions()
{}
Collisions::~Collisions()
{
	mInstance = NULL;//! make the static Collisions pointer store NULL value
}
Collisions* Collisions::Instance()
{
	if (!mInstance)
	{
		mInstance = new Collisions();
	}
	return mInstance;
}
bool Collisions::Circle(Character* character1, Character* character2)
{
	Vector2D vec = Vector2D((character1->getPosition().x - character2->getPosition().x),
		(character1->getPosition().y - character2->getPosition().y));
	double distance = sqrt((vec.x*vec.x) + (vec.y*vec.y));
	double combinedDistance(character1->GetCOllisionRadius() +
		character2->GetCOllisionRadius());
	return distance < combinedDistance;
}
bool Collisions::Box(Rect2D rect1, Rect2D rect2)
{
	if (rect1.x + (rect1.width / 2) > rect2.x &&
		rect1.x + (rect1.width / 2) < rect2.x + rect2.width &&
		rect1.y + (rect1.height / 2) > rect2.y &&
		rect1.y + (rect1.height / 2) < rect2.y + rect2.height)
	{
		return true;
	}
	return false;
}
bool Collisions::Circle(Character* character1, Collectible* collectible)
{
	Vector2D vec = Vector2D((character1->getPosition().x - collectible->getPosition().x),
		(character1->getPosition().y - collectible->getPosition().y));	
	double distance = sqrt((vec.x*vec.x) + (vec.y*vec.y));
	double combinedDistance(character1->GetCOllisionRadius() +
		collectible->GetCOllisionRadius());
	return distance < combinedDistance;
}

