#include "GameScreenLevel1.h"
#include <iostream>
#include "Texture2D.h"
#include "Collisions.h"

bool isActive = true;
int gameScore;
GameScreenLevel1::GameScreenLevel1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	SetUpLevel();
	mLevelMap = NULL;
}
GameScreenLevel1::~GameScreenLevel1()
{
	delete mBackground;
	mBackground = NULL;
	delete mario;
	mario = NULL;
	delete luigi;
	luigi = NULL;
	delete enemy;
	enemy = NULL;
	delete coin;
	coin = NULL;
}
void GameScreenLevel1::Update(float deltaTime, SDL_Event e)
{
	mario->Update(deltaTime, e);

	luigi->Update(deltaTime, e);
	
	enemy->Update(deltaTime, e);

	coin->Update(deltaTime, e);
	
	static bool once = []() {
		cout << "Score :" << gameScore << endl;
		return true;
	} ();

	if (Collisions::Instance()->Circle(mario, luigi))
	{
		//cout << "Player-player Collide" << endl; 
	}
	if (Collisions::Instance()->Circle(mario, coin)|| Collisions::Instance()->Circle(luigi, coin))
	{
		static bool once = []() {
			gameScore = gameScore + 100;
			cout << "Score :" << gameScore << endl;
			//cout << "Score : " + gameScore << endl;
			isActive = false;
			return true;
			
		} ();
	}
	
	if (Collisions::Instance()->Circle(mario, enemy)|| Collisions::Instance()->Circle(luigi, enemy))
	{
		static bool once = []() {
			cout << "Health -1" << endl;	
			return true;

		} ();
		//cout << "Player-Enemy Collide" << endl;
	}
	/*if (Collisions::Box(mario->GetCollisionBox(), luigi->GetCollisionBox()))
	{
		cout << "Box Collide" << endl;
	}*/
}
void GameScreenLevel1::Render()
{
	
	mBackground->Render(Vector2D(0, mBackgroundYPos), SDL_FLIP_NONE);
	mario->Render();
	luigi->Render();
	enemy->Render();
	if (isActive == true) { coin->Render(); }
}
bool GameScreenLevel1::SetUpLevel()
{
	SetUpMap();
	mario = new CharacterMario(mRenderer, "Images/Mario.png", Vector2D(90, 330), mLevelMap);
	luigi = new CharacterLuigi(mRenderer, "Images/Luigi.png", Vector2D(380, 330), mLevelMap);
	enemy = new CharacterEnemy(mRenderer, "Images/KoopaEnemy.png", Vector2D(400, 30), mLevelMap);
	coin = new Coin(mRenderer, "Images/Coin.png", Vector2D(250, 200), mLevelMap);

	mBackground = new Texture2D(mRenderer);
	if (!mBackground->LoadFromFile("Images/BackgroundL2.png"))
	{
		cout << "Failed to load background" << endl;
		return false;
	}
	mBackgroundYPos = 0.0f;
	return true;
}
void GameScreenLevel1::SetUpMap()
{
	int map[MAP_HEIGHT][MAP_WIDTH] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	if (mLevelMap != NULL)
	{
		delete mLevelMap;
	}
	mLevelMap = new LevelMap(map);
}

 

