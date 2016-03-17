
#include "Sprite.h"

namespace DsdlEngine{

	Sprite::Sprite(){
		setEngineNodeType(NodeType::SPRITE);
	}

	Sprite::~Sprite() { destroy(); }

	void Sprite::create(Vec2 spriteSize, Vec2 position, std::string path){
		setAssetPath(path);

		m_size.x_ = spriteSize.x_;
		m_size.y_ = spriteSize.y_;

		m_position.x_ = position.x_;
		m_position.y_ = position.y_;

		setBoundingBox(position, spriteSize);
		setPosition(position);
	}


	void Sprite::create(Vec2 spriteSize, Vec2 position, std::string path, int nf){
		setAssetPath(path);

		m_size.x_ = spriteSize.x_;
		m_size.y_ = spriteSize.y_;

		m_position.x_ = position.x_;
		m_position.y_ = position.y_;
		setPosition(position);


		setBoundingBox(position, spriteSize);
		m_numFrames = nf;
	}


	void Sprite::createWithPhysics(b2World* world, Vec2 spriteSize, Vec2 position, std::string path, int numFrames, float den, float fri, bool FixedRotation) {
		setAssetPath(path);

		m_size.x_ = spriteSize.x_;
		m_size.y_ = spriteSize.y_;
		
		m_position.x_ = position.x_;
		m_position.y_ = position.y_;

		setPosition(position);


		setBoundingBox(position, spriteSize);
		m_numFrames = numFrames;

		m_CollisionShape = new CollisionShape();

		m_CollisionShape->init(world, position, spriteSize, den, fri, FixedRotation);
	}

	void Sprite::destroy(){
		EngineBaseNode::destroy();
	}



	void Sprite::updateTexure(Vec2 spriteSize, Vec2 position, std::string path, int numFrames) {
	
		setUpdateTextureTrue(true);

		setAssetPath(path);

		m_size.x_ = spriteSize.x_;
		m_size.y_ = spriteSize.y_;

		m_position.x_ = position.x_;
		m_position.y_ = position.y_;
		setPosition(position);


		setBoundingBox(position, spriteSize);
		m_numFrames = numFrames;

	}
}