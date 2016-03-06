#ifndef GUI
#define GUI


#include "EngineDefines.h"
#include "Layer.h"

namespace DsdlEngine{

	class Button;
	class Label;

	class DsdlGui : public Layer
	{
	public:
		DsdlGui();
		virtual ~DsdlGui();


		void addButton(ButtonType type, std::string name, Vec2 pos, Size size, std::string path, SDL_Color color, SDL_Color bgColor, const char* text = NULL);

		void addLabel(LableType type, Vec2 pos, std::string text, int fontSize, SDL_Color color, std::string fontFilePath);

		void addPreDefineLabel(Label* label, LableType type);
		void setGUIPos();
		void onSDLEvent(SDL_Event& e);

		void destroy();

		std::vector<EngineBaseNode*> GUIElements;


		Button* m_btn;
		std::string buttonName;
	private:

		Label* m_label;
	};
}

#endif // !GUI
