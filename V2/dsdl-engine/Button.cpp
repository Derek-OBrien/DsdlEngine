#include "Button.h"

namespace DsdlEngine{




	Button::Button(){}

	Button::~Button(){}


	void Button::createTextButton(int width, int height, int textSize, std::string buttonText, SDL_Renderer* r, std::string fontPath, SDL_Color textColor, SDL_Color bgColor ){

		m_BtnHeight = height;
		m_BtnWidth = width;
		

		rect.h = m_BtnHeight;
		rect.w = m_BtnWidth;
		rect.x = m_BtnPosX;
		rect.y = m_BtnPosY;

		buttonbg = bgColor;


		engineTexture = m_label.create(buttonText, textSize, textColor, fontPath, r);
	}


	void Button::createSpriteButton(int width, int height, SDL_Renderer* r, std::string imagePath){
		m_BtnHeight = height;
		m_BtnWidth = width;
		
		rect.h = m_BtnHeight;
		rect.w = m_BtnWidth;
		rect.x = m_BtnPosX;
		rect.y = m_BtnPosY;

		engineTexture = m_spriteBtn.createSprite( m_BtnWidth, m_BtnHeight, imagePath, r);
	}


	/*void Button::render( SDL_Renderer* r){

		//render button bg
		SDL_SetRenderDrawColor(r, buttonbg.r, buttonbg.g, buttonbg.b, buttonbg.a);
		SDL_RenderFillRect(r, &rect); 

		//render button outline
		SDL_SetRenderDrawColor(r, buttonbg.r, buttonbg.g, buttonbg.b, buttonbg.a);
		SDL_RenderDrawRect(r, &rect);


		engineTexture->render(m_posX, m_posY, r);
	}*/


	//Set State to Hovering
	void Button::onMouseEnters(){
		m_eCurrentState = ButtonState::HOVERING;
		DEBUG_MSG("Mouse over button");
	}

	//Set State Back to Normal
	void Button::onMouseLeaves(){
		m_eCurrentState = ButtonState::NORMAL;
	}

	//Set State to Pressd, Preform Action
	void Button::onClicked(buttonCallBack){
		m_eCurrentState = ButtonState::PRESSED;
		DEBUG_MSG("Pressed button");

		buttonCallBack();
	}



	//Check for mouse input on a button
	void Button::checkInput(SDL_Event& e){

		//check if mouse over button
		if (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP || e.type == SDL_MOUSEBUTTONUP){
			DEBUG_MSG("Checking if mouse over button");
			int x, y;
			SDL_GetMouseState(&x, &y);

			//Check if mouse inside button area
			bool inside = true;

			//Check if mouse inside button
			if (x < position.x_){
				inside = false;
			}
			else if (x > position.x_ + m_BtnWidth){
				inside = false;
			}
			else if (y < position.y_){
				inside = false;
			}
			else if (y > position.y_ + m_BtnHeight){
				inside = false;
			}

			//If mouse outside buttton
			if (!inside){
				onMouseLeaves();
			}
			else{//If mouse is inside button check mouse input type
				switch (e.type){
				case SDL_MOUSEMOTION:
					onMouseEnters();
					break;
				case SDL_MOUSEBUTTONUP:
					onMouseEnters();
					break;
				case SDL_MOUSEBUTTONDOWN:
					onClicked(buttonCallBack());
					break;
				default:
					break;
				}
			}
		}

	}
}