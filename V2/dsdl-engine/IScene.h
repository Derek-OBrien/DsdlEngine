#ifndef _ISCENE_
#define _ISCENE_

#define SCENE_INDEX_NO_SCENE -1
#include "EngineDefines.h"
#include "EngineBaseNode.h"
#include "Sprite.h"
#include "InputManager.h"
#include "Layer.h"

/**
*	@author Derek O Brien
*/

namespace DsdlEngine {

	//forward declartion of class
	class IMainGame;

	/**
	*	SceneState enum class.
	*	For use when controlling the which scene is active..
	*/
	enum class SceneState {
		NONE,
		RUNNING,
		EXIT_APP,
		CHANGE_NEXT,
		CHANGE_PREVIOUS
	};

	/**
	*	IScene is a inteface class to inherith from when creating a scene in the game.
	*/
	class IScene {
	public:
		/**
		*	Constructor
		*/
		IScene() {
			//Empty
		};

		/**
		*	Deconstructor
		*/
		virtual ~IScene() {
			//Empty
		};

		/**
		*	Pure virtual function returns next scene.
		*	@return const int.
		*/
		virtual int getNextSceneIndex() const = 0;

		/**
		*	Pure virtual function returns previous scene.
		*	@return const int.
		*/
		virtual int getPreviousSceneIndex() const = 0;

		// Called when a screen enters and exits focus

		/**
		*	Pure virtual function.
		*	Called when scene is loaded into focus.
		*/
		virtual void onEntryScene() = 0;

		/**
		*	Pure virtual function.
		*	Called when scene leaves focus.
		*/
		virtual void onExitScene() = 0;

		/**
		*	Pure virtual function.
		*	Called when scene is in focus and updates all elemets in the scene.
		*/
		virtual void updateScene() = 0;

		/**
		*	Pure virtual function.
		*	Destroy and cleanup when scene leaves scope.
		*/
		virtual void destroyScene() = 0;

		/**
		*	Gets the current scene's index.
		*	@return int.
		*/
		int getSceneIndex() const { return m_iSceneIndex; }

		/**
		*	Get the current scenes state.
		*	@return SceneState int.
		*/
		SceneState getSceneState() const { return m_eCurrentState; }

		/**
		*	Set a scene running by setting the state.
		*/
		void setSceneRunning() { m_eCurrentState = SceneState::RUNNING; }

		/**
		*	Set the game that the scene belongs to.
		*	@parma game. the IMainGame the scene belongs to.
		*/
		void setParentGame(IMainGame* game) { m_game = game; }
		
		/**
		*	Virtual function for scene specific input.
		*/
		virtual void onInput();

		std::vector<Layer*> sceneLayers;		/**< Vector to hold scenes game Layer*/

		/**
		*	Add a Layer to the current Scene.
		*	@param layer, Layer to add to the scene.
		*/
		void addLayerToScene(Layer* layer) {
			sceneLayers.push_back(layer);
		}

		/**
		*	Load the scene and its layers.
		*	@param r, SDL_Renderer to use when loading
		*/
		void loadScene(SDL_Renderer* r) {
			for (size_t i = 0; i < sceneLayers.size(); i++) {
				sceneLayers.at(i)->loadNodes(r);
			}
		}

		/**
		*	Draw the current scenes layers to the window.
		*	@param r, SDL_Renderer to use when rendering.
		*/
		void drawScene(SDL_Renderer* r) {
			for (size_t i = 0; i < sceneLayers.size(); i++) {
				sceneLayers.at(i)->drawNodes(r);
			}
		}

	protected:
		///Friend Classes.
		friend class SceneManager;		
		friend class InputManager;

		SceneState m_eCurrentState = SceneState::NONE;		/**< Scenes current state variabel*/

		IMainGame* m_game = nullptr;						/**< parent game.*/
		int m_iSceneIndex = SCENE_INDEX_NO_SCENE;			/**< scene index int*/
		InputManager m_inputManager;						/**< scnenes input manager*/

	};
}


#endif //!_ISCENE_