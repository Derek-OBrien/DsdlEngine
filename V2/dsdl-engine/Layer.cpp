#include "Layer.h"
#include "Sprite.h"

namespace DsdlEngine{



	Layer::Layer(){
	
	}

	Layer ::~Layer() { destroy(); }



	void Layer::destroy(){

		for (size_t i = 0; i < layerNodes.size(); i++) {
			layerNodes[i]->destroy();
			delete layerNodes[i];
		}
		layerNodes.resize(0);
		for (size_t i = 0; i < box2dNodes.size(); i++) {
			box2dNodes[i]->Dump();
		}
		box2dNodes.resize(0);
		
		m_LayerTexture.destroy();

	}

	void Layer::addNodeToLayer(EngineBaseNode* node) {
		layerNodes.push_back(node);
	}

	void Layer::loadNodes(SDL_Renderer* r) {
		for (size_t i = 0; i < layerNodes.size(); i++){
			layerNodes.at(i)->load(r);
		}
	}

	void Layer::drawNodes(SDL_Renderer* r) {
		for (size_t i = 0; i < layerNodes.size(); i++){
			layerNodes.at(i)->render(r);

			SDL_Log("################Layer::drawNodes################");
		}
	}


	void Layer::addBox2dNodes(b2Body* body) {
		box2dNodes.push_back(body);
	}


	void Layer::drawBox2dNodes(SDL_Renderer* r) {
		for (size_t i = 0; i < box2dNodes.size(); i++) {
			box2dRect.x = box2dNodes.at(i)->GetPosition().x;
			box2dRect.y = box2dNodes.at(i)->GetPosition().y;
			box2dRect.h = 20;
			box2dRect.w = 1920;

			SDL_SetRenderDrawColor(r, 0, 0, 255, 120);
			SDL_RenderDrawRect(r, &box2dRect);
		}
	}

}