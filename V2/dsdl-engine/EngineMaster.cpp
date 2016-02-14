#include "EngineMaster.h"
#include "FileIO.h"

#include "../dependencies/tinyxml/tinyxml2.h"

#include <filesystem>
#include <sys/stat.h>

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



	XMLElement* EngineMaster::getXMLNodeForKey(const char*pKey, XMLElement** rootNode, XMLDocument** doc){

		XMLElement* curNode = nullptr;

		//Check the key
		if (! pKey){
			return nullptr;
		}

		do{
			XMLDocument* xmlDoc = new XMLDocument();
			*doc = xmlDoc;

			std::string xmlBuffer = "../../assets/Default.xml";//FileIO::getInstance()->getSuitableFOpen(getXMLFilePath());//"../../assets/Default.xml";
			
			if (xmlBuffer.empty()){
				DEBUG_MSG("can not read xml file");
				break;
			}

			if (xmlDoc->LoadFile(xmlBuffer.c_str()) == XML_SUCCESS){

				//xmlDoc->Parse(xmlBuffer.c_str(), xmlBuffer.size());

				// get root node
				*rootNode = xmlDoc->RootElement();

				//*rootNode = xmlDoc->FirstChildElement();
				if (nullptr == *rootNode){
					DEBUG_MSG("read root node error" + std::string(xmlDoc->GetErrorStr1()));
					break;
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
			else{
				DEBUG_MSG("Could not load doc: " + std::string(xmlDoc->GetErrorStr1()));
			}
		} while (0);

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
			doc->SaveFile("../../assets/Default.xml");
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
		if (node && node->FirstChild())
		{
			value = (const char*)(node->FirstChild()->Value());
		}

		int ret = 0;

		if (value)
		{
			ret = atoi(value);
		}

		if (doc)
		{
			delete doc;
		}


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
		sprintf_s(tmp, "%d", value);

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
			doc->SaveFile("../../assets/Default.xml");
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
		bRet = XML_SUCCESS == pDoc->SaveFile(FileIO::getInstance()->getSuitableFOpen(_filePath).c_str());
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