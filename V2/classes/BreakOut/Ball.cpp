
#include "Ball.h"

void Ball::create() {

	m_ball = new Sprite();
	m_ball->create(
		Vec2(24, 24),
		Vec2(24, 24),
		"Breakout/ball.png",
		1);

	setDirection(1, 1);

	ballPosX = m_ball->getPosition().x_;

	ballPosY = m_ball->getPosition().y_;
}

void Ball::setDirection(float dirx, float diry) {

	// Normalize the direction vector and multiply with BALL_SPEED
	float length = sqrt(dirx * dirx + diry * diry);
	this->m_dirx = BALL_SPEED * (dirx / length);
	this->m_diry = BALL_SPEED * (diry / length);
}


void Ball::update(float dt) {
	ballPosX += m_dirx * dt;
	ballPosY += m_diry * dt;

	m_ball->setPosition(Vec2(ballPosX, ballPosY));
}
