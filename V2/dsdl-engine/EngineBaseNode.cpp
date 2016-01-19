
#include "EngineBaseNode.h"

namespace DsdlEngine{


	EngineBaseNode::EngineBaseNode(){}

	EngineBaseNode::~EngineBaseNode(){}

	void EngineBaseNode::render(SDL_Renderer* r){

		engineTexture->render(m_posX, m_posY, r);
	}
}