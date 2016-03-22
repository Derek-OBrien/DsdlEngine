#include "Button.h"
#include "IScene.h"

namespace DsdlEngine {

	Button::Button() {
		setEngineNodeType(NodeType::LABEL);
		m_eCurrentState = ButtonState::NORMAL;
	}

	Button::~Button() { destroy(); }


	void Button::createTextButton(Vec2 pos, Size btnsize, std::string buttonText, std::string fontPath, SDL_Color color, SDL_Color bgColor) {

		m_size.y_ = btnsize.h_;
		m_size.x_ = buttonText.length() * btnsize.h_;

		m_position.x_ = pos.x_;
		m_position.y_ = pos.y_;

		m_buttonbg = bgColor;

		m_labelText = buttonText;
		m_textSize = btnsize.h_;
		m_textColor = color;
		setAssetPath(fontPath);

		m_label = new Label();
		m_label->create(pos, m_labelText, m_textSize, m_textColor, fontPath);
	}


	void Button::createSpriteButton(Vec2 spriteSize, Vec2 position, std::string imagePath, std::string name) {
		m_size.x_ = spriteSize.x_;
		m_size.y_ = spriteSize.y_;

		setAssetPath(imagePath);

		m_buttonName = name;

		m_position.x_ = position.x_;
		m_position.y_ = position.y_;
		setPosition(position);

		m_rect.h = m_size.y_;
		m_rect.w = m_size.x_;
		m_rect.x = m_position.x_;
		m_rect.y = m_position.y_;

		setEngineNodeType(NodeType::SPRITE);

		m_numFrames = 1;
		m_spriteBtn = new Sprite();
		m_spriteBtn->create(m_size, m_position, imagePath, 1);
	}

	//Set State to Hovering
	void Button::onMouseEnters() {
		m_eCurrentState = ButtonState::HOVERING;
		SDL_Log("Mouse over button");
	}

	//Set State Back to Normal
	void Button::onMouseLeaves() {
		m_eCurrentState = ButtonState::NORMAL;
	}

	//Set State to Pressd, Preform Action
	void Button::onClicked() {
		m_eCurrentState = ButtonState::PRESSED;
		SDL_Log("Pressed button");
	}

	//Check for mouse input on a button
	void Button::checkInput(SDL_Event& e) {

		//check if mouse over button
		if (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP) {
			int x, y;
			SDL_GetMouseState(&x, &y);

			//Check if mouse inside button area
			bool inside = true;

			//Check if mouse inside button
			if (x < m_position.x_) {
				inside = false;
			}
			else if (x > m_position.x_ + m_size.y_) {
				inside = false;
			}
			else if (y < m_position.y_) {
				inside = false;
			}
			else if (y > m_position.y_ + m_size.x_) {
				inside = false;
			}

			//If mouse outside buttton
			if (!inside) {
				onMouseLeaves();
			}
			else {//If mouse is inside button check mouse input type
				switch (e.type) {
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
				case SDL_FINGERDOWN:
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

	void Button::destroy() {

	}
}