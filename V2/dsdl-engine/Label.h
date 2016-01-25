#ifndef _LABEL_
#define _LABEL_

#include "EngineBaseNode.h"

namespace DsdlEngine{
	class Label : public EngineBaseNode
	{
	public:
		Label();
		~Label();

		/**
		* Create a TTF label
		*
		* @param text The initial text.
		* @param fontFilePath A font file.
		* @param fontSize The font size. This value must be > 0.
		* @param color The Color of the label
		*/

		void create(std::string text, int fontSize, SDL_Color color, std::string fontFilePath);

		//bool load(SDL_Renderer* r);

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