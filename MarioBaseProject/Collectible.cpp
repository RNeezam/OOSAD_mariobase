#include "Collectible.h"
#include "Texture2D.h"
#include "Constants.h"

using namespace std;

Collectible::Collectible(SDL_Renderer* renderer, string imagepth, Vector2D newPosition, LevelMap* map)
{
	mPosition = newPosition;
	mRenderer = renderer;
	mTexture = new Texture2D(mRenderer);

	mCurrentLevelMap = map;

	if (!mTexture->LoadFromFile(imagepth))
	{
		cout << "Failed to load collectible texture!" << endl;
	}
	
	mCollisonRadius = 15.0f;
}
Collectible::~Collectible()
{
	mRenderer = NULL;
}
void Collectible::Render()
{
	
	mTexture->Render(mPosition, SDL_FLIP_NONE);
}
void Collectible::Update(float deltaTime, SDL_Event e)
{
	int centralXPosition = (int)(mPosition.x + (mTexture->getWidth()*0.5f)) / TILE_WIDTH;
	int footPosition = (int)(mPosition.y + mTexture->getHeight()) / TILE_HEIGHT;
	
}
void Collectible::SetPosition(Vector2D newPosition)
{
	mPosition = newPosition;
}

Vector2D Collectible::getPosition()
{
	return mPosition;
}

float Collectible::GetCOllisionRadius()
{
	return mCollisonRadius;
}
Rect2D Collectible::GetCollisionBox()
{
	return Rect2D(mPosition.x, mPosition.y, mTexture->getWidth(), mTexture->getHeight());
}
