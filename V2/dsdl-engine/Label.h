#ifndef _LABEL_
#define _LABEL_

#include "EngineBaseNode.h"

namespace DsdlEngine{
	class Label : public EngineBaseNode
	{
	public:
		Label();
		virtual ~Label();

		/**
		* Create a TTF label
		*
		* @param text The initial text.
		* @param fontFilePath A font file.
		* @param fontSize The font size. This value must be > 0.
		* @param color The Color of the label
		*/

		void setType(LableType type) { m_labelType = type; };
		const int getType() {return (int)m_labelType;}


		void create(Vec2 pos, std::string text, int fontSize, SDL_Color color, std::string fontFilePath);

		void destroy();
		void cleanup();
	protected:

		LableType m_labelType;

	};
}

#endif