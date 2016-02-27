
#include "FileIO.h"

#include <sys/stat.h>

#include <fstream>

namespace DsdlEngine{
	/*
	Create As Singleton
	*/
	static FileIO* Instance = nullptr;

	FileIO* FileIO::getInstance(){
		if (!Instance){
			Instance = new FileIO();
		}
		return Instance;
	}


	inline bool fileExists(const std::string name) {
		std::ifstream f(name);
		if (f.good()) {
			f.close();
			return true;
		}
		else {
			f.close();

			return false;
		}
	}

	bool FileIO::fileExists2(const std::string& name) {
		struct stat buffer;
		return (stat(name.c_str(), &buffer) == 0);
	}

	std::string FileIO::getSuitableFOpen(const std::string& filenameUtf8) const{
		return filenameUtf8;
	}


	std::string FileIO::getWritablePath() const{
		std::string path;
#ifdef __WIN32__
		path = "../../assets/";
#endif
#ifdef __ANDROID__
		path = "assets/";
#endif
		return path;
	}


	/*
		Loads complete file into memory
	*/
	bool FileIO::loadDocument(const char* filepath, char** doc_contents) {

//		const char* path;
		SDL_RWops *file;

		file = SDL_RWFromFile(filepath, "rb");

		size_t file_length = SDL_RWseek(file, 0, SEEK_END);
		(*doc_contents) = new char[file_length + 1]; // allow an extra character for '\0'

		SDL_RWseek(file, 0, SEEK_SET);
		int n_blocks = SDL_RWread(file, (*doc_contents), 1, file_length);

		SDL_RWclose(file);

		(*doc_contents)[file_length] = '\0';

		return true;
	}


	bool FileIO::writeDocument(const char* filepath, char** doc_contents) {
		//const char* path;
		SDL_RWops *file;

		file = SDL_RWFromFile(filepath, "r+w");

		//Sint64 file_length = SDL_RWseek(file, 0, SEEK_END);
		//(*doc_contents) = new char[file_length + 1]; // allow an extra character for '\0'
		size_t file_length = SDL_strlen(*doc_contents);

		SDL_RWseek(file, 0, SEEK_SET);
		int n_blocks = SDL_RWwrite(file, (*doc_contents), 1, file_length);

		SDL_Log("Wrote %d bytes : ", n_blocks);

		SDL_RWclose(file);

		//(*doc_contents)[file_length] = '\0';

		return true;

	}
}