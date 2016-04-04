#include "Layer.h"
#include "Sprite.h"

/*
	Base Layer Class
	author: Derek O Brien
	Description: Layer base class for all layers in game.
*/

namespace DsdlEngine {

	//Constructor
	Layer::Layer() {
		//Emptty
		layerNodes.reserve(20);
	}

	//Deconstructor
	Layer ::~Layer() { 
		destroy(); 
	}

	//Destroy layer nodes and cleanup
	void Layer::destroy() {
 		for (size_t i = 0; i < layerNodes.size(); i++) {
			layerNodes.erase(std::remove(layerNodes.begin(), layerNodes.end(), layerNodes[i]), layerNodes.end());

			layerNodes[i]->destroy();

			//layerNodes.shrink_to_fit();
			//delete(layerNodes[i]);
		}
		layerNodes.clear();
	}


	//Add Engine node to layer for loading and rendering
	void Layer::addNodeToLayer(EngineBaseNode* node) {
		layerNodes.push_back(node);
	}


	//Remove Node from sceen Vector
	void Layer::removeNodeFromLayer(EngineBaseNode* node) {
		layerNodes.erase(std::remove(layerNodes.begin(), layerNodes.end(), node), layerNodes.end());
		node->destroy();
	}

	//Load all nodes added to layer
	void Layer::loadNodes(SDL_Renderer* r) {
		for (size_t i = 0; i < layerNodes.size(); i++) {
			layerNodes.at(i)->load(r);
		}
	}

	//Render all nodes added to layer
	void Layer::drawNodes(SDL_Renderer* r) {
		for (size_t i = 0; i < layerNodes.size(); i++) {

			if (layerNodes.at(i)->getNodeType() == NodeType::SPRITE) {

				//Reload texture if the texture has been changed
				if (layerNodes.at(i)->isTextureChanged() == true) {
					layerNodes.at(i)->cleanup();
					layerNodes.at(i)->load(r);
					layerNodes.at(i)->setUpdateTextureTrue(false);
				}
				layerNodes.at(i)->render(r);
			}

			/*
			Reload labels for update each tick for changes to take effect
			old label destroyed first to realease its memory so no extra memory been taking up
			*/
			if (layerNodes.at(i)->getNodeType() == NodeType::LABEL) {
				layerNodes.at(i)->cleanup();
				layerNodes.at(i)->load(r);
				layerNodes.at(i)->render(r);
			}
		}
	}

}