#pragma once
#include "../../dsdl-engine/DsdlEngine.h"
USING_NS_DSDL;

#include "GameDefines.h"

class Brick : public Sprite{
public:
	int type;
	bool state;

	Sprite* m_brickSprite;
};

class Board : public Sprite {
public:
	Board(Layer* layer) { m_layer = layer; };
	~Board() {};

	void create();
	void update();


	void createLevel();
	float brickoffsetx, brickoffsety;

	// Define the two-dimensional array of bricks
	Sprite* bricks[BOARD_WIDTH][BOARD_HEIGHT];

	Layer* m_layer;
	Sprite* bg;
	Sprite* m_sideLeft;
	Sprite* m_sideRight;

};