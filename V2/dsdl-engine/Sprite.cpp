
#include "Sprite.h"

namespace DsdlEngine{

	Sprite::Sprite(){
		setEngineNodeType(NodeType::SPRITE);
	}

	Sprite::~Sprite() { destroy(); }

	void Sprite::create(int w, int h, std::string path){
		setAssetPath(path);

		size.w_ = w;
		size.h_ = h;
	}


	void Sprite::create(int w, int h, std::string path, int nf){
		setAssetPath(path);

		size.w_ = w;
		size.h_ = h;
		m_numFrames = nf;
	}

	void Sprite::destroy(){
		EngineBaseNode::destroy();
	}

}