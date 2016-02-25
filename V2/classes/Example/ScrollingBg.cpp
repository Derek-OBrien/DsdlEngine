#include "ScrollingBg.h"



ScrollingBg::ScrollingBg(){}
ScrollingBg::~ScrollingBg(){}


void ScrollingBg::create(std::string path) {

	bg = new Sprite();

	//bg->create(3840, 1080, "DemoGame/backgrounds/bg_city.png");
	bg->create(3840, 1080, path);
	bg->setPosition(Vec2::ZERO);

	pos = 0;
}


void ScrollingBg::update() {

	pos -= 3;
	if (pos <= -1920){//-bg->getContentSize().w_) {
		pos = 0;
	}
	bg->setPositionX(pos);

}



void ScrollingBg::destroy() {
	bg->destroy();
}