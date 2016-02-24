#ifndef _SCREENMANAGER_
#define _SCREENMANAGER_
/*
name:	SceneManager
author: @Derek O Brien
Description: Scene Manager for handling all in game scenes
holds vector of all scenes,
*/

#include "EngineDefines.h"

namespace DsdlEngine{

	class IMainGame;
	class IScene;

	class SceneManager{
	public:
	

		SceneManager(IMainGame* game);
		~SceneManager(){ destroy(); };

		IScene* moveNext();
		IScene* movePrevious();

		void setScene(int nextScene);
		void addScene(IScene* newScenen);

		void destroy();

		IScene* getCurrentScene();
	
	protected:
		IMainGame* m_pGame;
		std::vector<IScene*> m_pScenes;
		int m_iCurrentSceneIndex;
	
	
	};
}
#endif