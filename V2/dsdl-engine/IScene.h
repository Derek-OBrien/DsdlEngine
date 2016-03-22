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

namespace DsdlEngine {

	class IMainGame;

	enum class SceneState {
		NONE,
		RUNNING,
		EXIT_APP,
		CHANGE_NEXT,
		CHANGE_PREVIOUS
	};


	class IScene {
	public:

		IScene() {
			//Empty
		};
		virtual ~IScene() {
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


		int getSceneIndex() const { return m_iSceneIndex; }
		SceneState getSceneState() const { return m_eCurrentState; }
		void setSceneRunning() { m_eCurrentState = SceneState::RUNNING; }

		// Sets m_game to the parent game
		void setParentGame(IMainGame* game) { m_game = game; }


		virtual void onInput();

		//Vector to hold Game Layers
		//Each Layer Contains Vector of game nodes
		std::vector<Layer*> sceneLayers;

		/*
			Add Layers to the scene
		*/
		void addLayerToScene(Layer* layer) {
			sceneLayers.push_back(layer);
		}


		//Load nodes in layer for current scene
		void loadScene(SDL_Renderer* r) {
			for (size_t i = 0; i < sceneLayers.size(); i++) {
				sceneLayers.at(i)->loadNodes(r);
			}
		}

		//Draw nodes in layer for current scene
		void drawScene(SDL_Renderer* r) {
			for (size_t i = 0; i < sceneLayers.size(); i++) {
				sceneLayers.at(i)->drawNodes(r);
			}
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