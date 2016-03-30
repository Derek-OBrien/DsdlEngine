#ifndef _SCREENMANAGER_
#define _SCREENMANAGER_

#include "EngineDefines.h"

/*
	name:	SceneManager
	author: @Derek O Brien
	Description: Scene Manager for handling all in game scenes
	holds vector of all scenes,
*/

namespace DsdlEngine{

	//Forward declearation of classes
	class IMainGame;
	class IScene;

	class SceneManager{
	public:
	
		SceneManager(IMainGame* game);
		~SceneManager(){ destroy(); };

		//Move to next scene
		IScene* moveNext();

		//Move to previous scene
		IScene* movePrevious();

		//Set scene
		void setScene(int nextScene);

		//Add a scene to the manager
		void addScene(IScene* newScene);

		//Destroy scene manager
		void destroy();

		//Get current loaded scene
		IScene* getCurrentScene();
	
	protected:
		//Main Game which scenemanager belongs too
		IMainGame* m_pGame;
		
		//Vector to hold scenes
		std::vector<IScene*> m_pScenes;

		//Current Scene index
		int m_iCurrentSceneIndex;
	};
}
#endif	//!_SCREENMANAGER_