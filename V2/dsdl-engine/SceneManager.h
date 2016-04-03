#ifndef _SCREENMANAGER_
#define _SCREENMANAGER_

#include "EngineDefines.h"

/**
*	@author Derek O Brien
*/

namespace DsdlEngine{

	//Forward declearation of classes
	class IMainGame;
	class IScene;

	/**
	*	Scene Manager for handling all in game scenes, holds vector of all scenes,
	*/
	class SceneManager{
	public:
		
		/**
		*	Constructor.
		*	@param game, the IMainGame the manager belongs to
		*/
		SceneManager(IMainGame* game);

		/**
		*	Deconstructor.
		*/
		~SceneManager(){ destroy(); };

		/**
		*	Move to Next scene in vector
		*	@return IScene, the scene to move to.
		*/
		IScene* moveNext();

		/**
		*	Move to Previous scene in vector
		*	@return IScene, the scene to move to.
		*/
		IScene* movePrevious();

		/**
		*	Sets the current Scene
		*	@param nextScene, the current scene.
		*/
		void setScene(int nextScene);

		/**
		*	Add a Scene to the Scene Manager.
		*	@param newScene, the IScene to add to the Manager.
		*/
		void addScene(IScene* newScene);

		/**
		*	Destroy the SceneManager and all of its Scenes
		*/
		void destroy();

		/**
		*	Get the Current Scene been managed
		*	@return IScene, the current scene.
		*/
		IScene* getCurrentScene();
	
	protected:
		
		IMainGame* m_pGame;					/**< Main Game which scenemanager belongs too*/
		
		std::vector<IScene*> m_pScenes;		/**< Vector to hold the game scenes*/

		int m_iCurrentSceneIndex;			/**< index for the current Scene*/
	};
}
#endif	//!_SCREENMANAGER_