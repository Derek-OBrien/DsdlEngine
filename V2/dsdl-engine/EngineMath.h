#ifndef _ENGINEMATH_
#define _ENGINEMATH_
#include "Window.h"

namespace DsdlEngine{

	class Vec2{

		friend class Window;

	public:
		
		//Position ints
		int x_;
		int y_;

		//Defaults to position of (0 , 0)
		Vec2();
		
		//Set position to values passed in (x , y)
		Vec2(int x, int y);
		
		Vec2(const Vec2& v);
		
		~Vec2();

		
		static const Vec2 ZERO;
		static const Vec2 TOP;
		static const Vec2 BOTTOM;
		static const Vec2 RIGHT;

		static const Vec2 MIDTOP;

	};


	class Size{
	public:
		int w_;
		int h_;

		Size();
		Size(int w, int h);
		Size(const Size& s);

		~Size();
	};


}
#endif