
#include "EngineBaseNode.h"




namespace DsdlEngine{

	//Constructor
	EngineBaseNode::EngineBaseNode(){
		setEngineNodeType(NodeType::BASENODE);
		m_frame = 0;
		m_numFrames = 1;
	}

	//Deconstructor
	EngineBaseNode::~EngineBaseNode(){
		destroy();
	}



	//Render Node
	void EngineBaseNode::render(SDL_Renderer* r){
		if (nodeType == NodeType::SPRITE){
			if (m_numFrames > 1){
				renderAnimation(r);

				SDL_Log("################Engine Base node frames > 1################");
			}
			else{
				engineTexture->render(position.x_, position.y_, r, m_currentFrame);

				SDL_Log("################Engine base Node frames 1################");
			}

		//	SDL_SetRenderDrawColor(r, 0, 0, 255, 120);
		//	SDL_RenderDrawRect(r, &objectBoundingBox);
		}

		else if (nodeType == NodeType::LABEL){

		//	SDL_SetRenderDrawColor(r, 255, 0, 0, 120);
		//	SDL_RenderDrawRect(r, &labelBorder);
		
			engineTexture->render(position.x_, position.y_, r);

		}
		else if (nodeType == NodeType::BUTTON) {
		//	SDL_SetRenderDrawColor(r, 0, 255, 0, 120);
		//	SDL_RenderDrawRect(r, &labelBorder);
		//	SDL_FillRect(btnbg, &labelBorder, 255);

			engineTexture->render(position.x_, position.y_, r);

		}
	}


	//Render Node as Animation
	void EngineBaseNode::renderAnimation(SDL_Renderer* r){
		m_currentFrame = &m_gSpriteClips[m_frame / m_numFrames];
		engineTexture->render(position.x_, position.y_, r, m_currentFrame);
		++m_frame;

		if (m_frame / m_numFrames >= m_numFrames){
			m_frame = 0;
		}
	}


	//Load Node as engine texture
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
					m_gSpriteClips[i].w = size.w_;
					m_gSpriteClips[i].h = size.h_;

					temp += size.w_;
				}

				objectBoundingBox.x = position.x_;
				objectBoundingBox.y = position.y_;
				objectBoundingBox.w = size.w_;
				objectBoundingBox.h = size.h_;

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