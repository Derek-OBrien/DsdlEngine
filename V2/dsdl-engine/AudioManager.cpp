
#include "AudioManager.h"

namespace DsdlEngine{

	//init audio manager
	void AudioManager::init(){

		if (Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG) == -1) {
			DEBUG_MSG("Mix_Init error: " + std::string(Mix_GetError()));
		}

		if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
			DEBUG_MSG("Mix_OpenAudio error: " + std::string(Mix_GetError()));
		}

		m_bisInitialized = true;
	}

	void AudioManager::destroy(){
		if (m_bisInitialized)
			m_bisInitialized = false;

		for (auto& it : m_sfxAudioMap){
			Mix_FreeChunk(it.second);
		}

		for (auto& it : m_bgAudioMap){
			Mix_FreeMusic(it.second);
		}

		m_bgAudioMap.clear();
		m_sfxAudioMap.clear();

		Mix_CloseAudio();
		Mix_Quit();
	}

	//Play sound effect
	void SFX::play(int loop) {
		if (Mix_PlayChannel(-1, m_Chunk, loop) == -1) {
			if (Mix_PlayChannel(0, m_Chunk, loop) == -1) {
				DEBUG_MSG("Mix_PlayChannel error: " + std::string(Mix_GetError()));
			}
		}
	}

	//load sound effect
	SFX AudioManager::loadSFX(std::string audioPath){
		//Load SFX music (Mix_Chunk)
		SFX sfx;
		Mix_Chunk* sfxChunk = nullptr;
		//Check if allready cached
		auto it = m_sfxAudioMap.find(audioPath);

		//Not cached so load and cahe it
		if (it == m_sfxAudioMap.end()){
			if ((sfxChunk = Mix_LoadWAV(audioPath.c_str())) == NULL){
				DEBUG_MSG("Mix_LoadWAV: Failed to load Audio" + std::string(Mix_GetError()));
			}
			sfx.m_Chunk = sfxChunk;
			m_sfxAudioMap[audioPath] = sfxChunk;
		}
		//it is cached 
		else{
			sfx.m_Chunk = it->second;
		}
		return sfx;
	}

	//load music
	Music AudioManager::loadMusic(std::string audioPath){
		//Check if allready cached
		auto it = m_bgAudioMap.find(audioPath);

		Music music;
		Mix_Music* mix = nullptr;
		//Not cached so load and cahe it
		if (it == m_bgAudioMap.end()){
			if ((mix = Mix_LoadMUS(audioPath.c_str())) == NULL){
				DEBUG_MSG("Mix_LoadMUS: Failed to load Audio" + std::string(Mix_GetError()));
			}
			music.m_Music = mix;
			m_bgAudioMap[audioPath] = mix;
		}
		//it is cached 
		else{
			music.m_Music = it->second;
		}
		return music;
	}
}

