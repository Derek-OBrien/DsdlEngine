#ifndef _FILEIO_
#define _FILEIO_

#include "EngineDefines.h"
#include <sys/stat.h>
#include "../dependencies/tinyxml/tinyxml2.h"
/*
	File: FileIO
	Author: Derek O Brien
	Description: FileIO class handles open and cllosing of xml files in the framework. 
				Handles XML parsing and Saveing
*/

namespace DsdlEngine{

	//Using Namespace
	using namespace tinyxml2;
	using namespace std;

	class FileIO{

	public:

		//Create as static instance
		static FileIO* getInstance();
		
		//Check if file exists
		bool fileExists2(const std::string& name);
		std::string getSuitableFOpen(const std::string& filenameUtf8) const;

		
		//Get and Set Asset Storage path
		std::string getWritablePath();
		void setAssetsPath(  std::string assetsPath)  { m_path = assetsPath; }


		//Get and set file to open { For Xml only }
		std::string getFileToOpen() { return m_fileName; }
		void setFileToOpen(std::string file) { m_fileName = file; }

		//Load document into memory
		bool loadDocument(const char* filepath, char** doc_contents);
	
		//Write contents from memory to file
		bool writeDocument(const char* filepath, const char** doc_contents);

		//get xml node 
		XMLElement* getXMLNodeForKey(const char*pKey, XMLElement** rootNode, XMLDocument** doc);

		//set value for giving xml node
		void setValueForKey(const char* value, const char* key);

		//Create xml File
		bool createXMLFile();

	protected:

		FileIO(){};
		virtual ~FileIO(){};

	private:

		std::string m_path;		//path to folder which contains file
		std::string m_fileName;	//name of xml file to load

	};
}

#endif // !_FILEIO_