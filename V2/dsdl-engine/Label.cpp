#include "Label.h"
/*
	Base Label Class
	author: Derek O Brien
	Description: label class for creating labels. inherits for EngineBaseNode
*/

namespace DsdlEngine{
	
	//Constructor
	Label::Label(){
		setEngineNodeType(NodeType::LABEL);
	}

	//Deconstructor
	Label::~Label() { 
		destroy(); 
	}
	
	//Create Label 
	void Label::create(Vec2 pos, std::string text, int txtsize, SDL_Color color, std::string fontFilePath){

		m_labelText = text;
		m_textSize = txtsize;
		m_textColor = color;

		setAssetPath(fontFilePath);

		m_position.x_ = pos.x_;
		m_position.y_ = pos.y_;
	}

	//Destroy Label
	void Label::destroy(){
		EngineBaseNode::destroy();
	}

	//Cleanup Label
	void Label::cleanup() {
		EngineBaseNode::cleanup();
	}
}