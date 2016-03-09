#pragma once
#include "../../dsdl-engine/DsdlEngine.h"
#include "GameDefines.h"

USING_NS_DSDL;

class Character : public DsdlEngine::Sprite{

public:
	Character();
	~Character();


	void init(b2World* world);
	void update(InputManager& inputManager);

	void jump();
	void slide();
	Sprite* m_sprite;


	b2Body* m_body;

	InputManager inputManager;

	int getPlayerState() { return currentState; };	//Get current palyer state
	void setPlayerState(EPlayerState state) { currentState = (EPlayerState)state; };	//Set player state

private:
	Vec2 m_position;
	Vec2 m_size;

	EPlayerState currentState;

};