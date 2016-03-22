#include "Paddle.h"


void Paddle::create() {

	m_paddle = new Sprite();
	m_paddle->create(
		Vec2(128, 32),
		Vec2(0, 560),
		"Breakout/paddle.png",
		1);

}


void Paddle::update(float dt) {

}
