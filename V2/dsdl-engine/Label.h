#ifndef _LABEL_
#define _LABEL_

#include "EngineBaseNode.h"

namespace DsdlEngine{
	class Label : public EngineBaseNode
	{
	public:
		Label();
		~Label();


		void create(std::string text, int size, SDL_Color color, std::string path);

		bool load(SDL_Renderer* r);

		//ResourceTexture* create(std::string text, int size, SDL_Color color, std::string fontPath);
	
		
		//void render(SDL_Renderer* r);

		//ResourceTexture* loadTTF(std::string text, int size, SDL_Color color);
	private:

		//ResourceTexture* m_pTextTexture = nullptr;

		//int m_fWidth;
		//int m_fHeight;

		//int m_iFrames;
		//Font
		/*TTF_Font* font;


		std::map<std::string, TTF_Font*> m_FontMap;


		std::string labelText;
		std::string fontPath;
		int textSize;
		SDL_Color textColor;*/

	};
}

#endif