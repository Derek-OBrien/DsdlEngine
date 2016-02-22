#include "EngineMaster.h"
#include "FileIO.h"

#include "../dependencies/tinyxml/tinyxml2.h"


namespace DsdlEngine{


#define DEFAULT_ROOT_NAME "DefaultRoot"
#define XML_FILE "Default.xml"


	using namespace tinyxml2;
	using namespace std;
	
	string EngineMaster::_filePath;
	bool EngineMaster::_isFilePathInitialized = false;

	

	/*
		Create As Singleton
	*/
	static EngineMaster* Instance = nullptr;
	EngineMaster* EngineMaster::getInstance(){
		if (!Instance){
			//Init Xml File Path
			initXMLFilePath();
			DEBUG_MSG(getXMLFilePath());
			//Check if file allready exists
			if ((!isXMLFileExist()) && (!createXMLFile())){
				return nullptr;
			}

			Instance = new (std::nothrow) EngineMaster();

		}
		return Instance;
	}



	bool loadDoucument(const char* filepath, char** doc_contents) {
		
		const char* path;
		SDL_RWops *file;

#ifdef __WIN32__
		path = "../../assets/Default.xml";
//		file = SDL_RWFromFile(path, "r+w");
#endif
#ifdef __ANDROID__
		path = "Default.xml";
		
//		file = SDL_RWFromFile(path, "r+w");
#endif

		file = SDL_RWFromFile(path, "r+w");

		Sint64 file_length = SDL_RWseek(file, 0, SEEK_END);
		(*doc_contents) = new char[file_length + 1]; // allow an extra character for '\0'

		SDL_RWseek(file, 0, SEEK_SET);
		int n_blocks = SDL_RWread(file, (*doc_contents), 1, file_length);

		SDL_RWclose(file);

		(*doc_contents)[file_length] = '\0';

		return true;
	}


	XMLElement* EngineMaster::getXMLNodeForKey(const char*pKey, XMLElement** rootNode, XMLDocument** doc){

		XMLElement* curNode = nullptr;

		char* contents = NULL;

		//Check the key
		if (! pKey){
			return nullptr;
		}

		if (loadDoucument("../../assets/Default.xml", &contents) != true) {

			SDL_Log("can not read xml file using SDL_rwops");
		}

		//SDL_Log(contents);

		//do{

			//*doc = xmlDoc;
/*
			std::string path;
			SDL_RWops *file;
#ifdef __WIN32__
			path = "../../assets/Default.xml";
#endif
#ifdef __ANDROID__
			path = "assets/Default.xml";
			// Open the file
			file = SDL_RWFromFile(path, "r");
#endif
			std::string xmlBuffer = path;//FileIO::getInstance()->getSuitableFOpen(getXMLFilePath());//"../../assets/Default.xml";
			
			if (xmlBuffer.empty()){
				SDL_Log("can not read xml file");
				break;
			}
*/

			//std::string path;
			//std::string xmlBuffer = path;//FileIO::getInstance()->getSuitableFOpen(getXMLFilePath());//"../../assets/Default.xml";

			//xmlDoc = loadDoucument(path.c_str(), doc );

			XMLDocument* xmlDoc = new XMLDocument;

			if (xmlDoc->Parse(contents) == XML_SUCCESS){
				SDL_Log("Doc Loaded from contents");

				if (xmlDoc->Parse(contents) == XML_SUCCESS) {
					SDL_Log("Doc Parsed");
					// get root node
					*rootNode = xmlDoc->RootElement();

					//*rootNode = xmlDoc->FirstChildElement();
					if (nullptr == *rootNode) {
						SDL_Log("read root node error ");
					//	break;
					}

					// find the node
					curNode = (*rootNode)->FirstChildElement();
					while (curNode != nullptr)
					{
						const char* nodeName = curNode->Value();
						if (!strcmp(nodeName, pKey))
						{
							break;
						}

						curNode = curNode->NextSiblingElement();
					}
				}
			}
			else{
				SDL_Log("Could not load doc: ");
			}
		//} while (0);
			delete[] contents;

		return curNode;
	}



	void EngineMaster::setValueForKey(const char* value, const char* key){
	
		XMLElement* rootNode;
		XMLDocument* doc;
		XMLElement* node;

		if (!key || !value){
			return;
		}

		//find node
		node = getXMLNodeForKey(key, &rootNode, &doc);

		//change node if exists
		if (node){
			if (node->FirstChild()){
				node->FirstChild()->SetValue(value);
			}
			else{
				XMLText* content = doc->NewText(value);
				node->LinkEndChild(content);
			}
		}
		else{
			if (rootNode){
				XMLElement* temp = doc->NewElement(key);
				rootNode->LinkEndChild(temp);
				XMLText* content = doc->NewText(value);
				temp->LinkEndChild(content);
			}
		}

		//save doc
		if (doc){
			std::string path;
#ifdef __WIN32__
			path = "../../assets/Default.xml";
#endif
#ifdef __ANDROID__
			path = "assets/Default.xml";
#endif
			doc->SaveFile(path.c_str());
		}
	}

