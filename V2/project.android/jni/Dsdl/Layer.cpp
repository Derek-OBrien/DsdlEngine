#include "Layer.h"

namespace DsdlEngine{



	Layer::Layer(){}

	Layer ::~Layer(){}


	ResourceTexture* Layer::create(std::string texturePath, SDL_Renderer* r){

		if (!m_LayerTexture.loadFromFile(texturePath, r)){
			DEBUG_MSG("Faild to load sprite");
		
		}
		else{
			DEBUG_MSG("Loaded sprite");

		}

		return &m_LayerTexture;
	}


	void Layer::destroy(){

	}

	/*void Layer::render(SDL_Renderer* r){

		m_LayerTexture.render(0, 0, r);
	}*/
}