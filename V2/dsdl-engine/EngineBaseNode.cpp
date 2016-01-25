
#include "EngineBaseNode.h"

namespace DsdlEngine{


	EngineBaseNode::EngineBaseNode(){}

	EngineBaseNode::~EngineBaseNode(){}



	void EngineBaseNode::create(int w, int h, std::string path){
		setAssetPath(path);

		width = w;
		height = h;

	}


	void EngineBaseNode::render(SDL_Renderer* r){
		if (nodeType == NodeType::SPRITE){
			engineTexture->render(position.x_, position.y_, r, m_gSpriteClips);
		}
		else if (nodeType == NodeType::LABEL){
			engineTexture->render(position.x_, position.y_, r);
		}
	}



	bool EngineBaseNode::load( SDL_Renderer * r){

		engineTexture = new ResourceTexture();
		
		if (nodeType == NodeType::SPRITE){
			if (!engineTexture->loadFromFile(m_assetPath, r))
				DEBUG_MSG("Faild to load sprite");

			else{
				DEBUG_MSG("Loaded sprite");

				for (int i = 0; i < 2; i++){
					m_gSpriteClips[i].x = 0;
					m_gSpriteClips[i].y = 0;
					m_gSpriteClips[i].w = width;
					m_gSpriteClips[i].h = height;
				}

				objectBoundingBox.x = position.x_;
				objectBoundingBox.y = position.y_;
				objectBoundingBox.w = width;
				objectBoundingBox.h = height;

			}
			return true;
		}
		else if (nodeType == NodeType::LABEL){


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
	}
}