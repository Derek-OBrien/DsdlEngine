#include "ScrollingBg.h"



ScrollingBg::ScrollingBg(){
	//Empty
}
ScrollingBg::~ScrollingBg(){
	//Empty
}


void ScrollingBg::create(std::string path) {

	scrollingImage = new Sprite();

	scrollingImage->create(Vec2(3840, 1080), Vec2::ZERO, path);
	pos = 0;
	
	bacgrounds.push_back(scrollingImage);
	scrollSpeed = 0;
}


void ScrollingBg::update(int speed) {
	
	scrollSpeed = speed;

	pos -= scrollSpeed;
	if (pos < -scrollingImage->getContentSize().x_ / 2){
		pos = 0;
	}
	scrollingImage->setPositionX(pos);

}



void ScrollingBg::destroy() {
	scrollingImage->destroy();
}