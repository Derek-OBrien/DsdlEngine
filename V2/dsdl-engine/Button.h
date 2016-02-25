#ifndef _BUTTON_
#define _BUTTON_

#include "EngineBaseNode.h"

#include "Label.h"
#include "Sprite.h"

namespace DsdlEngine{

	//call back function
	//typedef bool(*buttonCallBack)(bool func());


	class Button : public EngineBaseNode{
		typedef bool(*callbck)();

	
	public:

		Button();
		virtual ~Button();


		void createTextButton(int width, int height, int textSize, std::string buttonText, std::string fontPath, SDL_Color textColor, SDL_Color bgColor);

		void createSpriteButton(int width, int height, std::string imagePath);

		//void render(SDL_Renderer* r);

		//Set State to Hovering
		void onMouseEnters();

		//Set State Back to Normal
		void onMouseLeaves();

		//Set State to Pressd, Preform Action
		void onClicked();

		//Check for mouse input on a button
		void checkInput(SDL_Event& e);

		//void assignCallBack(callbck cb){ cb = func; }

		void callback(void* func);
		void destroy();
	private:

		callbck func();
		//ResourceTexture* m_pButtonTexture = nullptr;
		Label* m_label;
		Sprite* m_spriteBtn;

		/*SDL_Rect rect;
		SDL_Color buttonbg;
		int m_BtnHeight;
		int m_BtnWidth;
		*/
		ButtonState m_eCurrentState;// = ButtonState::NORMAL;
	};
}

#endif