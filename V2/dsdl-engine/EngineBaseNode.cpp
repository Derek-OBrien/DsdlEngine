
#include "EngineBaseNode.h"
#include "FileIO.h"



namespace DsdlEngine {

	//Constructor
	EngineBaseNode::EngineBaseNode() {

		m_engineTexture = NULL;
		setEngineNodeType(NodeType::BASENODE);
		m_frame = 0;
		m_numFrames = 1;
		m_opacity = 255;
		m_objectBoundingBox = new SDL_Rect();

		updateTextureInfo = false;
	}

	//Deconstructor
	EngineBaseNode::~EngineBaseNode() {
		destroy();
	}



	//Render Node by type
	void EngineBaseNode::render(SDL_Renderer* r) {
		if (nodeType == NodeType::SPRITE) {
			renderAnimation(r);
		}
		else if (nodeType == NodeType::LABEL) {
			m_engineTexture->render(m_position, m_size, r);
		}
		else if (nodeType == NodeType::BUTTON) {
			m_engineTexture->render(m_position, m_size, r);
		}
		else if (nodeType == NodeType::PARTICLE) {

		}

	}


	//Render Node as Animation
	void EngineBaseNode::renderAnimation(SDL_Renderer* r) {
		m_currentFrame = &m_gSpriteClips[m_frame / m_numFrames];
		m_engineTexture->setAlpha(m_opacity);

		//Draw Bounding Box
		SDL_SetRenderDrawColor(r, 0, 255, 255, 255);
		SDL_RenderDrawRect(r, m_objectBoundingBox);

		//render texture
		m_engineTexture->render(m_position, m_size, r, m_currentFrame);
		++m_frame;

		if (m_frame / m_numFrames >= m_numFrames) {
			m_frame = 0;
		}
	}


	//Load Node as engine texture
	bool EngineBaseNode::load(SDL_Renderer * r) {

		m_engineTexture = new ResourceTexture();
		m_objectBoundingBox = new SDL_Rect();

		if (nodeType == NodeType::SPRITE || nodeType == NodeType::BUTTON) {

			if (!m_engineTexture->loadFromFile(m_assetPath, r))
				SDL_Log("Faild to load sprite");

			else {

				int temp = 0;

				for (int i = 0; i < m_numFrames; i++) {
					m_gSpriteClips[i].x = temp;
					m_gSpriteClips[i].y = 0;
					m_gSpriteClips[i].w = m_size.x_;
					m_gSpriteClips[i].h = m_size.y_;

					temp += m_size.x_;
				}
					m_objectBoundingBox->x = m_position.x_;
					m_objectBoundingBox->y = m_position.y_;
					m_objectBoundingBox->w = m_size.x_;
					m_objectBoundingBox->h = m_size.y_;
				
			}
			return true;
		}
		else if (nodeType == NodeType::LABEL) {


			if (!TTF_WasInit()) {
				TTF_Init();
			}

			std::string temp;

			temp = FileIO::getInstance()->getWritablePath() + m_assetPath;

			//Check if font in chache
			auto it = m_FontMap.find(temp);

			// if not load and create texture
			if (it == m_FontMap.end()) {

				//open font
				m_font = TTF_OpenFont(temp.c_str(), m_textSize);
				if (m_font == NULL) {
					DEBUG_MSG("TTF_OpenFont Error : " + std::string(TTF_GetError()));
				}

				m_engineTexture->loadTTF(m_labelText, m_textColor, m_font, r);

				m_FontMap[temp] = m_font;
			}
			else {//create texture
				m_font = it->second;
				m_engineTexture->loadTTF(m_labelText, m_textColor, m_font, r);
			}

			return true;
		}
		else
			return false;
	}

	void EngineBaseNode::setBoundingBox(Vec2 pos, Vec2 size) {
		m_objectBoundingBox = new SDL_Rect();
		m_objectBoundingBox->x = pos.x_; 
		m_objectBoundingBox->y = pos.y_; 
		m_objectBoundingBox->w = size.x_; 
		m_objectBoundingBox->h = size.y_; 
	}

	void EngineBaseNode::updateLabelText(std::string text) {
		m_labelText = text;
	}


	void EngineBaseNode::setOpacity(int op) {
		m_opacity = op;
	}

	void EngineBaseNode::destroy() {
		m_engineTexture->destroy();
		m_objectBoundingBox = nullptr;
		m_size = Vec2(0, 0);
	}

	void EngineBaseNode::cleanup() {
		m_engineTexture->destroy();
	}


	void EngineBaseNode::renderCollisionShape(SDL_Renderer* r, CollisionShape* shape) {

		SDL_Rect collisionbox;
		collisionbox.x = shape->getBody()->GetPosition().x;
		collisionbox.y = shape->getBody()->GetPosition().y;
		collisionbox.w = shape->getDimensions().x_;
		collisionbox.h = shape->getDimensions().y_;

		SDL_SetRenderDrawColor(r, 0, 255, 0, 255);
		SDL_RenderDrawRect(r, &collisionbox);
	}

}