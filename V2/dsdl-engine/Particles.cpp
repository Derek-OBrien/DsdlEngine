
#include "Particles.h"

namespace DsdlEngine {

	Particles::Particles(int x, int y) {
		//Set offsets
		mPosX = x - 5 + (rand() % 25);
		mPosY = y - 5 + (rand() % 25);

		//Initialize animation
		m_frame = rand() % 5;

	}

	Particles::~Particles() {}


	bool Particles::isDead(Particles *p)
	{
		if ((p->life < 0) || (p->size < 1))
			return true;
		return false;
	}


}