#ifndef _LABEL_
#define _LABEL_

#include "EngineDefines.h"
#include "ResourceTexture.h"
namespace DsdlEngine{
	class Label
	{
	public:
		Label();
		~Label();

		ResourceTexture* create(std::string text, int size, SDL_Color color, std::string fontPath, SDL_Renderer* r);
		void render(int x, int y, SDL_Renderer* r);

		//ResourceTexture* loadTTF(std::string text, int size, SDL_Color color);
	private:

		ResourceTexture* m_pTextTexture = nullptr;

		int m_fPosX;
		int m_fPosY;
		int m_fWidth;
		int m_fHeight;

		int m_iFrames;


		std::map<std::string, TTF_Font*> m_FontMap;
	};
}

#endif