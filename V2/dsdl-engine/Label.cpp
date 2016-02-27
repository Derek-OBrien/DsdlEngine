#include "Label.h"


namespace DsdlEngine{

	Label::Label(){
		setEngineNodeType(NodeType::LABEL);
	}

	Label::~Label() { destroy(); }



	void Label::create(Vec2 pos, std::string text, int txtsize, SDL_Color color, std::string fontFilePath){

		labelText = text;
		textSize = txtsize;
		textColor = color;
		setAssetPath(fontFilePath);

		position.x_ = pos.x_;
		position.y_ = pos.y_;


		labelBorder.h = txtsize;
		labelBorder.w = text.length() * txtsize;
		labelBorder.x = position.x_;
		labelBorder.y = position.y_;
	}


	void Label::destroy(){
		EngineBaseNode::destroy();
	}


}