#ifndef _ENGINEMATH_
#define _ENGINEMATH_

namespace DsdlEngine{


	class Vec2{
	public:
		
		int x_;
		int y_;

		Vec2();
		
		Vec2(int x, int y);
		
		
		
		~Vec2();
	};


	typedef Vec2 Point;

}
#endif