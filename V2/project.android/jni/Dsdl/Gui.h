
#include "EngineDefines.h"


namespace DsdlEngine{
	class Gui
	{
	public:
		Gui();
		~Gui();

		void showMouse();
		void hideMouse();
		void setMouse();

		void onSDLEvent(SDL_Event& e);

	private:

	};

	Gui::Gui(){}

	Gui::~Gui(){}
}