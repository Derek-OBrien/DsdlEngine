#ifndef _LAYER_
#define _LAYER_

#include "EngineBaseNode.h"
#include "ResourceTexture.h"

/**
*	@author Derek O Brien
*/

namespace DsdlEngine {
	/***
	*	Base layer class for the engine
	*/
	class Layer {
	public:
		//Add Gui Class As friend class
		friend class Gui;

		/**
		*	Constructor
		*/
		Layer();

		/**
		*	Deconstructor
		*/
		virtual ~Layer();

		/**
		*	Destroy the layer and all its contents
		*/
		void destroy();

		/**
		*	Load all nodes in the layer
		*	@parma r, SDL_Renderer to be used when loading
		*/
		void loadNodes(SDL_Renderer* r);

		/**
		*	Draw all nodes in the layer
		*	@parma r, SDL_Renderer to be used when rendering
		*/
		void drawNodes(SDL_Renderer* r);

		/**
		*	Add A node to the layer. 
		*	@parma node, EngineBaseNode to add to the Layer
		*/
		void addNodeToLayer(EngineBaseNode* node);

		/**
		*	Remove a node from the layer.
		*	@parma node, EngineBaseNode to be removed from the layer
		*/
		void removeNodeFromLayer(EngineBaseNode* node);
	
		std::vector<EngineBaseNode*> layerNodes;		/**< vector to hold layer nodes*/
	private:

	};
}
#endif //!_LAYER_