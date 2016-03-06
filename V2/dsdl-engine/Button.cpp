#include "Button.h"
#include "IScene.h"

namespace DsdlEngine{
	//NS_DSDL_START


	Button::Button() {
		setEngineNodeType(NodeType::BUTTON);
		m_eCurrentState = ButtonState::NORMAL;
	}

	Button::~Button() { destroy(); }


	void Button::createTextButton(Vec2 pos, Size btnsize, std::string buttonText, std::string fontPath, SDL_Color color, SDL_Color bgColor){

		size.y_ = btnsize.h_;
		size.x_ =  buttonText.length() * btnsize.h_;

		position.x_ = pos.x_;
		position.y_ = pos.y_;

		buttonbg = bgColor;

		labelText = buttonText;
		textSize = btnsize.h_;
		textColor = color;
		setAssetPath(fontPath);

		labelBorder.h = size.y_;
		labelBorder.w = size.x_;
		labelBorder.x = position.x_;
		labelBorder.y = position.y_;

		m_label = new Label();
		m_label->create(pos, labelText, textSize, textColor, fontPath);
	}


	void Button::createSpriteButton(int width, int height, std::string imagePath){
		size.y_ = height;
		size.x_ = width;

		setAssetPath(imagePath);

		rect.h = size.y_;
		rect.w = size.x_;
		rect.x = position.x_;
		rect.y = position.y_;

		setEngineNodeType(NodeType::SPRITE);

		m_numFrames = 3;
		m_spriteBtn = new Sprite();
		m_spriteBtn->create(width, height, imagePath, 3);
	}

	//Set State to Hovering
	void Button::onMouseEnters(){
		m_eCurrentState = ButtonState::HOVERING;
		SDL_Log("Mouse over button");
	}

	//Set State Back to Normal
	void Button::onMouseLeaves(){
		m_eCurrentState = ButtonState::NORMAL;
	}

	Uint32 callback(Uint32 interval, void* func) {
		return ((class IScene *)func)->getNextSceneIndex();
	}


	//Set State to Pressd, Preform Action
	void Button::onClicked(){
		m_eCurrentState = ButtonState::PRESSED;
		SDL_Log("Pressed button");

		//Set callback
		CallBackTimer timerID = SDL_AddTimer(3 * 1000, callback, this);

	}

	//Check for mouse input on a button
	void Button::checkInput(SDL_Event& e){

		//check if mouse over button
		if (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP || e.type == SDL_MOUSEBUTTONUP){
			SDL_Log("Checking if mouse over button");
			int x, y;
			SDL_GetMouseState(&x, &y);
	
			//Check if mouse inside button area
			bool inside = true;

			//Check if mouse inside button
			if (x < position.x_){
				inside = false;
			}
			else if (x > position.x_ + size.y_){
				inside = false;
			}
			else if (y < position.y_){
				inside = false;
			}
			else if (y > position.y_ + size.x_){
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