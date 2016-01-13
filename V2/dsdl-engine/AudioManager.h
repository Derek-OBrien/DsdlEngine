
#ifndef _AUDIOMANAGER_
#define _AUDIOMANAGER_

#include "EngineDefines.h"
#include <SDL_mixer.h>

namespace DsdlEngine{
	class AudioManager{
	public:
		static AudioManager* getInstance();

		bool audioLoad(std::string audio, audio_type type);

		bool audioLoadBg(std::string audioPath, Mix_Music * aduio);

		void audioPlayBG();
		void audioPlaySFX(std::string audioPath);

		void audioPauseBG(){ Mix_PauseMusic(); };
		void audioResumeBG(){ Mix_ResumeMusic(); };
		void audioStopBG(){ Mix_HaltMusic(); };

	private:

		AudioManager();
		~AudioManager(){};
		
		Mix_Music* m_pBGAudio;
		Mix_Chunk* m_pSFXAudio;
		
	};
}

#endif