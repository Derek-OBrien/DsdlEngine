#ifndef _AUDIOMANAGER_
#define _AUDIOMANAGER_

#include "EngineDefines.h"
/*
Author: Derek O Brien
File : AudioManager.h
Description: Engine Audio Manger handles loading, playing and stoping of audio files
*/
//Name Space Wrapper
namespace DsdlEngine {

	/**
	*	Sound effect class for interfacing with SDL Mix_Chunk.
	*/
	class SFX {
	public:
		
		/**
		*	Friend Class Audio Manager.
		*/
		friend class AudioManager;

		/**
		*	Paly sound effect.
		*	@param int loops == -1 : loop forever, 0 : loop once, 1+ : loop that many times
		*/
		void play(int loop = 0);
	private:
		/**
		*	Private Mix_Chunk Variable
		*/
		Mix_Chunk* m_Chunk;
	};

	/**
	*	Music class for interfacing with SDL Mix_Music.
	*/
	class Music {
	public:
		/**
		*	Friend Class Audio Manager.
		*/
		friend class AudioManager;

		/**
		*	Play Music.
		*	@param loops == -1 : loop forever, 0 : loop once, 1+ : loop that many times
		*/
		void play(int loop = -1) { Mix_PlayMusic(m_Music, loop); };
		
		/**
		*	Pause Music currently playeing.
		*/
		void audioPauseBG() { Mix_PauseMusic(); };

		/**
		*	Resume Music that is currently paused.
		*/
		void audioResumeBG() { Mix_ResumeMusic(); };

		/**
		*	Stop Music that is currently playing.
		*/
		void audioStopBG() { Mix_HaltMusic(); };

	private:

		/**
		*	Private Mix_Music Variable
		*/
		Mix_Music* m_Music;
	};


	/**
	*	AudioManager Class.
	*	The AudioManager Class is responsable for loading and playing of audio within a game.
	*	The AudioManager will also cache any loaded audio.
	*/
	class AudioManager {
	public:
		/**
		*	AudioManager Constructor.
		*	On call will init the AudioManager.
		*/
		AudioManager() { init(); };

		/**
		*	AudioManager Deconstructor.
		*	On call will destroy current copy of the AudioManager and clear current cache
		*/
		~AudioManager() { destroy(); };

		/**
		*	init SDL Audio and set up Audio channels and frequency.
		*	Automaticaly called by Constructor.
		*/
		void init();

		/**
		*	Destroy current copy of AudioManager and clear cache maps.
		*/
		void destroy();

		/**
		*	Load Sound effect.
		*	@param std::string for path to audio. 
		*	@return SFX chunk to play.
		*/
		SFX loadSFX(std::string audioPath);

		/**
		*	Load Music.
		*	@param std::string for path to audio.
		*	@return Music to play.
		*/
		Music loadMusic(std::string audioPath);

	private:
		/**
		*	Private cache map for storing sound effects.
		*/
		std::map<std::string, Mix_Chunk*> m_sfxAudioMap;

		/**
		*	Private cache map for storing musics.
		*/
		std::map<std::string, Mix_Music*> m_bgAudioMap;

		/**
		*	Private bool for control loading.
		*/
		bool m_bisInitialized;
	};
}

#endif