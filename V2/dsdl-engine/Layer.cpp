#include "Layer.h"
#include "Sprite.h"

namespace DsdlEngine{



	Layer::Layer(){
	
	}

	Layer ::~Layer(){}


	Layer* Layer::create(){

		auto layer = new Layer();

		return layer;
	}


	void Layer::destroy(){

	}


	void Layer::loadNodes(SDL_Renderer* r) {
		for (size_t i = 0; i < layerNodes.size(); i++)
		{
			layerNodes.at(i)->load(r);
		}
	}

	void Layer::drawNodes(SDL_Renderer* r) {
		for (size_t i = 0; i < layerNodes.size(); i++)
		{
			layerNodes.at(i)->render(r);
		}
	}


	void Layer::addNodeToLayer(EngineBaseNode* node) {
		layerNodes.push_back(node);
	}

}