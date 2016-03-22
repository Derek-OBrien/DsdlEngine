
#include "AudioManager.h"
#include "FileIO.h"

namespace DsdlEngine {

	//init audio manager
	void AudioManager::init() {

		if (Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG) == -1) {
			DEBUG_MSG("Mix_Init error: " + std::string(Mix_GetError()));
		}

		if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
			DEBUG_MSG("Mix_OpenAudio error: " + std::string(Mix_GetError()));
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
				DEBUG_MSG("Mix_PlayChannel error: " + std::string(Mix_GetError()));
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
				DEBUG_MSG("Mix_LoadWAV: Failed to load Audio" + std::string(Mix_GetError()));
				SDL_Log("Failed to load Audio Wav");
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
				DEBUG_MSG("Mix_LoadMUS: Failed to load Audio" + std::string(Mix_GetError()));
				SDL_Log("Failed to load Audio");
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

