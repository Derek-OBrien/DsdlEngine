#ifndef GUI
#define GUI


#include "EngineDefines.h"
#include "Layer.h"
#include "IScene.h"

namespace DsdlEngine{

	class Button;
	class Label;

	class DsdlGui : public Layer
	{
	public:
		DsdlGui();
		virtual ~DsdlGui();


		void addButton(ButtonType type, std::string name, Vec2 pos, Size size, std::string path, SDL_Color color, SDL_Color bgColor, /*dsdlCallBack callback,*/ const char* text = NULL);

		void addLabel(LableType type, Vec2 pos, std::string text, int fontSize, SDL_Color color, std::string fontFilePath);

		void addPreDefineLabel(Label* label, LableType type);
		void setGUIPos();
		void onSDLEvent(SDL_Event& e);

		void destroy();

		std::vector<Button*> GUIElements;

		Button* getButton() { return m_btn; }
		//std::string getButtonName() { return buttonName; }

	protected:

		Label* m_label;
		Button* m_btn;
		//std::string buttonName;

		//dsdlCallBack m_callback;
	};
}

#endif // !GUI
