#ifndef _LAYER_
#define _LAYER_

#include "EngineBaseNode.h"
#include "ResourceTexture.h"

/*
	Base Layer Class
	author: Derek O Brien
	Description: Layer base class for all layers in game.
*/

namespace DsdlEngine {
	class Layer {
	public:
		//Add Gui Class As friend class
		friend class Gui;

		Layer();
		virtual ~Layer();

		void destroy();

		//Load all engine nodes added to the layer
		void loadNodes(SDL_Renderer* r);

		//Draw all engine nodes added to the layer
		void drawNodes(SDL_Renderer* r);

		//Add node to layer 
		void addNodeToLayer(EngineBaseNode* node);

		//Remove node form layer
		void removeNodeFromLayer(EngineBaseNode* node);
	
		//Vector to hold layer nodes
		std::vector<EngineBaseNode*> layerNodes;
	private:

	};
}
#endif //!_LAYER_