
#include "Sprite.h"

namespace DsdlEngine{

	Sprite::Sprite(){
		setEngineNodeType(NodeType::SPRITE);
	}

	Sprite::~Sprite() { destroy(); }

	void Sprite::create(int w, int h, std::string path){
		setAssetPath(path);

		size.x_ = w;
		size.y_ = h;
	}


	void Sprite::create(int w, int h, std::string path, int nf){
		setAssetPath(path);

		size.x_ = w;
		size.y_ = h;
		m_numFrames = nf;
	}


	void Sprite::createWithPhysics(Size spriteSize, std::string path, int numFrames) {
		setAssetPath(path);

		size.x_ = spriteSize.w_;
		size.y_ = spriteSize.h_;
		m_numFrames = numFrames;

	}

	void Sprite::destroy(){
		EngineBaseNode::destroy();
	}

}