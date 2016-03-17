#pragma once
#include "../../dsdl-engine/DsdlEngine.h"
#include "GameDefines.h"

USING_NS_DSDL;

class Character : public DsdlEngine::Sprite{

public:
	Character();
	~Character();


	void init(b2World* world);
	void update(InputManager& inputManager, b2World* world);

	void jump();
	void fall();
	void slide();
	void stopSlide();

	Sprite* m_sprite;


	b2Body* m_body;

	InputManager inputManager;

	int getPlayerState() { return currentState; };	//Get current palyer state
	void setPlayerState(EPlayerState state) { currentState = (EPlayerState)state; };	//Set player state

private:
	
	EPlayerState currentState;
	std::string player;
};