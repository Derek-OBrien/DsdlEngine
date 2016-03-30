#ifndef _LABEL_
#define _LABEL_

#include "EngineBaseNode.h"
/*
	Base Label Class
	author: Derek O Brien
	Description: label class for creating labels. inherits for EngineBaseNode
*/
namespace DsdlEngine{
	class Label : public EngineBaseNode{
	public:
		Label();
		virtual ~Label();

		//Create bacis label
		void create(Vec2 pos, std::string text, int fontSize, SDL_Color color, std::string fontFilePath);

		//Set Type of for Label STATIC or DYNAMIC
		void setType(LableType type) { m_labelType = type; };

		//Get Type of for Label STATIC or DYNAMIC
		const int getType() { return (int)m_labelType; }

		//Destroy label
		void destroy();

		//Cleanup Label
		void cleanup();

	protected:
		LableType m_labelType;

	};
}
#endif	//!_LABEL_