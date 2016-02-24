
#include "EngineDefines.h"
#include "Layer.h"

namespace DsdlEngine{
	class Gui : public Layer
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