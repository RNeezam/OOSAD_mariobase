#pragma once

struct Vector2D
{
	float x;
	float y;

	Vector2D()
	{
		x = 0.0f;
		y = 0.0f;
	}
	Vector2D(float initialX, float initialY)
	{
		x = initialX;
		y = initialY;
	}
};

struct Rect2D
{
	float x, y, width, height;

	Rect2D(float xPos, float yPos, float width, float height)
	{
		x = xPos;
		y = yPos;
		this->width = width;
		this->height = height;
	}
};

enum FACING
{
	FACING_LEFT =0,
	FACING_RIGHT
};

enum SCREENS
{
	SCREEN_INTRO =0,
	SCREEN_MENU,
	SCREEN_LEVEL1,
	SCREEN_LEVEL2
};