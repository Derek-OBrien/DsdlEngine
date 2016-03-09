
#include "Sprite.h"

namespace DsdlEngine{

	Sprite::Sprite(){
		setEngineNodeType(NodeType::SPRITE);
	}

	Sprite::~Sprite() { destroy(); }

	void Sprite::create(int w, int h, std::string path){
		setAssetPath(path);

		m_size.x_ = w;
		m_size.y_ = h;
	}


	void Sprite::create(int w, int h, std::string path, int nf){
		setAssetPath(path);

		m_size.x_ = w;
		m_size.y_ = h;
		m_numFrames = nf;
	}


	void Sprite::createWithPhysics(b2World* world, Vec2 spriteSize, Vec2 position, std::string path, int numFrames, float den, float fri, bool FixedRotation) {
		setAssetPath(path);

		m_size.x_ = spriteSize.x_;
		m_size.y_ = spriteSize.y_;
		
		m_position.x_ = position.x_;
		m_position.y_ = position.y_;

		setPosition(position);

		m_numFrames = numFrames;

		m_CollisionShape = new CollisionShape();

		m_CollisionShape->init(world, position, spriteSize, den, fri, FixedRotation);
	}

	void Sprite::destroy(){
		EngineBaseNode::destroy();
	}

}