
#include "Sprite.h"

namespace DsdlEngine{

	Sprite::Sprite(){
		setEngineNodeType(NodeType::SPRITE);
	}

	Sprite::~Sprite(){}

	void Sprite::create(int w, int h, std::string path){
		setAssetPath(path);

		width = w;
		height = h;
	}

}