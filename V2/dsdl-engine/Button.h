#ifndef _BUTTON_
#define _BUTTON_

#include "EngineBaseNode.h"

#include "Label.h"
#include "Sprite.h"

namespace DsdlEngine {

	class Button : public EngineBaseNode {

	public:

		Button();
		virtual ~Button();

		void destroy();

		//Create Buttons
		void createTextButton(Vec2 pos, Size size, std::string buttonText, std::string fontPath, SDL_Color textColor, SDL_Color bgColor);
		void createSpriteButton(Vec2 spriteSize, Vec2 position, std::string imagePath, std::string name);

		//Set State to Hovering
		void onMouseEnters();

		//Set State Back to Normal
		void onMouseLeaves();

		//Set State to Pressd, Preform Action
		void onClicked();

		//Check for mouse input on a button
		void checkInput(SDL_Event& e);


		std::string getButtonName() { return m_buttonName; }

		ButtonState m_eCurrentState;// = ButtonState::NORMAL;
	private:


		Label* m_label;
		Sprite* m_spriteBtn;

		std::string m_buttonName;

	};
}

#endif //!_BUTTON_