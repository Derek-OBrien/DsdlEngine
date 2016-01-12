#ifndef _SPRITE_
#define _SPRITE_

#include "ResourceTexture.h"
#include <string>

namespace DsdlEngine{

	class Sprite
	{
	public:
		Sprite();
		~Sprite();

		void createSprite(float x, float y, float w, float h, std::string texturePath, SDL_Renderer* r);
		void createSpriteWithAnimation( SDL_Renderer* r);


		void draw(SDL_Renderer* renderer);


		void setPosX(float x){ m_fPosX += x; }
		void setPosY(float y){ m_fPosY += y; }
	private:

		float m_fPosX;
		float m_fPosY;
		float m_fWidth;
		float m_fHeight;

		int m_iFrames = 1;
		ResourceTexture m_SpriteTexture;
		
		SDL_Rect m_gSpriteClips[30];	//frames for animation
		
		SDL_Rect* m_currentFrame;		//current animation frame
		SDL_Rect objectBoundingBox;
	};
}

#endif