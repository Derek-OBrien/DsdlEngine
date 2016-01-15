#ifndef _SCREENMANAGER_
#define _SCREENMANAGER_
#include "EngineDefines.h"

namespace DsdlEngine{

	class IMainGame;
	class IScene;

	class SceneManager{
	public:
		static SceneManager* getInstance();


		~SceneManager(){ destroy(); };

		IScene* moveNext();
		IScene* movePrevious();

		void setScene(int nextScene);
		void addScene(IScene* newScenen);

		void destroy();

		IScene* getCurrentScene();
	
	protected:
		IMainGame* m_pGame = nullptr;
		std::vector<IScene*> m_pScenes;
		int m_iCurrentSceneIndex = -1;
	
	private:
		SceneManager(){ m_iCurrentSceneIndex = 0; };

	};
}
#endif