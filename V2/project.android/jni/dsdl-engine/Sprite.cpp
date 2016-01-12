
#include "Sprite.h"
#include "EngineError.h"

namespace DsdlEngine{

	Sprite::Sprite(){}

	Sprite::~Sprite(){}

	void Sprite::createSprite(float x, float y, float w, float h, std::string texturePath, SDL_Renderer* r){

		m_fPosX = x;
		m_fPosY = y;
		m_fWidth = w;
		m_fHeight = h;

		if (!m_SpriteTexture.loadFromFile(texturePath, r))
			dsdl_error("Faild to load sprite");
	
		else{
			dsdl_error("Loaded sprite");

			for (int i = 0; i < 2; i++){
				m_gSpriteClips[i].x = 0;
				m_gSpriteClips[i].y = 0;
				m_gSpriteClips[i].w = m_fWidth;
				m_gSpriteClips[i].h = m_fHeight;
			}

			objectBoundingBox.x = m_fPosX;
			objectBoundingBox.y = m_fPosY;
			objectBoundingBox.w = m_fWidth;
			objectBoundingBox.h = m_fHeight;

		}
	}

	void Sprite::createSpriteWithAnimation(SDL_Renderer* r){

		m_currentFrame = &m_gSpriteClips[m_iFrames / 5];
		m_SpriteTexture.render(m_fPosX, m_fPosY, m_currentFrame, r);

		++m_iFrames;
		if (m_iFrames / 5 >= 1)
			m_iFrames = 0;
	}


	void Sprite::draw(SDL_Renderer* r){
		createSpriteWithAnimation(r);
		m_SpriteTexture.render(m_fPosX, m_fPosY, m_gSpriteClips, r);

		SDL_SetRenderDrawColor(r, 0x00, 0xff, 0x00, 0xff);
		SDL_RenderDrawRect(r, &objectBoundingBox);
	}

}