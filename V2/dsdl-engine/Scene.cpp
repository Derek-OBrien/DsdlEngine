#include "IScene.h"


namespace DsdlEngine {


	void IScene::onInput() {
		SDL_Event evnt;
		m_inputManager.update();

		while (SDL_PollEvent(&evnt)) {

			switch (evnt.type) {
			case SDL_QUIT:
				exit(1);
				break;
			case SDL_MOUSEMOTION:
				m_inputManager.setMouseCoords(evnt.motion.x, evnt.motion.y);
				break;
			case SDL_KEYDOWN:
				m_inputManager.pressKey(evnt.key.keysym.sym);
				break;
			case SDL_KEYUP:
				m_inputManager.releaseKey(evnt.key.keysym.sym);
				break;
			case SDL_MOUSEBUTTONDOWN:
				m_inputManager.pressKey(evnt.button.button);
				break;
			case SDL_MOUSEBUTTONUP:
				m_inputManager.releaseKey(evnt.button.button);
				break;
				//Touch down
			case SDL_FINGERDOWN:
				m_inputManager.pressKey(evnt.button.button);
				break;
			case SDL_FINGERMOTION:
				m_inputManager.setMouseCoords((float)evnt.motion.x, (float)evnt.motion.y);
				break;
			case SDL_FINGERUP:
				m_inputManager.releaseKey(evnt.button.button);
				break;
			default:
				break;
			}
		}
	}
}