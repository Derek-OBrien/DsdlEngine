#include "SceneManager.h"
#include "IScene.h"


namespace DsdlEngine{

	SceneManager::SceneManager(IMainGame* game) : 
		m_pGame(game){
		//Empty
	}

	//Move to next scene
	IScene* SceneManager::moveNext(){
		IScene* currentScene = getCurrentScene();
		if (currentScene->getNextSceneIndex() != SCENE_INDEX_NO_SCENE){
			m_iCurrentSceneIndex = currentScene->getNextSceneIndex();
		}
		return getCurrentScene();
	}

	//Move to Previous Scene
	IScene* SceneManager::movePrevious(){
		IScene* currentScene = getCurrentScene();
		if (currentScene->getPreviousSceneIndex() != SCENE_INDEX_NO_SCENE){
			m_iCurrentSceneIndex = currentScene->getPreviousSceneIndex();
		}
		return getCurrentScene();
	}

	//Set Current scene
	void SceneManager::setScene(int nextScene){
		m_iCurrentSceneIndex = nextScene;
	}

	//Add a scene to game
	void SceneManager::addScene(IScene* newScene){
		newScene->m_iSceneIndex = m_pScenes.size();
		m_pScenes.push_back(newScene);
		newScene->setParentGame(m_pGame);
	}

	//Clean up scenes
	void SceneManager::destroy(){
		for (size_t i = 0; i < m_pScenes.size(); i++){
			m_pScenes[i]->destroyScene();
			delete m_pScenes[i];
		}
		m_pScenes.resize(0);
		m_iCurrentSceneIndex = SCENE_INDEX_NO_SCENE;
	}

	//Return the current scene
	IScene* SceneManager::getCurrentScene(){
		if (m_iCurrentSceneIndex == SCENE_INDEX_NO_SCENE) {
			return nullptr;
		}
		return m_pScenes[m_iCurrentSceneIndex];
	}

}