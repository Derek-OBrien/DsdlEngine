
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
		return "../../assets/";
	}
}