#include "EngineMath.h"

namespace DsdlEngine{

	

	//Defaults to position of (0 , 0)
	Vec2::Vec2() : x_(0), y_(0){
	}

	//Set position to values passed in (x , y)
	Vec2::Vec2(int x, int y) : x_(x), y_(y){
	}

	Vec2::Vec2(const Vec2& v){
		this->x_ = v.x_;
		this->y_ = v.y_;
	}





	Vec2::~Vec2(){
	}


	const Vec2 Vec2::ZERO(0, 0);
	const Vec2 Vec2::BOTTOM(1, 1);
}