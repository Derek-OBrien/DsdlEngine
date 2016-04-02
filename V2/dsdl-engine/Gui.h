#ifndef _GUI_
#define _GUI_

#include "EngineDefines.h"
#include "Layer.h"
#include "IScene.h"

/**
*	@author Derek O Brien
*/
namespace DsdlEngine{

	//Forward Decalare Classes
	class Button;
	class Label;

	/**
	*	 GUi Layer templtate for creating an a UI Layer. Inherits from layer
	*/
	class DsdlGui : public Layer{
	public:
		/**
		*	Constructor
		*/
		DsdlGui();

		/**
		*	Deconstructor
		*/
		virtual ~DsdlGui();
		
		/**
		*	addButton, Creates and adds a button to the UI layer.
		*	@parma type, type of button as a ButtonType
		*	@parma name, std::string name of the button
		*	@parma pos, Vec2 position of the button
		*	@parma size, Vec2 size of the button
		*	@parma path, path to texture to load.
		*	@parma color, SDL_color of the button. for label type
		*	@parma bgColor, background color of the button. for label type.
		*	@parma text, text to display. for label type.
		*/
		void addButton(ButtonType type, std::string name, Vec2 pos, Vec2 size, std::string path, SDL_Color color, SDL_Color bgColor, const char* text = NULL);

		/**
		*	addLabel, Creates and adds a Label to the UI layer.
		*	@parma type, type of labe as a LabelType
		*	@parma pos, Vec2 position of the label
		*	@parma text, text to display. for label type.
		*	@parma fontsize, as int size of font.
		*	@parma color, SDL_color of the label.
		*	@parma fontFilePath, file path to the font.
		*/
		void addLabel(LableType type, Vec2 pos, std::string text, int fontSize, SDL_Color color, std::string fontFilePath);

		/**
		*	addPredefinedLabel, add a pre made label to the UI layer,
		*	@parma label, the Label to be added.
		*	@parma type, the type of label.
		*/
		void addPreDefineLabel(Label* label, LableType type);

		/**
		*	setGUIPos, set the GUI position
		*/
		void setGUIPos();

		/**
		*	onSDLEvent, evnet listener for GUI buttons.
		*	@param e, evnent to listen on.
		*/
		void onSDLEvent(SDL_Event& e);

		/**
		*	destroy, Clean up when left scope.
		*/
		void destroy();

		std::vector<Button*> GUIElements;		/**< Vector to hold GUI Elements*/

		/**
		*	getButton, Get button from the UIElemets vector
		*	@return Button.
		*/
		Button* getButton() { return m_btn; }

	protected:
		//Variables
		Label* m_label;
		Button* m_btn;
	};
}

#endif //!_GUI_
