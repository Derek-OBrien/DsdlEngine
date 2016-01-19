#include "Label.h"


namespace DsdlEngine{

	Label::Label(){}

	Label::~Label(){}

	//// Load and Create text texture
	ResourceTexture* Label::create(int x, int y, std::string text, int size, SDL_Color color, std::string fontPath, SDL_Renderer* r){

		m_posX = x;
		m_posY = y;

		if (!TTF_WasInit()){
			TTF_Init();
		}

		std::string temp = "../../assets/" + fontPath;


		//Check if font in chache
		auto it = m_FontMap.find(temp);


		engineTexture = new ResourceTexture();

		// if not load and create texture
		if (it == m_FontMap.end()){

			//open font
			font = TTF_OpenFont(temp.c_str(), size);
			if (font == NULL){
				DEBUG_MSG("TTF_OpenFont Error : " + std::string(TTF_GetError()));
			}

			engineTexture->loadTTF(text, color, font, r);

			m_FontMap[temp] = font;
		}
		else{//create texture
			font = it->second;
			engineTexture->loadTTF(text, color, font, r);

		}

		return engineTexture;
	}


	void Label::render( SDL_Renderer* r){

		engineTexture->render(m_posX, m_posY, r);
	}
}