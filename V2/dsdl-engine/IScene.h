/*
	Base Scene Class
	author: @Derek O Brien
	Description: Interface for base scene in game.
*/

#ifndef _ISCENE_
#define _ISCENE_

#define SCENE_INDEX_NO_SCENE -1
#include "EngineDefines.h"
#include "EngineBaseNode.h"
#include "Sprite.h"
#include "InputManager.h"
#include "Layer.h"

namespace DsdlEngine{

	class IMainGame;

	enum class SceneState{
		NONE,
		RUNNING,
		EXIT_APP,
		CHANGE_NEXT,
		CHANGE_PREVIOUS
	};
	 

	class IScene{
	public:
	
		IScene(){
			//Empty
		};
		virtual ~IScene(){
			//Empty
		};

		// Return the index of the next or previous screen when changing screens
		virtual int getNextSceneIndex() const = 0;
		virtual int getPreviousSceneIndex() const = 0;

		// Called when a screen enters and exits focus
		virtual void onEntryScene() = 0;
		virtual void onExitScene() = 0;

		// Called while in focus
		virtual void updateScene() = 0;
		
		//Destroy scene on clean up
		virtual void destroyScene() = 0;


		int getSceneIndex() const{ return m_iSceneIndex; }
		SceneState getSceneState() const { return m_eCurrentState; }
		void setSceneRunning(){ m_eCurrentState = SceneState::RUNNING; }

		// Sets m_game to the parent game
		void setParentGame(IMainGame* game) { m_game = game; }

		
		virtual void onInput() {
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
		//Vector to hold Game Layers
		//Each Layer Contains Vector of game nodes
		std::vector<Layer*> sceneLayers;

		void addLayerToScene(Layer* layer) {
			sceneLayers.push_back(layer);
		}


		//Load nodes in current Scene
		void loadScene(SDL_Renderer* r) {
			for (size_t i = 0; i < sceneLayers.size(); i++) {
				sceneLayers.at(i)->loadNodes(r);
			}
		}

		//Draw Nodes in current scene
		void drawScene(SDL_Renderer* r) {
			for (size_t i = 0; i < sceneLayers.size(); i++) {
				sceneLayers.at(i)->drawNodes(r);
			}
			/*for (size_t i = 0; i < sceneLayers.size(); i++) {
				sceneLayers.at(i)->drawBox2dNodes(r);
			}*/
		}
		
	protected:

		friend class SceneManager;
		friend class InputManager;
		SceneState m_eCurrentState = SceneState::NONE;

		IMainGame* m_game = nullptr;
		int m_iSceneIndex = SCENE_INDEX_NO_SCENE;
		InputManager m_inputManager;
		
	};
}


#endif