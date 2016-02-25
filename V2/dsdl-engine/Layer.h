#ifndef _LAYER_
#define _LAYER_

#include "EngineBaseNode.h"
#include "ResourceTexture.h"

namespace DsdlEngine{
	class Layer : public EngineBaseNode
	{
	public:
		Layer ();
		virtual ~Layer ();

	
		void destroy();

		void loadNodes(SDL_Renderer* r);
		void drawNodes(SDL_Renderer* r);

		std::vector<EngineBaseNode*> layerNodes;

		void addNodeToLayer(EngineBaseNode* node);

		
	private:

		ResourceTexture m_LayerTexture;

	};
}
#endif