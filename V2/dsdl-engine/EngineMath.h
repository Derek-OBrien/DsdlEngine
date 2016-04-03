#ifndef _ENGINEMATH_
#define _ENGINEMATH_

/**
*	@author Derek O Brien
*/
namespace DsdlEngine{
	/**
	*	Vec2 is a class for creating a 2 point position variable
	*/
	class Vec2{

	public:

		/**
		*	Constructor
		*	Defaults values to 0 , 0
		*/
		Vec2();
		
		/**
		*	Constructor
		*	Set values on creation.
		*	@param x as a float argument
		*	@param y as a float argument
		*/
		Vec2(float x, float y);
		
		/**
		*	Constructor.
		*	Create a Vec2 object with another Vec2
		*	@param v as a Vec2 argument
		*/
		Vec2(const Vec2& v);
		
		/**
		*	Deconstructor
		*/
		~Vec2();

		/**
		*	const postition set to origin
		*/
		static const Vec2 ZERO;

		float x_;	/**< float value for x position*/
		float y_;	/**< float value for y position*/


	};

	/**
	*	Size is a class for creating a 2 point size variable
	*/
	class Size{
	public:

		/**
		*	Constructor
		*	Defaults values to 0 , 0
		*/
		Size();

		/**
		*	Constructor
		*	Set values on creation.
		*	@param w as a float argument
		*	@param h as a float argument
		*/
		Size(float w, float h);


		/**
		*	Constructor.
		*	Create a Size object with another Size
		*	@param s as a Size argument
		*/
		Size(const Size& s);

		/**
		*	Deconstructor
		*/
		~Size();


		float w_;	/**< float value for width */
		float h_;	/**< float value for height */
	};


}
#endif