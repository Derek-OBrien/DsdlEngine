#ifndef _ENGINEMASTER_
#define _ENGINEMASTER_

#include "EngineDefines.h"
#include "../dependencies/tinyxml/tinyxml2.h"
#include "EngineMath.h"

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


#endif