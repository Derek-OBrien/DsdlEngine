#pragma once


#include "../../dsdl-engine/DsdlEngine.h"
USING_NS_DSDL;


class ScrollingBg : public Layer
{
public:
	ScrollingBg();
	~ScrollingBg();

	void create(std::string path);
	void update();
	void destroy();

	Sprite* bg;
	int pos;
private:

};

