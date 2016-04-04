#include "InputManager.h"

namespace DsdlEngine{


	InputManager::InputManager(){
		swipedown = false;
		swipeup = false;
		swipeleft = false;
		swiperight = false;
	}
	
	InputManager::~InputManager(){
		//Empty
	}


	void InputManager::update() {
		// Loop through _keyMap using a for each loop, and copy it over to _previousKeyMap
		for (auto& it : _keyMap) {
			_previousKeyMap[it.first] = it.second;
		}
	}

	void InputManager::pressKey(unsigned int keyID) {
		// if keyID doesn't already exist in _keyMap, it will get added
		_keyMap[keyID] = true;
	}

	void InputManager::releaseKey(unsigned int keyID) {
		_keyMap[keyID] = false;
	}

	void InputManager::setMouseCoords(float x, float y) {
		
	}


	bool InputManager::isKeyDown(unsigned int keyID) {
		// We dont want to use the associative array approach here
		// because we don't want to create a key if it doesnt exist.
		// So we do it manually
		auto it = _keyMap.find(keyID);
		if (it != _keyMap.end()) {
			// Found the key
			return it->second;
		}
		else {
			// Didn't find the key
			return false;
		}
	}

	bool InputManager::wasKeyDown(unsigned int keyID) {
		// We dont want to use the associative array approach here
		// because we don't want to create a key if it doesnt exist.
		// So we do it manually
		auto it = _previousKeyMap.find(keyID);
		if (it != _previousKeyMap.end()) {
			// Found the key
			return it->second;
		}
		else {
			// Didn't find the key
			return false;
		}
	}

	bool InputManager::isKeyPressed(unsigned int keyID) {
		// Check if it is pressed this frame, and wasn't pressed last frame
		if (isKeyDown(keyID) == true && wasKeyDown(keyID) == false) {
			pressKey(keyID);
			return true;
		}
		return false;
	}


	bool InputManager::isKeyReleased(unsigned int keyID) {
		// Check if it is pressed this frame, and wasn't pressed last frame
		if (isKeyDown(keyID) == false && wasKeyDown(keyID) == true) {
			releaseKey(keyID);
			return true;
		}
		return false;

	}


	bool InputManager::isTouch(unsigned int keyID) {

		if (keyID == SDL_FINGERDOWN) {
			return true;
		}
		return false;
	}



	bool InputManager::isSwipe(SDL_Event& evnt) {
		
		float startX, startY, endX, endY;
	
		if (evnt.type = SDL_FINGERMOTION) {
			
			startX = ((float)evnt.tfinger.x);
			startY = ((float)evnt.tfinger.y);
			fingerDown = true;

			if (evnt.type = SDL_FINGERUP) {
				endX = ((float)evnt.tfinger.x);
				endY = ((float)evnt.tfinger.y);
				fingerUp = true;
			}
		}

		
		if (fingerDown && fingerUp) {

			if (startX < endX) {
				//swipe down
				SDL_Log("SWIPE DOWN---Start : %f ----- End : %f", startX, endX);
				swipedown = true;
			}
			else if (startX > endX) {
				//swipe up
				SDL_Log("SWIPE UP---Start : %f ----- End : %f", startX, endX);
				swipeup = true;
			}
			else if (startY > endY) {
				//swipe left
				swipeleft = true;
				SDL_Log("SWIPE LEFT---Start : %f ----- End : %f", startY, endY);
			}
			else if (startY < endY) {
				//swipe right
				swiperight = true;
				SDL_Log("SWIPE RIGHT---Start : %f ----- End : %f", startY, endY);
			}
			else if (startX == endX) {
				SDL_Log("Only tough happened not swipe");
			}
		}
		return true;
	}



	bool InputManager::isSwipeUp() {

		return swipeup;
	}

	bool InputManager::isSwipeDown() {

		return swipedown;
	}

	bool InputManager::isSwipeLeft(float x, float y) {

		return swipeleft;
	}

	bool InputManager::isSwipeRight(float x, float y) {

		return swiperight;
	}

}
