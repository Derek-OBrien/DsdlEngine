#include "EngineMaster.h"
#include "FileIO.h"
#include "XmlLocalStorage.h"

namespace DsdlEngine {

	using namespace tinyxml2;
	using namespace std;

	string EngineMaster::_filePath;
	bool EngineMaster::_isFilePathInitialized = false;



	/*
		Create As Singleton
	*/
	static EngineMaster* Instance = nullptr;
	EngineMaster* EngineMaster::getInstance() {
		if (!Instance) {
			Instance = new (std::nothrow) EngineMaster();
		}
		return Instance;
	}


	void EngineMaster::initXMLFilePath() {
		if (!_isFilePathInitialized) {
			_filePath += FileIO::getInstance()->getWritablePath() + XML_FILE;
			_isFilePathInitialized = true;
		}
	}

	const string EngineMaster::getXMLFilePath() { return _filePath; }

	bool EngineMaster::isXMLFileExist() {
		return FileIO::getInstance()->fileExists2(_filePath);
	}
}