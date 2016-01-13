
#include "AudioManager.h"

namespace DsdlEngine{


	static AudioManager* instance = 0;
	AudioManager* AudioManager::getInstance(){
		if (instance == 0)
			instance = new AudioManager();

		return instance;
	}

	AudioManager::AudioManager(){
		Mix_OpenAudio(22050, AUDIO_S16, 2, (4096 / 2));
	}

	bool AudioManager::audioLoad(std::string audio, audio_type type){
	
		if (type == BG_){
			//Load Bg music (Mix_Music)
			if ((m_pBGAudio = Mix_LoadMUS(audio.c_str()) )== NULL){
				DEBUG_MSG("Failed to load Audio" , Mix_GetError());
				return false;
			}
		}
		else if (type == SFX_){
			//Load SFX music (Mix_Chunk)
			if ((m_pSFXAudio = Mix_LoadWAV(audio.c_str())) == NULL){
				DEBUG_MSG("Failed to load Audio", Mix_GetError());
				return false;
			}
		}
		return true;
	}

	
	void AudioManager::audioPlayBG(){
		if (Mix_PlayingMusic() == 0){
			Mix_PlayMusic(m_pBGAudio, -1);
		}
		else{
			if (Mix_PausedMusic() == 1){
				audioResumeBG();
			}
			else{
				audioPauseBG();
			}
		}
	}


	void AudioManager::audioPlaySFX(std::string audioPath){
		//loadaudio first
		audioLoad(audioPath, SFX_);
		Mix_PlayChannel(-1, m_pSFXAudio, 0);
	}
}

