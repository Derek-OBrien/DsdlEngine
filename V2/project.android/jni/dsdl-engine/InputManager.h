#ifndef _INPUTMANAGER_
#define _INPUTMANAGER_

#include <unordered_map>

namespace DsdlEngine{
	class InputManager{
	public:
		InputManager();
		~InputManager();

		void update();

		void pressKey(unsigned int keyID);
		void releaseKey(unsigned int keyID);

		void setMouseCoords(float x, float y);

		/// Returns true if the key is held down
		bool isKeyDown(unsigned int keyID);

		/// Returns true if the key was just pressed
		bool isKeyPressed(unsigned int keyID);

	private:

		/// Returns true if the key is held down
		bool wasKeyDown(unsigned int keyID);


		std::unordered_map<unsigned int, bool> _keyMap;
		std::unordered_map<unsigned int, bool> _previousKeyMap;

	};
}
#endif