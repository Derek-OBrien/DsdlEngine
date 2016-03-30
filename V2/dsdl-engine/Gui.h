#ifndef _GUI_
#define _GUI_

#include "EngineDefines.h"
#include "Layer.h"
#include "IScene.h"

/*
	File: Gui
	Author: Derek O Brien
	Description: GUi Layer templtate for creating an a UI Layer. Inherits from layer
*/
namespace DsdlEngine{

	//Forward Decalare Classes
	class Button;
	class Label;

	class DsdlGui : public Layer{
	public:
		//Constructor
		DsdlGui();
		//Deconstructor
		virtual ~DsdlGui();
		
		//Create and Add button to a gui layer
		void addButton(ButtonType type, std::string name, Vec2 pos, Vec2 size, std::string path, SDL_Color color, SDL_Color bgColor, const char* text = NULL);

		//Create and Add label to a gui layer
		void addLabel(LableType type, Vec2 pos, std::string text, int fontSize, SDL_Color color, std::string fontFilePath);

		//Add A label allready created to the layer
		void addPreDefineLabel(Label* label, LableType type);

		//Set position of layer
		void setGUIPos();

		//Event manager for layer buttons
		void onSDLEvent(SDL_Event& e);

		//Destroy
		void destroy();

		//Vector to hold layer buttons
		std::vector<Button*> GUIElements;

		//Get each button added to layer
		Button* getButton() { return m_btn; }

	protected:
		//Variables
		Label* m_label;
		Button* m_btn;
	};
}

#endif //!_GUI_
