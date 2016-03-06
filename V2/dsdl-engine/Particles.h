#ifndef __Particles__
#define __Particles__
#include "DsdlEngine.h"

namespace DsdlEngine {

#define MAL_PARTICLE_LIFE 500


	class Particles : public EngineBaseNode{
	public:
		Particles(int x, int y);
		~Particles();


		bool isDead(Particles *p);

		static inline float torad(float angle){
			return (angle * M_PI) / 180;
		}

		
	private:
		
		int life;
		float mPosX, mPosY, xvel, yvel, angle, size;
		Uint32 endtime;

	};
}
#endif // !__Particles__
