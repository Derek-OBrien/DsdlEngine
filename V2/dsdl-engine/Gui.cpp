
#include "Gui.h"
#include "Button.h"
#include "Window.h"

namespace DsdlEngine{


	DsdlGui::DsdlGui() {}

	DsdlGui::~DsdlGui() { destroy(); }

	void DsdlGui::addButton(ButtonType type, Vec2 pos, Size size, const char* path, SDL_Color color, SDL_Color bgColor , const char* text) {

		m_btn = new Button();

		if (type == ButtonType::LABEL_BTN) {
			m_btn->createTextButton(pos, size, text, path, color, bgColor);
			m_btn->setPosition(pos);
		}

		if (type == ButtonType::SPRITE_BTN) {
			m_btn->createSpriteButton(size.w_, size.h_, path);
			m_btn->setPosition(pos);
		}

		//Add button to gui elements array
		layerNodes.push_back(m_btn);
	}

	void DsdlGui::addLabel() {

	}

	void DsdlGui::setGUIPos() {
		
	}

	void DsdlGui::onSDLEvent(SDL_Event& e) {

	}

	void DsdlGui::destroy() {
	
	}
}


