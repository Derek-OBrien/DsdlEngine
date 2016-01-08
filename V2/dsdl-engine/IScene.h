#ifndef _ISCENE_
#define _ISCENE_

#define SCENE_INDEX_NO_SCENE -1

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
		friend class SceneManager;

		IScene(){};
		virtual ~IScene(){};

		virtual int getNextSceneIndex() const = 0;
		virtual int getPreviousSceneIndex() const = 0;

		virtual void buildScene() = 0;
		virtual void destroyScene() = 0;

		virtual void onEntryScene() = 0;
		virtual void onExitScene() = 0;

		virtual void updateScene() = 0;
		virtual void drawScene() = 0;

		int getSceneIndex() const{ return m_iSceneIndex; }

		SceneState getSceneState() const { return m_eCurrentState; }
		void setParentGame(IMainGame* game){ m_pGame = game; }
		void setSceneRunning(){ m_eCurrentState = SceneState::RUNNING; }

	protected:
		SceneState m_eCurrentState = SceneState::NONE;
		IMainGame* m_pGame = nullptr;


		int m_iSceneIndex = SCENE_INDEX_NO_SCENE;

	};
}


#endif