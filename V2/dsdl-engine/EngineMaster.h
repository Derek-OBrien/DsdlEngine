#ifndef _ENGINEMASTER_
#define _ENGINEMASTER_
/*
	Author:: Derek O Brien K00105572
	File:: EngineMaster
	Description:: Engine master class is a singleton helper class
*/

#include "EngineDefines.h"
#include "../dependencies/tinyxml/tinyxml2.h"

namespace DsdlEngine{

	class EngineMaster{
	public:

		/**
		*	Returns the singleton.
		*/
		static EngineMaster* getInstance();

		void setAssetsPath(std::string s){ rootAssetsPath = s; };
		std::string getAssetsPath(){ return rootAssetsPath;  };

	protected:
		EngineMaster(){};
		virtual ~EngineMaster(){};

	private:


		static bool isXMLFileExist();
		static void initXMLFilePath();
		static const std::string getXMLFilePath();

		
		static std::string _filePath;
		static bool _isFilePathInitialized;


		std::string rootAssetsPath;
		int windowHeight;
		int windowWidth;
	//	Size windowSize;
	};
}


#endif // !_ENGINEMASTER_