	/*static const char* findNode(XMLElement* node){
		const char* value = nullptr;
		if (node && node->FirstChild()){
			value = (const char*)(node->FirstChild()->Value());
		}
		return value;
	}*/

	static void delDoc(XMLDocument* d){ 
		if (d){
			delete d;
		}
	 }


	int EngineMaster::getIntegerForKey(const char* key){
		
		const char* value = nullptr;
		tinyxml2::XMLElement* rootNode;
		tinyxml2::XMLDocument* doc;
		tinyxml2::XMLElement* node;

		node = getXMLNodeForKey(key, &rootNode, &doc);

		// find the node
		if (node && node->FirstChild()){
			value = (const char*)(node->FirstChild()->Value());
		}

		int ret = 0;

		if (value){
			ret = atoi(value);
		}
		/**
		if (doc){
			delete doc;
		}*/


		return ret;
	}


	bool EngineMaster::getBoolForKey(const char* key){ return true; };
	double EngineMaster::getDoubleForKey(const char* key) { return 0.0; };
	float EngineMaster::getFloatForKey(const char* key){ return 0.0; };
	string EngineMaster::getStringForKey(const char* key) { return "helloE"; };


	void EngineMaster::setIntegerForKey(int value, const char* key){
		// check key
		if (!key)
		{
			return;
		}

		// format the value
		char tmp[50];
		memset(tmp, 0, 50);
#ifdef __WIN32__
		sprintf_s(tmp, "%d", value);
#endif

#ifdef __ANDROID__
		std::sprintf(tmp, "%d", value);
#endif

		setValueForKey(tmp, key);

	}

	void EngineMaster::setBoolForKey(bool value, const char* key){}
	void EngineMaster::setDoubleForKey(double value, const char* key){}
	void EngineMaster::setFloatForKey(float value, const char* key){}
	void EngineMaster::setStringForKey(std::string value, const char* key){}



	void EngineMaster::deleteValueForKey(const char* key){
		tinyxml2::XMLElement* rootNode;
		tinyxml2::XMLDocument* doc;
		tinyxml2::XMLElement* node;

		// check the params
		if (! key)
		{
			DEBUG_MSG("the key is invalid");
			return;
		}

		// find the node
		node = getXMLNodeForKey(key, &rootNode, &doc);

		// if node not exist, don't need to delete
		if (!node)
		{
			return;
		}

		// save file and free doc
		if (doc)
		{
			doc->DeleteNode(node);
			std::string path;
#ifdef __WIN32__
			path = "../../assets/Default.xml";
#endif
#ifdef __ANDROID__
			path = "assets/Default.xml";
#endif
			doc->SaveFile(path.c_str());
			delete doc;
		}

		//flush();
	}


	bool EngineMaster::createXMLFile(){
		bool bRet = false;

		XMLDocument *pDoc = new XMLDocument();
		if (nullptr == pDoc){
			return false;
		}

		XMLDeclaration *pDeclaration = pDoc->NewDeclaration(nullptr);
		if (nullptr == pDeclaration){
			return false;
		}
		
		pDoc->LinkEndChild(pDeclaration);
		XMLElement *pRootEle = pDoc->NewElement(DEFAULT_ROOT_NAME);
		if (nullptr == pRootEle){
			return false;
		}
		
		pDoc->LinkEndChild(pRootEle);

		std::string path;
#ifdef __WIN32__
		path = "../../assets/Default.xml";
#endif
#ifdef __ANDROID__
		path = "assets/Default.xml";
#endif
		
		bRet = XML_SUCCESS == pDoc->SaveFile(FileIO::getInstance()->getSuitableFOpen(path).c_str());
		DEBUG_MSG("XML File Created");

		if (pDoc){
			delete pDoc;
		}

		return bRet;
	}





	void EngineMaster::initXMLFilePath(){
		if (!_isFilePathInitialized){
			_filePath += FileIO::getInstance()->getWritablePath() + XML_FILE;
			_isFilePathInitialized = true;
		}
	}

	const string EngineMaster::getXMLFilePath(){ return _filePath; }

	bool EngineMaster::isXMLFileExist(){
		return FileIO::getInstance()->fileExists2(_filePath);
	}
}