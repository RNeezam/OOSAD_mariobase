#include "Character.h"
#include "Texture2D.h"
#include "Constants.h"

using namespace std;

Character::Character(SDL_Renderer* renderer, string imagepth, Vector2D newPosition, LevelMap* map)
{
	mPosition = newPosition;
	mRenderer = renderer;
	mTexture = new Texture2D(mRenderer);

	mCurrentLevelMap = map;

	if (!mTexture->LoadFromFile(imagepth))
	{
		cout << "Failed to load charcter texture!" << endl;
	}
	mMovingLeft = false;
	mMovingRight = false;
	mCollisonRadius = 15.0f;
}
Character::~Character()
{
	mRenderer = NULL;
}
void Character::Render()
{
	if (mFacingDirection == FACING_LEFT)
	{
		mTexture->Render(mPosition, SDL_FLIP_HORIZONTAL);
	}
	else
	{
		mTexture->Render(mPosition, SDL_FLIP_NONE);
	}
}
void Character::Update(float deltaTime, SDL_Event e)
{
	if (mJumping)
	{
		mPosition.y -= mJumpForce * deltaTime;
		mJumpForce -= JUMP_FORCE_DECREMENT * deltaTime;
		if (mJumpForce <= 0.0f)
		{
			mJumping = false;
		}
	}
	int centralXPosition = (int)(mPosition.x + (mTexture->getWidth()*0.5f)) / TILE_WIDTH;
	int footPosition = (int)(mPosition.y + mTexture->getHeight()) / TILE_HEIGHT;
	if (mCurrentLevelMap->GetTileAt(footPosition, centralXPosition) == 0)
	{
		ApplyGravity(deltaTime);
	}
	else
	{
		mCanJump = true;
	}
	//mCanJump = true;
	if (mMovingLeft)
	{
		MoveLeft(deltaTime);
	}
	if (mMovingRight)
	{
		MoveRight(deltaTime);
	}
}
void Character::SetPosition(Vector2D newPosition)
{
	mPosition = newPosition;
}
Vector2D Character::getPosition()
{
	return mPosition;
}
void Character::MoveLeft(float deltaTime)
{
	mFacingDirection = FACING_LEFT;
	mPosition.x -= deltaTime * MOVEMENT_SPEED;
}
void Character::MoveRight(float deltaTime)
{
	mFacingDirection = FACING_RIGHT;
	mPosition.x += deltaTime * MOVEMENT_SPEED;
}
void Character::ApplyGravity(float deltaTime)
{
	mPosition.y += GRAVITY * deltaTime;
}
void Character::Jump()
{
	if (!mJumping)
	{
		mJumpForce = INITIAL_JUMP_FORCE;
		mJumping = true;
		mCanJump = false;
	}
}
float Character::GetCOllisionRadius()
{
	return mCollisonRadius;
}
Rect2D Character::GetCollisionBox()
{
	return Rect2D(mPosition.x, mPosition.y, mTexture->getWidth(), mTexture->getHeight());
}
