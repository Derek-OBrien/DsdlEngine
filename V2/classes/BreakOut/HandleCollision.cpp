#include "HandleCollision.h"


bool HandleCollision::Collides(Sprite* one, Sprite* two) {

	if (one->getPosition().x_ + one->getContentSize().x_ > two->getPosition().x_ 
		&& 
		one->getPosition().x_ < two->getPosition().x_ + two->getContentSize().x_
		&&
		one->getPosition().y_ + one->getContentSize().y_ >  two->getPosition().y_ 
		&&
		one->getContentSize().y_ < two->getPosition().y_ + two->getContentSize().y_) {
		return true;
	}
	return false;
}