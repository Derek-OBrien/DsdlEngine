#ifndef __COLLISIONSHAPE__
#define __COLLISIONSHAPE__

#include "EngineDefines.h"
/**
*	@author Derek O Brien 
*/
namespace DsdlEngine {
	/**
	*	CollisionShape class is for creating a Box2D collision shape around the Sprite node.
	*/
	class CollisionShape
	{
	public:
		/**
		*	Constructor.
		*/
		CollisionShape();

		/**
		*	Deconstructor.
		*/
		~CollisionShape();

		/**
		*	Initialize shape with arguments passed in.	
		*	@param position as a Vec2 position argument.
		*	@param dimensions as a Vec2 size arguent.
		*	@param density as a float argument.
		*	@param friction as a float argument.
		*	@param fixedRotation as a bool argument.
		*/
		void init(b2World* world,
			Vec2 position,
			Vec2 dimensions,
			float density,
			float friction,
			bool fixedRotation);

		/**
		*	destroy shape in the Box2D world.
		*	@param world as a b2World pointer argument.
		*/
		void destroy(b2World* world);

		/**
		*	getBody, get the body for the shape.
		*	@return b2Body pointer.
		*/
		b2Body* getBody() const { return m_body; }

		/**
		*	getFixture, get the fixture for index passed in.
		*	@param index as a int argument.
		*	@return b2Fixture pointer.
		*/
		b2Fixture* getFixture(int index) const { return m_fixtures[index]; }

		/**
		*	getDimensions, get the dimensions of the shape.
		*	@return Vec2 dimesions of the shape.
		*/
		const Vec2 getDimensions() const { return m_dimensions; }

	protected:
		/**
		*	b2Body variabel.
		*/
		b2Body* m_body = nullptr;

		/**
		*	Array of fixtures for the shape.
		*/
		b2Fixture* m_fixtures[1];

		/**
		*	Vec2 dimensions variable.
		*/
		Vec2 m_dimensions;
	};

}
#endif // !__COLLISIONSHAPE__
