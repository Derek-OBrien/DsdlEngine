
#include "EngineBaseNode.h"




namespace DsdlEngine{


	EngineBaseNode::EngineBaseNode(){
		setEngineNodeType(NodeType::BASENODE);
		m_frame = 0;
		m_numFrames = 1;
	}

	EngineBaseNode::~EngineBaseNode(){
		destroy();
	}



	/*void EngineBaseNode::create(int w, int h, std::string path){
		setAssetPath(path);

		width = w;
		height = h;

	}*/


	void EngineBaseNode::render(SDL_Renderer* r){
		if (nodeType == NodeType::SPRITE){
			if (m_numFrames > 1){
				spriteAnimation(r);
			}
			else{
				engineTexture->render(position.x_, position.y_, r, m_currentFrame);
			}

			//SDL_SetRenderDrawColor(r, 0xff, 0x00, 0x00, 0xFF);
			SDL_RenderDrawRect(r, &objectBoundingBox);
		}
		else if (nodeType == NodeType::LABEL || nodeType == NodeType::BUTTON){
			engineTexture->render(position.x_, position.y_, r);
		}
	}


	void EngineBaseNode::spriteAnimation(SDL_Renderer* r){
		m_currentFrame = &m_gSpriteClips[m_frame / m_numFrames];
		engineTexture->render(position.x_, position.y_, r, m_currentFrame);
		++m_frame;

		if (m_frame / m_numFrames >= m_numFrames){
			m_frame = 0;
		}
	}



	bool EngineBaseNode::load( SDL_Renderer * r){

		engineTexture = new ResourceTexture();
		
		if (nodeType == NodeType::SPRITE){
			
			if (!engineTexture->loadFromFile(m_assetPath, r))
				SDL_Log("Faild to load sprite");

			else{
				SDL_Log("Loaded sprite");

				int temp = 0;

				for (int i = 0; i < m_numFrames; i++){
					m_gSpriteClips[i].x = temp;
					m_gSpriteClips[i].y = 0;
					m_gSpriteClips[i].w = width;
					m_gSpriteClips[i].h = height;

					temp += width;
				}

				objectBoundingBox.x = position.x_;
				objectBoundingBox.y = position.y_;
				objectBoundingBox.w = width;
				objectBoundingBox.h = height;

			}
			return true;
		}
		else if (nodeType == NodeType::LABEL || nodeType == NodeType::BUTTON){


			if (!TTF_WasInit()){
				TTF_Init();
			}



			std::string temp;
#ifdef __WIN32__
			SDL_Log("Loading Assets For Windows Platform");
			temp = "../../assets/" + m_assetPath;
#endif

#ifdef __ANDROID__
			SDL_Log("Loading Assets for Android Platform");
			temp = m_assetPath;
#endif

			//Check if font in chache
			auto it = m_FontMap.find(temp);


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

			return true;
		}
		//else
		return false;
	}

	void EngineBaseNode::destroy(){
		engineTexture->destroy();
	}
}