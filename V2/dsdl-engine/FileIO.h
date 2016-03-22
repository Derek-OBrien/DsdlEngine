#ifndef _FILEIO_
#define _FILEIO_
#include "EngineDefines.h"
#include <sys/stat.h>

#include "../dependencies/tinyxml/tinyxml2.h"


namespace DsdlEngine{

	using namespace tinyxml2;
	using namespace std;

	class FileIO{

	public:
		static FileIO* getInstance();


		bool fileExists2(const std::string& name);
		std::string getSuitableFOpen(const std::string& filenameUtf8) const;

		/*
			Get and Set Asset Storage path
		*/
		std::string getWritablePath();
		void setAssetsPath(  std::string assetsPath)  { m_path = assetsPath; }


		/*
			Get and set file to open { For Xml only }
		*/
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