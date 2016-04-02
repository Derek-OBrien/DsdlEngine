#ifndef _FILEIO_
#define _FILEIO_

#include "EngineDefines.h"
#include <sys/stat.h>
#include "../dependencies/tinyxml/tinyxml2.h"
/**
*	@author Derek O Brien
*/

namespace DsdlEngine{

	///Using external Namespace
	using namespace tinyxml2;
	using namespace std;
	
	/**
	*	FileIO class handles open and cllosing of xml files in the framework. 
	*	Handles XML parsing and Saveing
	*/
	class FileIO{

	public:
		/**
		*	getInstance, Creates FileIO as a static singleton
		*	@return instance of FileIO 
		*/
		static FileIO* getInstance();
		
		/**
		*	getSuitableFopen, the the filename of the path to open
		*	@parma std::string file path.
		*	@return std::string file path to open.
		*/
		std::string getSuitableFOpen(const std::string& filenameUtf8) const;

		/**
		*	getWriteablePath, get the full path to the file.
		*	@return std::string.
		*/
		std::string getWritablePath();

		/**
		*	setAssetsPath, set the path to the file root ( only applies to windows platform)
		*	@parma std::string path for file.
		*/
		void setAssetsPath(  std::string assetsPath)  { m_path = assetsPath; }


		/**
		*	getFileToOpen, get the name of teh file to open.
		*	@return std::string filename.
		*/
		std::string getFileToOpen() { return m_fileName; }

		/**
		*	setFileToOpen, set the name of the file to open.
		*	@parma std::string file name.
		*/
		void setFileToOpen(std::string file) { m_fileName = file; }

		/**
		*	loadDocument, load the contents of a file into memory for parsing,
		*	@parma filepath const char path to file,
		*	@parma doc_contents buffer to hold the file contents.
		*	@return bool.
		*/
		bool loadDocument(const char* filepath, char** doc_contents);
	
		/**
		*	writeDocument. Write the file contents from memory buffer to file and save.
		*	@parma filepath const char path to file,
		*	@parma doc_contents buffer cotaining the file contents.
		*	@return bool.
		*/
		bool writeDocument(const char* filepath, const char** doc_contents);

		/**
		*	getXMLNodeForKey, parses the file contents in the memory buffer for a xml element that matches the key.
		*	@parma pKey key to search for in the file.
		*	@parma rootNode XML node to use for search.
		*	@parma doc XML doc to hold the contents.
		*	@return XMLElement the element matching the key.
		*/
		XMLElement* getXMLNodeForKey(const char*pKey, XMLElement** rootNode, XMLDocument** doc);

		/**
		*	setValueForKey, Set or update the value of an XML element that matches the key.
		*	@parma vlaue the value to be set.
		*	@parma key the key to look for.
		*/
		void setValueForKey(const char* value, const char* key);

		/**
		*	createXMLFile, Create a new Xml file.
		*	@return bool 1 on success.
		*/
		bool createXMLFile();

	protected:
		/**
		*	Constructor
		*/
		FileIO(){};

		/**
		*	Deconstructor
		*/
		virtual ~FileIO(){};

	private:

		std::string m_path;			/**< path to folder which contains file*/
		std::string m_fileName;		/**< name of xml file to load*/

	};
}

#endif // !_FILEIO_