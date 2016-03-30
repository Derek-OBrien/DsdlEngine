#include "Gui.h"
#include "Button.h"
#include "Window.h"
#include "Label.h"

/*
	File: Gui
	Author: Derek O Brien
	Description: GUi Layer templtate for creating an a UI Layer. Inherits from layer
*/
namespace DsdlEngine{
	
	//Constructor
	DsdlGui::DsdlGui() {
		//Empty
	}

	//Deconstructor
	DsdlGui::~DsdlGui() { 
		destroy(); 
	}

	//Add Button to GUI
	void DsdlGui::addButton(ButtonType type, std::string name, Vec2 pos, Vec2 size, std::string path, SDL_Color color, SDL_Color bgColor, const char* text) {

		m_btn = new Button();
		//Create as Text Button
		if (type == ButtonType::LABEL_BTN) {
			m_btn->createTextButton(pos, Size(size.x_, size.y_), text, path, color, bgColor);
			m_btn->setPosition(pos);
		}

		//Create as Sprite Button
		if (type == ButtonType::SPRITE_BTN) {
			m_btn->createSpriteButton(size , pos, path, name);
			m_btn->setEngineNodeType(NodeType::SPRITE);
			m_btn->setPosition(pos);
		}

		//Add button to gui elements array
		GUIElements.push_back(m_btn);
		layerNodes.push_back(m_btn);
	}

	//Add Label to Gui Layer
	void DsdlGui::addLabel(LableType type, Vec2 pos, std::string text, int fontSize, SDL_Color color, std::string fontFilePath){
		m_label = new Label();

		m_label->setType(type);
		m_label->create(pos, text, fontSize, color, fontFilePath);

		layerNodes.push_back(m_label);
	}


	//Add predefined label to the gui layer
	void DsdlGui::addPreDefineLabel(Label* label, LableType type) {
		label->setType(type);
		layerNodes.push_back(label);
	}

	//Set Gui Layer Position
	void DsdlGui::setGUIPos() {
		
	}

	//Event Manager for input on gui Buttons
	void DsdlGui::onSDLEvent(SDL_Event& e) {
		//Loop and Check each button for input
		for (size_t i = 0; i < GUIElements.size(); i++){
			GUIElements.at(i)->checkInput(e);
		}
	}

	//Destroy
	void DsdlGui::destroy() {
		//Empty
	}
}


