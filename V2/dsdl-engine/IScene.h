/*
	Base Scene Class

*/

#ifndef _ISCENE_
#define _ISCENE_

#define SCENE_INDEX_NO_SCENE -1

#include "EngineBaseNode.h"
#include "Sprite.h"

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

		virtual void destroyScene() = 0;

		virtual void onEntryScene() = 0;
		virtual void onExitScene() = 0;

		virtual void updateScene() = 0;
		
		//Add node as child of scene
		void addChild(EngineBaseNode* node, int zOrder) {
				sceneChildren.push_back(node);
		}


		int getSceneIndex() const{ return m_iSceneIndex; }
		SceneState getSceneState() const { return m_eCurrentState; }
		void setSceneRunning(){ m_eCurrentState = SceneState::RUNNING; }

		//Vector to hold game nodes
		std::vector<EngineBaseNode*> sceneChildren;

	protected:

		SceneState m_eCurrentState;// = SceneState::NONE;
		int m_iSceneIndex;// = SCENE_INDEX_NO_SCENE;
	};
}


#endif