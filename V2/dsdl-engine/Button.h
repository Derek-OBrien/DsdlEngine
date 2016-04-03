#ifndef _BUTTON_
#define _BUTTON_

#include "EngineBaseNode.h"

#include "Label.h"
#include "Sprite.h"

/**
*	@author Derek O Brien
*/

namespace DsdlEngine {

	/**
	*	Button Class subclass of EngineBaseNode.
	*	The button class is for creating buttons and handling events on such buttons.
	*/
	class Button : public EngineBaseNode {

	public:
		/**
		*	Button Constructor.
		*/
		Button();

		/**
		*	Button Deconstructor.
		*/
		virtual ~Button();

		/**
		*	destroy. responsible for cleaning up after button gose out of scope.
		*/
		void destroy();

		/**
		*	Create button as Label node.
		*	@param pos as a Vec2 position argument.
		*	@param size as a Size content size argument.
		*	@param buttonText as a std::string argument.
		*	@param fontPath as a std::string argument.
		*	@param textColor as a SDL_Color argument.
		*	@param bgColor as a SDL_Color argument.
		*/
		void createTextButton(Vec2 pos, Size size, std::string buttonText, std::string fontPath, SDL_Color textColor, SDL_Color bgColor);

		/**
		*	Create button as a Sprite node.
		*	@param spriteSize as a Vec2 argument.
		*	@param position as a Vec2 position argument
		*	@param imagePath as a std::string path to image
		*	@param name as a std::string name of button
		*/
		void createSpriteButton(Vec2 spriteSize, Vec2 position, std::string imagePath, std::string name);

		/**
		*	checkInput.
		*	Check for input event on the current button.
		*	@param e as SDL_Event argument.
		*/
		void checkInput(SDL_Event& e);


		/**
		*	getButtonName.
		*	Get the name of the button.
		*	@return std::string name of the button
		*/
		std::string getButtonName() { return m_buttonName; }

		/**
		*	ButtonState.
		*	Enum class for handeling the buttons state.
		*/
		ButtonState m_eCurrentState;
	private:

		/**
		*	onMouseEnters.
		*	Set button state to HOVERING.
		*/
		void onMouseEnters();

		/**
		*	onMouseLeaves.
		*	Set button state to NORMAL.
		*/
		void onMouseLeaves();

		/**
		*	onCLicked.
		*	Set button state to CLICKED.
		*/
		void onClicked();


		/**
		*	Label varaible for creating label buttons.
		*/
		Label* m_label;

		/**
		*	Sprite variable for creating sprite button.
		*/
		Sprite* m_spriteBtn;

		/**
		*	std::string button name variable.
		*/
		std::string m_buttonName;

	};
}

#endif //!_BUTTON_