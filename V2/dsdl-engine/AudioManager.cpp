#include "AudioManager.h"
#include "FileIO.h"

/**
*	@author Derek O Brien
*/
namespace DsdlEngine {

	//init audio manager
	void AudioManager::init() {
		//init audio
		if (Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG) == -1) {
			SDL_Log("Mix_Init error: %s " ,Mix_GetError());
		}
		//open audio defaults
		if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 2048) == -1) {
			SDL_Log("Mix_OpenAudio error: %s " ,Mix_GetError());
		}

		m_bisInitialized = true;
	}

	//Clean Up Aduio
	void AudioManager::destroy() {
		if (m_bisInitialized)
			m_bisInitialized = false;

		//Loop Through maps and free audio
		for (auto& it : m_sfxAudioMap) {
			Mix_FreeChunk(it.second);
		}

		for (auto& it : m_bgAudioMap) {
			Mix_FreeMusic(it.second);
		}
		//Clear maps
		m_bgAudioMap.clear();
		m_sfxAudioMap.clear();

		//Close and Quit Audio
		Mix_CloseAudio();
		Mix_Quit();
	}

	//Play sound effect
	void SFX::play(int loop) {
		if (Mix_PlayChannel(-1, m_Chunk, loop) == -1) {
			if (Mix_PlayChannel(0, m_Chunk, loop) == -1) {
			SDL_Log("Mix_PlayChannel error: %s", Mix_GetError());
			}
		}
	}

	//Load Sound effect file
	//@parma : string audioPath ( path to file)
	SFX AudioManager::loadSFX(std::string audioPath) {

		std::string temp;
		temp = FileIO::getInstance()->getWritablePath() + audioPath;


		//Load SFX music (Mix_Chunk)
		SFX sfx;
		Mix_Chunk* sfxChunk = nullptr;

		//Check if allready cached
		auto it = m_sfxAudioMap.find(temp);

		//Not cached so load and cahe it
		if (it == m_sfxAudioMap.end()) {
			if ((sfxChunk = Mix_LoadWAV(temp.c_str())) == NULL) {
				SDL_Log("Mix_LoadWAV: Failed to load Audio %s", Mix_GetError());
			}
			sfx.m_Chunk = sfxChunk;
			m_sfxAudioMap[temp] = sfxChunk;
		}
		//it is cached 
		else {
			sfx.m_Chunk = it->second;
		}
		return sfx;
	}


	//Load Music file
	//@parma : string audioPath ( path to file)
	Music AudioManager::loadMusic(std::string audioPath) {

		std::string temp;
		temp = FileIO::getInstance()->getWritablePath() + audioPath;


		//Check if allready cached
		auto it = m_bgAudioMap.find(temp);

		Music music;
		Mix_Music* mix = nullptr;
		//Not cached so load and cahe it
		if (it == m_bgAudioMap.end()) {
			if ((mix = Mix_LoadMUS(temp.c_str())) == NULL) {
				SDL_Log("Mix_LoadMUS: Failed to load Audio %s", Mix_GetError());
			}
			music.m_Music = mix;
			m_bgAudioMap[temp] = mix;
		}
		//it is cached 
		else {
			music.m_Music = it->second;
		}
		return music;
	}
}

