#ifndef _BUTTON_
#define _BUTTON_

#include "EngineDefines.h"
#include "ResourceTexture.h"
#include "Label.h"
#include "Sprite.h"

#include <functional>

namespace DsdlEngine{
	

	class Label;
	class Sprite;

	enum class ButtonState{
		NORMAL,
		PRESSED,
		HOVERING
	};
	class Button{
	public:
		Button();
		~Button();


		void createTextButton(int posX, int posY, int width, int height, int textSize, std::string buttonText, SDL_Renderer* r, std::string fontPath, SDL_Color textColor, SDL_Color bgColor);

		void createSpriteButton(int posX, int posY, int width, int height, SDL_Renderer* r, std::string imagePath);

		void render( SDL_Renderer* r);
		//Set State to Hovering
		void onMouseEnters();

		//Set State Back to Normal
		void onMouseLeaves();

		//Set State to Pressd, Preform Action
		void onClicked();

		//Check for mouse input on a button
		void checkInput(SDL_Event& e);

	private:

		ResourceTexture* m_pButtonTexture = nullptr;
		Label m_label;
		Sprite m_spriteBtn;

		SDL_Rect rect;
		SDL_Color buttonbg;
		int m_BtnHeight = 0;
		int m_BtnWidth = 0;
		int m_BtnPosX = 0;
		int m_BtnPosY = 0;

		ButtonState m_eCurrentState = ButtonState::NORMAL;
	};
}

#endif