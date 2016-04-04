#pragma once


#include "../../dsdl-engine/DsdlEngine.h"
USING_NS_DSDL;


class ScrollingBg : public Layer
{
public:
	ScrollingBg();
	~ScrollingBg();

	void create(std::string path);
	void update(int speed);
	void destroy();

	Sprite* scrollingImage;
	int pos;

	std::vector<Sprite*> bacgrounds;

	int scrollSpeed;

	int getScrollSpeed() { return scrollSpeed; }
private:

};

