#include "Texture2D.h"
#include <SDL_image.h>
#include <iostream>

using namespace std;

Texture2D::Texture2D(SDL_Renderer* renderer)
{
	mRenderer = renderer;
}
Texture2D::~Texture2D() {
	Free();//! clear the mTexture Pointer
	mRenderer = NULL;
}

bool Texture2D::LoadFromFile(string path)
{
	//remove the memory from previous texture
	Free();
	//! load image 
	SDL_Surface* pSurface = IMG_Load(path.c_str());
	if (pSurface != NULL)
	{
		SDL_SetColorKey(pSurface, SDL_TRUE, SDL_MapRGB(pSurface->format, 0, 0XFF, 0XFF));
		//! create texture
		mTexture = SDL_CreateTextureFromSurface(mRenderer, pSurface);
		if (mTexture == NULL)
		{
			cout << "Unable to crete texture from Surface" << endl;
		}
		else
		{
			mWidth = pSurface->w;
			mHeight = pSurface->h;
		}
		SDL_FreeSurface(pSurface);
	}
	else
	{
		cout << "Unable to crete texture from Surface" << endl;
	}
	return mTexture != NULL;//return true, if mTexture == NULL  -> false
}
void Texture2D::Free()
{
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
	}
}
//!			Drawing     spawn location         flip -> horizontal or vertitcal
void Texture2D::Render(Vector2D newPosition, SDL_RendererFlip flip,
	double angle)
{
	//! set where to render thetexture
	SDL_Rect renderLocation = { newPosition.x, newPosition.y, mWidth, mHeight};
	//! render to screen
	SDL_RenderCopyEx(mRenderer, mTexture, NULL, &renderLocation, 0, NULL, flip);
}