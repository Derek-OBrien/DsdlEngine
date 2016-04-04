#ifndef _INPUTMANAGER_
#define _INPUTMANAGER_

#include "EngineDefines.h"
/**
*	@author Derek O Brien
*
*	Class Based of https://www.youtube.com/watch?v=Epyih-LEbig&list=PLSPw4ASQYyymu3PfG9gxywSPghnSMiOAW&index=26 tutorial 
*/

namespace DsdlEngine{
	/**
	*	InputManager Class handles all input in the game
	*/
	class InputManager{
	public:
		/**
		*	Constructor
		*/
		InputManager();

		/**
		*	Deconstructor
		*/
		~InputManager();

		/**
		*	update, loops through the key map.
		*/
		void update();

		/**
		*	pressKey, add key pressed to the key map.
		*	@param keyID, the id of the key that was pressed.
		*/
		void pressKey(unsigned int keyID);
		
		/**
		*	releaseKey, remove key pressed from the key map and add to previous map.
		*	@param keyID, the id of the key that was pressed.
		*/
		void releaseKey(unsigned int keyID);

		/**
		*	setMouseCoords, set the coordinates for the mouse.
		*	@param x, float value for mouse x location.
		*	@param y, float value for mouse y location.
		*/
		void setMouseCoords(float x, float y);

		/**
		*	isKeyDown, check if key is down.
		*	@param keyID, ID of key to be checked.
		*	@return bool.
		*/
		bool isKeyDown(unsigned int keyID);

		/**
		*	isKeyPressed, check if key was just pressed.
		*	@param keyID, ID of key to be checked.
		*	@return bool.
		*/
		bool isKeyPressed(unsigned int keyID);

		/**
		*	isKeyReleased, check if key was just realesed.
		*	@param keyID, ID of key to be checked.
		*	@return bool.
		*/
		bool isKeyReleased(unsigned int KeyID);

		/**
		*	isTouch, check if it was touch event.
		*	@param keyID, ID of key to be checked.
		*	@return bool.
		*/
		bool isTouch(unsigned int keyID);

		/**
		*	isSwipe, check if it was a swipe event.
		*	@param evnt, event to be checked.
		*	@return bool.
		*/
		bool isSwipe(SDL_Event& evnt);

		/**
		*	isSwipeUP, check if event was a swipe up.
		*	@return bool.
		*/
		bool isSwipeUp();

		/**
		*	isSwipeDown, check if event was a swipe down.
		*	@return bool.
		*/
		bool isSwipeDown();

		/**
		*	isSwipeLeft, check if event was a swipe left.
		*	@return bool.
		*/
		bool isSwipeLeft(float x, float y);

		/**
		*	isSwipeRight, check if event was a swipe right.
		*	@return bool.
		*/
		bool isSwipeRight(float x, float y);

	private:

		/**
		*	wasKeyDown, Check if key was down.
		*	@param keyID, ID of key to be checked.
		*	@return bool.
		*/
		bool wasKeyDown(unsigned int keyID);

		std::unordered_map<unsigned int, bool> _keyMap;				/**< map to hold current keys*/
		std::unordered_map<unsigned int, bool> _previousKeyMap;		/**< map to hold previous keys*/

		bool swipeup, swipedown, swipeleft, swiperight;				/**< bools to control swipe checking*/
		bool fingerDown, fingerUp;									/**< bools to control touch checking*/
	};
}
#endif