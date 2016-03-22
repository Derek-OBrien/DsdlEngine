#pragma once
#include "../../dsdl-engine/DsdlEngine.h"

USING_NS_DSDL;

// Define a ball speed in pixels per second
const float BALL_SPEED = 550;

class Ball : public Sprite {
public:

	Ball() {};
	~Ball() {};


	void create();

	void setDirection(float dirx, float diry);

	void update(float dt);

	float m_dirx, m_diry, ballPosX, ballPosY;
	

	Sprite* m_ball;

private:
};