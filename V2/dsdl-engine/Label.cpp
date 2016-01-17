#include "Label.h"


namespace DsdlEngine{

	Label::Label(){}

	Label::~Label(){}

	//// Load and Create text texture
	ResourceTexture* Label::create(std::string text, int size, SDL_Color color, std::string fontPath, SDL_Renderer* r){

		if (!TTF_WasInit()){
			TTF_Init();
		}

		//Check if font in chache
		auto it = m_FontMap.find(fontPath);


		m_pTextTexture = new ResourceTexture();

		// if not load and create texture
		if (it == m_FontMap.end()){

			//open font
			font = TTF_OpenFont(fontPath.c_str(), size);
			if (font == NULL){
				DEBUG_MSG("TTF_OpenFont Error : " + std::string(TTF_GetError()));
			}

			m_pTextTexture->loadTTF(text, color, font, r);

			m_FontMap[fontPath] = font;
		}
		else{//create texture
			font = it->second;
			m_pTextTexture->loadTTF(text, color, font, r);

		}

		return m_pTextTexture;
	}


	void Label::render(int x, int y, SDL_Renderer* r){

		m_pTextTexture->render(x, y, r);
	}
}