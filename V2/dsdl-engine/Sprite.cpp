
#include "Sprite.h"

namespace DsdlEngine{

	Sprite::Sprite(){}

	Sprite::~Sprite(){}

	ResourceTexture* Sprite::createSprite(int w, int h, std::string texturePath, SDL_Renderer* r){

		m_fWidth = w;
		m_fHeight = h;

		if (!engineTexture->loadFromFile(texturePath, r))
			DEBUG_MSG("Faild to load sprite");

		else{
			DEBUG_MSG("Loaded sprite");

			for (int i = 0; i < 2; i++){
				m_gSpriteClips[i].x = 0;
				m_gSpriteClips[i].y = 0;
				m_gSpriteClips[i].w = m_fWidth;
				m_gSpriteClips[i].h = m_fHeight;
			}

			//objectBoundingBox.x = m_posX;
			//objectBoundingBox.y = m_posY;
			objectBoundingBox.w = m_fWidth;
			objectBoundingBox.h = m_fHeight;

		}

		return engineTexture;
	}



	void Sprite::createSpriteWithAnimation(SDL_Renderer* r){

		m_currentFrame = &m_gSpriteClips[m_iFrames / 5];
		//engineTexture->render(m_posX, m_posY, r, m_currentFrame);

		++m_iFrames;
		if (m_iFrames / 5 >= m_iFrames)
			m_iFrames = 0;
	}


	void Sprite::render(SDL_Renderer* r){
		createSpriteWithAnimation(r);
		//engineTexture->render(m_posX, m_posY, r, m_gSpriteClips);

		SDL_SetRenderDrawColor(r, 0x00, 0xff, 0x00, 0xff);
		SDL_RenderDrawRect(r, &objectBoundingBox);
	}



	void Sprite::createSpriteWithSpriteSheet(int w, int h, int f, int o, std::string texturePath, SDL_Renderer* r){

		//m_posX = x;
		//m_posY = y;
		m_fWidth = w;
		m_fHeight = h;
		m_iFrames = f;


		if (!engineTexture->loadFromFile(texturePath, r))
			DEBUG_MSG("Faild to load sprite");

		else{
			DEBUG_MSG("Loaded sprite");

			for (int i = 0; i < m_iFrames; i++){
				m_gSpriteClips[i].x = o;
				m_gSpriteClips[i].y = 0;
				m_gSpriteClips[i].w = m_fWidth;
				m_gSpriteClips[i].h = m_fHeight;

				o += m_fWidth;
			}

			//objectBoundingBox.x = m_posX;
			//objectBoundingBox.y = m_posY;
			objectBoundingBox.w = m_fWidth;
			objectBoundingBox.h = m_fHeight;

		}
	}
}