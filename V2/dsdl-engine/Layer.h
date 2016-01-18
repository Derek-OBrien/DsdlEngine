#ifndef _LAYER_
#define _LAYER_

#include "EngineBaseNode.h"
#include "ResourceTexture.h"

namespace DsdlEngine{

	class Layer : public EngineBaseNode
	{
	public:
		Layer ();
		~Layer ();


		ResourceTexture* create(std::string texturePath, SDL_Renderer* r);

		void render(SDL_Renderer* r) override;


	private:

		ResourceTexture m_LayerTexture;

	};

}

#endif