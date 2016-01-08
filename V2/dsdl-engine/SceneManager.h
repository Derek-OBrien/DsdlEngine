#ifndef _SCREENMANAGER_
#define _SCREENMANAGER_

#include <vector>

namespace DsdlEngine{

	class IMainGame;
	class IScene;

	class SceneManager{

	public:
		SceneManager(IMainGame* game);
		~SceneManager();

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
	};
}
#endif