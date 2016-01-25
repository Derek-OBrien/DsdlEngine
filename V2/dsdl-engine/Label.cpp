#include "Label.h"


namespace DsdlEngine{

	Label::Label(){
		setEngineNodeType(NodeType::LABEL);
	}

	Label::~Label(){}



	void Label::create(std::string text, int size, SDL_Color color, std::string fontFilePath){

		labelText = text;
		textSize = size;
		textColor = color;
		setAssetPath(fontFilePath);
	}


	//// Load and Create text texture
	/*bool Label::load(SDL_Renderer* r){

		//m_posX = x;
		//m_posY = y;

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
			font = TTF_OpenFont(temp.c_str(), textSize);
			if (font == NULL){
				DEBUG_MSG("TTF_OpenFont Error : " + std::string(TTF_GetError()));
			}

			engineTexture->loadTTF(labelText, textColor, font, r);

			m_FontMap[temp] = font;
		}
		else{//create texture
			font = it->second;
			engineTexture->loadTTF(labelText, textColor, font, r);

		}

		return engineTexture;
	}

	/**	void Label::render( SDL_Renderer* r){

		engineTexture->render(m_posX, m_posY, r);
	}*/
}