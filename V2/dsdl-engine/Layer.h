#ifndef _LAYER_
#define _LAYER_

#include "EngineBaseNode.h"

namespace DsdlEngine{

	class Layer : public EngineBaseNode
	{
	public:
		Layer ();
		~Layer ();


		void render(SDL_Renderer* r) override;


	private:

	};

	Layer ::Layer (){}

	Layer ::~Layer (){}
}

#endif