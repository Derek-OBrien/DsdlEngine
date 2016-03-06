#ifndef _BUTTON_
#define _BUTTON_

#include "EngineBaseNode.h"

#include "Label.h"
#include "Sprite.h"

namespace DsdlEngine{

	class Button : public EngineBaseNode{
		
	public:

		
		Button();
		virtual ~Button();


		void createTextButton(Vec2 pos, Size size, std::string buttonText, std::string fontPath, SDL_Color textColor, SDL_Color bgColor);

		void createSpriteButton(int width, int height, std::string imagePath);

		//Set State to Hovering
		void onMouseEnters();

		//Set State Back to Normal
		void onMouseLeaves();

		//Set State to Pressd, Preform Action
		void onClicked();

		//Check for mouse input on a button
		void checkInput(SDL_Event& e);

		void destroy();


		ButtonState m_eCurrentState;// = ButtonState::NORMAL;
	private:

		
		Label* m_label;
		Sprite* m_spriteBtn;

		/*SDL_Rect rect;
		SDL_Color buttonbg;
		int m_BtnHeight;
		int m_BtnWidth;
		*/
	};
}

#endif