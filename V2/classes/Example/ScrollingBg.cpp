#include "ScrollingBg.h"



ScrollingBg::ScrollingBg(){
	//bg = new Sprite();
}
ScrollingBg::~ScrollingBg(){}


void ScrollingBg::create(std::string path) {

	scrollingImage = new Sprite();

	scrollingImage->create(Vec2(3840, 1080), Vec2::ZERO, path);
	//scrollingImage->setPosition(Vec2::ZERO);

	pos = 0;
	
	bacgrounds.push_back(scrollingImage);
}


void ScrollingBg::update() {

	pos -= 3;
	if (pos < -scrollingImage->getContentSize().x_){
		pos = 0;
	}
	scrollingImage->setPositionX(pos);

}



void ScrollingBg::destroy() {
	scrollingImage->destroy();
}