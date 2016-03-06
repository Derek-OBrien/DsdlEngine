
#include "EngineBaseNode.h"




namespace DsdlEngine {

	//Constructor
	EngineBaseNode::EngineBaseNode() {

		engineTexture = NULL;
		setEngineNodeType(NodeType::BASENODE);
		m_frame = 0;
		m_numFrames = 1;
		opacity = 255;

	}

	//Deconstructor
	EngineBaseNode::~EngineBaseNode() {
		destroy();
	}



	//Render Node
	void EngineBaseNode::render(SDL_Renderer* r) {
		if (nodeType == NodeType::SPRITE) {
			if (m_numFrames > 1) {
				renderAnimation(r);
			}
			else {
				engineTexture->setAlpha(opacity);
				engineTexture->render(position, size, r, m_currentFrame);
			}
		}

		else if (nodeType == NodeType::LABEL) {

			engineTexture->render(position, size, r);
		}
		else if (nodeType == NodeType::BUTTON) {

			engineTexture->render(position, size, r);
		}
	}


	//Render Node as Animation
	void EngineBaseNode::renderAnimation(SDL_Renderer* r) {
		m_currentFrame = &m_gSpriteClips[m_frame / m_numFrames];
		engineTexture->setAlpha(opacity);
		engineTexture->render(position, size, r, m_currentFrame);
		++m_frame;

		if (m_frame / m_numFrames >= m_numFrames) {
			m_frame = 0;
		}
	}


	//Load Node as engine texture
	bool EngineBaseNode::load(SDL_Renderer * r) {

		engineTexture = new ResourceTexture();

		if (nodeType == NodeType::SPRITE) {

			if (!engineTexture->loadFromFile(m_assetPath, r))
				SDL_Log("Faild to load sprite");

			else {
				SDL_Log("Loaded sprite");

				int temp = 0;

				for (int i = 0; i < m_numFrames; i++) {
					m_gSpriteClips[i].x = temp;
					m_gSpriteClips[i].y = 0;
					m_gSpriteClips[i].w = size.x_;
					m_gSpriteClips[i].h = size.y_;

					temp += size.x_;
				}

				objectBoundingBox.x = position.x_;
				objectBoundingBox.y = position.y_;
				objectBoundingBox.w = size.x_;
				objectBoundingBox.h = size.y_;

			}
			return true;
		}
		else if (nodeType == NodeType::LABEL || nodeType == NodeType::BUTTON) {


			if (!TTF_WasInit()) {
				TTF_Init();
			}

			std::string temp;
#ifdef __WIN32__
			//	SDL_Log("Loading Assets For Windows Platform");
			temp = "../../assets/" + m_assetPath;
#endif

#ifdef __ANDROID__
			//	SDL_Log("Loading Assets for Android Platform");
			temp = m_assetPath;
#endif

			//Check if font in chache
			auto it = m_FontMap.find(temp);


			// if not load and create texture
			if (it == m_FontMap.end()) {

				//open font
				font = TTF_OpenFont(temp.c_str(), textSize);
				if (font == NULL) {
					DEBUG_MSG("TTF_OpenFont Error : " + std::string(TTF_GetError()));
				}

				engineTexture->loadTTF(labelText, textColor, font, r);

				m_FontMap[temp] = font;
			}
			else {//create texture
				font = it->second;
				engineTexture->loadTTF(labelText, textColor, font, r);

			}

			return true;
		}
		else
			return false;
	}


	void EngineBaseNode::setOpacity(int op) {
		opacity = op;
	}

	void EngineBaseNode::destroy() {
		engineTexture->destroy();
	}
}