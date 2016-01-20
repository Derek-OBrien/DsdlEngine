
#include "EngineBaseNode.h"

namespace DsdlEngine{


	EngineBaseNode::EngineBaseNode(){}

	EngineBaseNode::~EngineBaseNode(){}

	void EngineBaseNode::render(SDL_Renderer* r){

		engineTexture->render(position.x_, position.y_, r);
	}
}