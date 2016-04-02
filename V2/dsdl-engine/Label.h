#ifndef _LABEL_
#define _LABEL_

#include "EngineBaseNode.h"
/**
*	@author Derek O Brien
*/
namespace DsdlEngine{
	/**
	*	Label class is the base for all labels in the engine it inherits for EngineBaseNode.
	*/
	class Label : public EngineBaseNode{
	public:
		/***
		*	COnstructor
		*/
		Label();

		/**
		*	Deconstructor
		*/
		virtual ~Label();

		/**
		*	Create a basic Label
		*	@parma pos, Vec2 Position of the label.
		*	@parma text, std::String label display text,
		*	@parma fontSize, int the font size to use
		*	@parma color, SDL_Color of the label.
		*	@parma fontFilePath, std::string path to the font to use.
		*/
		void create(Vec2 pos, std::string text, int fontSize, SDL_Color color, std::string fontFilePath);

		/**
		*	Set the type of label STATIC or DYNAMIC
		*	@parma type, type of label.
		*/
		void setType(LableType type) { m_labelType = type; };

		/**
		*	Get the type of label it is.
		*	@return int label type,
		*/
		const int getType() { return (int)m_labelType; }

		/**
		*	Destroy the label.
		*/
		void destroy();

		/**
		*	Cleanup the lable texture.
		*/
		void cleanup();

	protected:
		LableType m_labelType;	/**< LabelType variable*/

	};
}
#endif	//!_LABEL_