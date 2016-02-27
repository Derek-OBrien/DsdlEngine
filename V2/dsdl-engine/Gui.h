#ifndef GUI
#define GUI


#include "EngineDefines.h"
#include "Layer.h"

namespace DsdlEngine{

	class Button;

	class DsdlGui : public Layer
	{
	public:
		DsdlGui();
		virtual ~DsdlGui();


		void addButton(ButtonType type, Vec2 pos, Size size, const char* path, SDL_Color color, SDL_Color bgColor, const char* text = NULL);
		void addLabel();

		void setGUIPos();
		void onSDLEvent(SDL_Event& e);

		void destroy();
		std::vector<EngineBaseNode*> GUIElements;
	private:

		Button* m_btn;
	};
}

#endif // !GUI
