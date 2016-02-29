#include "EngineMaster.h"
#include "FileIO.h"


namespace DsdlEngine {


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
	EngineMaster* EngineMaster::getInstance() {
		if (!Instance) {
			//Init Xml File Path
			initXMLFilePath();
			DEBUG_MSG(getXMLFilePath());
			//Check if file allready exists
			if ((!isXMLFileExist()) && (!createXMLFile())) {
				return nullptr;
			}

			Instance = new (std::nothrow) EngineMaster();

		}
		return Instance;
	}



	/*
	
		Parse Xml for Element for Key and return Element node if found
	
	*/
	XMLElement* EngineMaster::getXMLNodeForKey(const char*pKey, XMLElement** rootNode, XMLDocument** doc) {

		XMLElement* curNode = nullptr;

		char* contents = NULL;
		std::string path;

#ifdef __WIN32__
		path = "../../assets/Default.xml";
#endif
#ifdef __ANDROID__
		path = "Default.xml";
#endif

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
				if (!strcmp(nodeName, pKey)){
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



	void EngineMaster::setValueForKey(const char* value, const char* key) {

		XMLElement* rootNode;
		XMLDocument* doc;
		XMLElement* node;
		XMLPrinter printer;
		std::string path;


		if (!key || !value) {
			return;
		}

		
#ifdef __WIN32__
		path = "../../assets/Default.xml";
#endif
#ifdef __ANDROID__
		path = "Default.xml";
#endif

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


	int EngineMaster::getIntegerForKey(const char* key) {

		const char* value = nullptr;
		XMLElement* rootNode;
		XMLDocument* doc;
		XMLElement* node;

		node = getXMLNodeForKey(key, &rootNode, &doc);

		// find the node
		if (node && node->FirstChild()) {
			value = (const char*)(node->FirstChild()->Value());
		}

		int temp = 0;

		if (value) {
			temp = SDL_atoi(value);
		}

		if (doc) delete doc;

		return temp;
	}


	bool EngineMaster::getBoolForKey(const char* key) { 
		const char* value = nullptr;
		XMLElement* rootNode;
		XMLDocument* doc;
		XMLElement* node;

		node = getXMLNodeForKey(key, &rootNode, &doc);

		// find the node
		if (node && node->FirstChild()) {
			value = (const char*)(node->FirstChild()->Value());
		}

		bool temp = true;
		if (value) {
			temp = (!strcmp(value, "true"));
		}

		if (doc) delete doc;

		return temp;
	}


	double EngineMaster::getDoubleForKey(const char* key) { 
		const char* value = nullptr;
		XMLElement* rootNode;
		XMLDocument* doc;
		XMLElement* node;

		node = getXMLNodeForKey(key, &rootNode, &doc);

		// find the node
		if (node && node->FirstChild()) {
			value = (const char*)(node->FirstChild()->Value());
		}

		double temp = 0.0;

		if (value) {
			temp = SDL_atof(value);
			
		}

		if (doc) delete doc;

		return temp; 
	};


	float EngineMaster::getFloatForKey(const char* key) { 
		float temp = (float)getDoubleForKey(key);
		return temp; 
	};


	string EngineMaster::getStringForKey(const char* key) {

		const char* value = nullptr;
		XMLElement* rootNode;
		XMLElement* node;
		XMLDocument* doc;

		node = getXMLNodeForKey(key, &rootNode, &doc);

		if (node && node->FirstChild()) {
			value = (const char*)(node->FirstChild()->Value());
		}

		string temp = "No Value Found";

		if (value) {
			temp = string(value);
		}

		return temp;
	}


	void EngineMaster::setIntegerForKey(int value, const char* key) {
		// check key
		if (!key) {
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

	void EngineMaster::setBoolForKey(bool value, const char* key) {
		if (value == true) {
			setStringForKey("true", key);
		}
		else {
			setStringForKey("false", key);
		}
	}

	
	void EngineMaster::setDoubleForKey(double value, const char* key) {
		// check key
		if (!key) {
			return;
		}

		// format the value
		char tmp[50];
		memset(tmp, 0, 50);

#ifdef __WIN32__
		sprintf_s(tmp, "%f", value);
#endif

#ifdef __ANDROID__
		std::sprintf(tmp, "%f", value);
#endif

		setValueForKey(tmp, key);

	}

	void EngineMaster::setFloatForKey(float value, const char* key) {
		setDoubleForKey(value, key);
	}
	void EngineMaster::setStringForKey(std::string value, const char* key) {
		if (!key) return;

		setValueForKey(value.c_str(), key);
	}



	void EngineMaster::deleteValueForKey(const char* key) {
		
		XMLElement* rootNode;
		XMLDocument* doc;
		XMLElement* node;
		XMLPrinter printer;
		
		// check the params
		if (!key){
			return;
		}

		// find the node
		node = getXMLNodeForKey(key, &rootNode, &doc);

		// if node not exist, don't need to delete
		if (!node){
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

			// attach printer to the document you want to convert in to a std::string 
			doc->Accept(&printer);

			// Create a std::string and copy your document data in to the string    
			const char* buffer = printer.CStr();

			//Write back to file and save file
			if (FileIO::getInstance()->writeDocument(path.c_str(), &buffer)) {
				SDL_Log("Key : %s :: deleted", key);
			}
			delete doc;
		}
	}


	bool EngineMaster::createXMLFile() {
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
#ifdef __WIN32__
		path = "../../assets/Default.xml";
#endif
#ifdef __ANDROID__
		path = "assets/Default.xml";
#endif

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