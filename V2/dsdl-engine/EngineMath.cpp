#include "EngineMath.h"
#include "XmlLocalStorage.h"
/**
*	@author Derek O Brien
*/

namespace DsdlEngine{


	//Defaults to position of (0 , 0)
	Vec2::Vec2() : x_(0), y_(0){
	}

	//Set position to values passed in (x , y)
	Vec2::Vec2(float x, float y) : x_(x), y_(y){
	}

	Vec2::Vec2(const Vec2& v){
		this->x_ = v.x_;
		this->y_ = v.y_;
	}

	
	Vec2::~Vec2(){}

	/*
		SDL Window Coordintes 
		origin is top left corner
	*/
	const Vec2 Vec2::ZERO(0, 0);
}

namespace DsdlEngine{


	Size::Size() : w_(0), h_(0){}
	
	Size::Size(float w, float h) : w_(w), h_(h){}

	Size::Size(const Size& s){
		this->h_ = s.h_;
		this->w_ = s.w_;
	}

	Size::~Size(){}

}