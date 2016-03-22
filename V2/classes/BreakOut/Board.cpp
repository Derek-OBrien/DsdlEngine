#include "Board.h"


void Board::create() {
	
	bg = new Sprite();
	m_sideLeft = new Sprite();
	m_sideRight = new Sprite();

	bg->create(Vec2(GAME_WIDTH, GAME_HEIGHT), Vec2(0, 0), "Breakout/black_bg.png", 1);
	m_sideLeft->create(Vec2(16, GAME_HEIGHT),Vec2(0, 0),"Breakout/side.png",1);
	m_sideRight->create(Vec2(16, GAME_HEIGHT), Vec2(GAME_WIDTH-16, 0), "Breakout/side.png", 1);

	brickoffsetx = 0;
	brickoffsety = 16;

	m_layer->addNodeToLayer(bg);
	m_layer->addNodeToLayer(m_sideLeft);
	m_layer->addNodeToLayer(m_sideRight);
}

void Board::update() {

}


void Board::createLevel() {
	for (int i = 0; i<BOARD_WIDTH; i++) {
		for (int j = 0; j<BOARD_HEIGHT; j++) {
			Brick* brick = new Brick();
			
			brick->state = true;
			brick->type = 1;

			brick->m_brickSprite = new Sprite();
			
			brick->m_brickSprite->create(Vec2(BOARD_BRWIDTH, BOARD_BRHEIGHT),Vec2(20, 20),"Breakout/bricks.png",1);

			brick->m_brickSprite->setPosition(Vec2(
				brickoffsetx + brick->m_brickSprite->getPosition().x_ + i * BOARD_BRWIDTH ,
				brickoffsety + brick->m_brickSprite->getPosition().y_ + j * BOARD_BRHEIGHT));

			bricks[i][j] = brick;
			
			m_layer->addNodeToLayer(brick->m_brickSprite);
		}
	}
}
