#include "Label.h"


namespace DsdlEngine{

	Label::Label(){
		setEngineNodeType(NodeType::LABEL);
	}

	Label::~Label() { destroy(); }



	void Label::create(Vec2 pos, std::string text, int txtsize, SDL_Color color, std::string fontFilePath){

		m_labelText = text;
		m_textSize = txtsize;
		m_textColor = color;

		setAssetPath(fontFilePath);

		m_position.x_ = pos.x_;
		m_position.y_ = pos.y_;
	}


	void Label::destroy(){
		EngineBaseNode::destroy();
	}


}