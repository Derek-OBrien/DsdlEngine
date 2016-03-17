
#include "FileIO.h"

#include <sys/stat.h>

#include <fstream>

using namespace tinyxml2;
using namespace std;

namespace DsdlEngine{
	/*
	Create As Singleton
	*/
	static FileIO* Instance = nullptr;

	FileIO* FileIO::getInstance(){
		if (!Instance){
			Instance = new (std::nothrow) FileIO();
		}
		return Instance;
	}


	/*
		Check if file exists first
	*/
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


	/*
		Get Path to file

		if defs here for different platfoms as windows needs to find assets in root folder which i have created
		but android needs to find assets in the jni/assets folder. android is allready set up to go look in this folder 
		there for all that was needed was the name and in the windows platfom i add on path to the assets folder so it just has to look for name of file

		this will need to be done to each asset type loding function eg. audio, fonts, images
	*/

	std::string FileIO::getWritablePath(){
		//std::string path;

#ifdef __WIN32__
		//path = "../../assets/";
		m_path;
#endif

#ifdef __ANDROID__
		SDL_Log("Setting Path to assets folder");
		m_path = "";
		SDL_Log("Path is Set %s", m_path.c_str());
#endif
		return m_path;
	}


	/*
		Loads complete file into memory
	*/
	bool FileIO::loadDocument(const char* filepath, char** doc_contents) {

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

	/*
		Write contents of buffer to file and save.
	*/

	bool FileIO::writeDocument(const char* filepath, const char** doc_contents) {

		SDL_RWops *file;

		//Open file
		file = SDL_RWFromFile(filepath, "w");

		//Length of data to write	
		size_t len = SDL_strlen(*doc_contents);
		
		//Write the data
		SDL_RWwrite(file, *doc_contents, 1, len);
		
		//close file
		SDL_RWclose(file);

		return true;

	}


	/*

	Parse Xml for Element for Key and return Element node if found

	*/
	XMLElement* FileIO::getXMLNodeForKey(const char*pKey, XMLElement** rootNode, XMLDocument** doc) {

		XMLElement* curNode = nullptr;

		char* contents = NULL;
		std::string path;

/*#ifdef __WIN32__
		//path = "../../assets/Default.xml";
		path = m_path + "Default.xml";
#endif
#ifdef __ANDROID__
		path = "Default.xml";
#endif*/

		SDL_Log("Setting path to contain file name");
		path = getWritablePath() + "Default.xml";
		SDL_Log("Path is Set %s", path.c_str());

		//Check the key
		if (!pKey) {
			return nullptr;
		}

		//Load Xml document into contents char
		if (FileIO::getInstance()->loadDocument(path.c_str(), &contents) != true) {
			SDL_Log("can not read xml file using SDL_rwops");
		}

		//SDL_Log(contents);

		XMLDocument* xmlDoc = new XMLDocument;
		*doc = xmlDoc;

		if (xmlDoc->Parse(contents) == XML_SUCCESS) {
			SDL_Log("Doc Parsed");
			// get root node
			*rootNode = xmlDoc->RootElement();

			if (nullptr == *rootNode) {
				SDL_Log("read root node error ");
			}

			// find the node
			curNode = (*rootNode)->FirstChildElement();
			while (curNode != nullptr)
			{
				const char* nodeName = curNode->Value();
				if (!strcmp(nodeName, pKey)) {
					break;
				}
				curNode = curNode->NextSiblingElement();
			}
		}
		else {
			SDL_Log("Could not load doc: ");
		}

		delete[] contents;

		return curNode;
	}


	/*
		Set Value for key in xml file
		@parma key = name of node to be written to file
		@parma vale = vale of node to be saved
	*/
	void FileIO::setValueForKey(const char* value, const char* key) {

		XMLElement* rootNode;
		XMLDocument* doc;
		XMLElement* node;
		XMLPrinter printer;
		std::string path;


		if (!key || !value) {
			return;
		}

/**
#ifdef __WIN32__
		path = "../../assets/Default.xml";
#endif
#ifdef __ANDROID__
		path = "Default.xml";
#endif
*/

		path = getWritablePath() + "Default.xml";

		//Check if node exists allready
		node = getXMLNodeForKey(key, &rootNode, &doc);

		//if node allready exists change value
		if (node) {
			if (node->FirstChild()) {
				node->FirstChild()->SetValue(value);
			}
			else {
				XMLText* content = doc->NewText(value);
				node->LinkEndChild(content);
			}
		}//Create new node and set value
		else {
			if (rootNode) {
				XMLElement* temp = doc->NewElement(key);
				rootNode->LinkEndChild(temp);
				XMLText* content = doc->NewText(value);
				temp->LinkEndChild(content);
			}
		}

		// attach printer to the document you want to convert in to a std::string 
		doc->Accept(&printer);

		// Create a std::string and copy your document data in to the string    
		const char* buffer = printer.CStr();

		//Write back to file and save file
		if (FileIO::getInstance()->writeDocument(path.c_str(), &buffer)) {
			SDL_Log("Key : %s :: Value : %s :: saved", key, value);
		}
		delete doc;
	}


	bool FileIO::createXMLFile() {
		bool bRet = false;

		XMLPrinter printer;

		XMLDocument *doc = new XMLDocument();
		if (nullptr == doc) {
			return false;
		}

		XMLDeclaration *pDeclaration = doc->NewDeclaration(nullptr);
		if (nullptr == pDeclaration) {
			return false;
		}

		doc->LinkEndChild(pDeclaration);
		XMLElement *pRootEle = doc->NewElement(DEFAULT_ROOT_NAME);
		if (nullptr == pRootEle) {
			return false;
		}

		doc->LinkEndChild(pRootEle);

		std::string path;
/*#ifdef __WIN32__
		path = "../../assets/Default.xml";
#endif
#ifdef __ANDROID__
		path = "assets/Default.xml";
#endif*/
		path = getWritablePath() + "Default.xml";


		bRet = XML_SUCCESS == doc->SaveFile(FileIO::getInstance()->getSuitableFOpen(path).c_str());
		DEBUG_MSG("XML File Created");

		// attach printer to the document you want to convert in to a std::string 
		//doc->Accept(&printer);

		// Create a std::string and copy your document data in to the string    
		//const char* buffer = printer.CStr();

		//Write back to file and save file
		//if (FileIO::getInstance()->writeDocument(path.c_str(), &buffer)) {
		//	bRet = true;
		//}

		if (doc) delete doc;

		return bRet;
	}

}