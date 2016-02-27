#include "Button.h"

namespace DsdlEngine{
	//NS_DSDL_START


	Button::Button() {
		setEngineNodeType(NodeType::BUTTON);
		m_eCurrentState = ButtonState::NORMAL;
	}

	Button::~Button() { destroy(); }


	void Button::createTextButton(Vec2 pos, Size btnsize, std::string buttonText, std::string fontPath, SDL_Color color, SDL_Color bgColor){

		size.h_ = btnsize.h_;
		size.w_ =  buttonText.length() * btnsize.h_;

		position.x_ = pos.x_;
		position.y_ = pos.y_;

		buttonbg = bgColor;

		labelText = buttonText;
		textSize = btnsize.h_;
		textColor = color;
		setAssetPath(fontPath);

		labelBorder.h = size.h_;
		labelBorder.w = size.w_;
		labelBorder.x = position.x_;
		labelBorder.y = position.y_;

		m_label = new Label();
		m_label->create(pos, labelText, textSize, textColor, fontPath);
	}


	void Button::createSpriteButton(int width, int height, std::string imagePath){
		size.h_ = height;
		size.w_ = width;

		rect.h = size.h_;
		rect.w = size.w_;
		rect.x = position.x_;
		rect.y = position.y_;

		m_spriteBtn = new Sprite();
		m_spriteBtn->create(size.w_, size.h_, imagePath);
	}

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
	void Button::onClicked(){
		m_eCurrentState = ButtonState::PRESSED;
		DEBUG_MSG("Pressed button");

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
			else if (x > position.x_ + size.h_){
				inside = false;
			}
			else if (y < position.y_){
				inside = false;
			}
			else if (y > position.y_ + size.w_){
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
					onClicked();
					break;
					//Touch down
				case SDL_FINGERDOWN :
					onClicked();
					break;
				case SDL_FINGERMOTION:
					onMouseEnters();
					break;
				case SDL_FINGERUP:
					onMouseEnters();
					break;
				default:
					break;
				}
			}
		}

	}

	void Button::destroy(){

	}
}
//NS_DSDL_END