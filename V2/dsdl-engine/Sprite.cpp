#include "Sprite.h"

/*
	File: Sprite.h
	Author: Derek O Brien
	Description: Sprite file for creating in game sprites. Inherits from engine base node
*/
namespace DsdlEngine{

	//Constructor
	Sprite::Sprite(){
		setEngineNodeType(NodeType::SPRITE);
	}

	//DeConstructor
	Sprite::~Sprite() { 
		destroy(); 
	}


	//Create basic sprite with one frame
	void Sprite::create(Vec2 spriteSize, Vec2 position, std::string path){
		setAssetPath(path);

		m_size.x_ = spriteSize.x_;
		m_size.y_ = spriteSize.y_;

		m_position.x_ = position.x_;
		m_position.y_ = position.y_;
		setPosition(position);

		setBoundingBox(position, spriteSize);
	}


	//Create basic sprite with more than one frame
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

	//Create basic sprite with more than one frame and physics body attached
	void Sprite::createWithPhysics(b2World* world, Vec2 spriteSize, Vec2 position, std::string path, int numFrames, float den, float fri, bool FixedRotation) {
		setAssetPath(path);

		m_size.x_ = spriteSize.x_;
		m_size.y_ = spriteSize.y_;
		
		m_position.x_ = position.x_;
		m_position.y_ = position.y_;

		setPosition(position);

		setBoundingBox(position, spriteSize);
		m_numFrames = numFrames;

		//Create new collision shape
		m_CollisionShape = new CollisionShape();
		m_CollisionShape->init(world, position, spriteSize, den, fri, FixedRotation);
	}

	//Destroy Sprite
	void Sprite::destroy(){
		EngineBaseNode::destroy();
	}

	//Change sprite texture after sprite is loaded
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