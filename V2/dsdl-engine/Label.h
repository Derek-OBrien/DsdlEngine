#ifndef _LABEL_
#define _LABEL_

#include "EngineBaseNode.h"

namespace DsdlEngine{
	class Label : public EngineBaseNode
	{
	public:
		Label();
		~Label();

		ResourceTexture* create(std::string text, int size, SDL_Color color, std::string fontPath, SDL_Renderer* r);
	
		
		//void render(SDL_Renderer* r);

		//ResourceTexture* loadTTF(std::string text, int size, SDL_Color color);
	private:

		//ResourceTexture* m_pTextTexture = nullptr;

		int m_fPosX;
		int m_fPosY;
		int m_fWidth;
		int m_fHeight;

		int m_iFrames;
		//Font
		TTF_Font* font = NULL;


		std::map<std::string, TTF_Font*> m_FontMap;
	};
}

#endif