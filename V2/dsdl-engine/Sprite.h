#ifndef _SPRITE_
#define _SPRITE_

#include "EngineBaseNode.h"

namespace DsdlEngine{

	class Sprite :public EngineBaseNode
	{
	public:
		Sprite();
		~Sprite();

		/*Create Basic Sprite
			x = x position
			y = y position
			w = sprite width
			h = sprite heigth
			texturePath = file path to sprite assest
			r = pointer to window renderer
		*/
		ResourceTexture* createSprite(int w, int h, std::string texturePath, SDL_Renderer* r);

		/*Create Sprite with Bounding Box
		x = x position
		y = y position
		w = sprite width
		h = sprite heigth
		texturePath = file path to sprite assest
		r = pointer to window renderer
		*/
		void createSpriteWithSpriteSheet(int w, int h, int f, int o, std::string texturePath, SDL_Renderer* r);
		
		
		void createSpriteWithAnimation( SDL_Renderer* r);


		//void draw(SDL_Renderer* renderer);


		void render(SDL_Renderer* r);

		void setPosX(int x){ m_fPosX += x; objectBoundingBox.x += x; }
		void setPosY(int y){ m_fPosY += y; objectBoundingBox.y += y; }
	private:

		int m_fPosX;
		int m_fPosY;
		int m_fWidth;
		int m_fHeight;

		int m_iFrames;
		//ResourceTexture* m_SpriteTexture = nullptr;
		
		SDL_Rect m_gSpriteClips[30];	//frames for animation
		
		SDL_Rect* m_currentFrame;		//current animation frame
		SDL_Rect objectBoundingBox;
	};
}

#endif