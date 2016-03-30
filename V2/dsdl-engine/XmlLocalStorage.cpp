#include "XmlLocalStorage.h"
#include "FileIO.h"

/*
	File: XmlLocalStorage
	Author: Derek O Brien
	Description: For loading and saving values to XML file
*/

using namespace tinyxml2;
using namespace std;

namespace DsdlEngine {
	
	//Create As Singleton static instance
	static XmlLocalStorage* Instance = nullptr;
	XmlLocalStorage* XmlLocalStorage::getInstance() {
		if (!Instance) {
			Instance = new (std::nothrow) XmlLocalStorage();
		}
		return Instance;
	}



	//get integet value for key passed in
	int XmlLocalStorage::getIntegerForKey(const char* key) {

		const char* value = nullptr;
		XMLElement* rootNode;
		XMLDocument* doc;
		XMLElement* node;

		//Get node from xml file
		node = FileIO::getInstance()->getXMLNodeForKey(key, &rootNode, &doc);

		//Get the value from the node
		if (node && node->FirstChild()) {
			value = (const char*)(node->FirstChild()->Value());
		}

		//Convert value to type needed
		int temp = 0;
		if (value) {
			temp = SDL_atoi(value);
		}

		if (doc) delete doc;

		return temp;
	}


	//Get bool Value for key
	bool XmlLocalStorage::getBoolForKey(const char* key) {
	
		const char* value = nullptr;
		XMLElement* rootNode;
		XMLDocument* doc;
		XMLElement* node;

		//Get node from xml file
		node = FileIO::getInstance()->getXMLNodeForKey(key, &rootNode, &doc);

		//Get the value from the node
		if (node && node->FirstChild()) {
			value = (const char*)(node->FirstChild()->Value());
		}

		//Convert value to type needed

		bool temp = true;
		if (value) {
			temp = (!strcmp(value, "true"));
		}

		if (doc) delete doc;

		return temp;
	}

	
	//Get Double  Value for key passed in
	double XmlLocalStorage::getDoubleForKey(const char* key) {

		const char* value = nullptr;
		XMLElement* rootNode;
		XMLDocument* doc;
		XMLElement* node;

		//Get node from xml file
		node = FileIO::getInstance()->getXMLNodeForKey(key, &rootNode, &doc);

		//Get the value from the node
		if (node && node->FirstChild()) {
			value = (const char*)(node->FirstChild()->Value());
		}

		//Convert value to type needed
		double temp = 0.0;

		if (value) {
			temp = SDL_atof(value);
		}

		if (doc) delete doc;

		return temp;
	};

	//Get float value for key passed in
	float XmlLocalStorage::getFloatForKey(const char* key) {
		float temp = (float)getDoubleForKey(key);
		return temp;
	};

	//Get String value for key passed in 
	std::string XmlLocalStorage::getStringForKey(const char* key) {

		const char* value = nullptr;
		XMLElement* rootNode;
		XMLDocument* doc;
		XMLElement* node;

		//Get node from xml file
		node = FileIO::getInstance()->getXMLNodeForKey(key, &rootNode, &doc);

		//Get the value from the node
		if (node && node->FirstChild()) {
			value = (const char*)(node->FirstChild()->Value());
		}

		//Convert value to type needed
		string temp = "No Value Found";

		if (value) {
			temp = string(value);
		}

		return temp;
	}

	//Set a string value for the key 
	void XmlLocalStorage::setIntegerForKey(int value, const char* key) {
		// check key
		if (!key) {
			return;
		}

		// format the value as char for saving
		char tmp[50];
		memset(tmp, 0, 50);
#ifdef __WIN32__
		sprintf_s(tmp, "%d", value);
#endif

#ifdef __ANDROID__
		sprintf(tmp, "%d", value);
#endif

		//Save the Value and key
		FileIO::getInstance()->setValueForKey(tmp, key);
	}

	//Set bool value for key passed in
	void XmlLocalStorage::setBoolForKey(bool value, const char* key) {
		if (value == true) {
			setStringForKey("true", key);
		}
		else {
			setStringForKey("false", key);
		}
	}

	//Set double value for key passed in
	void XmlLocalStorage::setDoubleForKey(double value, const char* key) {
		// check key
		if (!key) {
			return;
		}

		// format the value as char for saving
		char tmp[50];
		memset(tmp, 0, 50);
#ifdef __WIN32__
		sprintf_s(tmp, "%f", value);
#endif

#ifdef __ANDROID__
		sprintf(tmp, "%f", value);
#endif

		//Save the value and key
		FileIO::getInstance()->setValueForKey(tmp, key);
	}

	//Set float value for key
	void XmlLocalStorage::setFloatForKey(float value, const char* key) {
		setDoubleForKey(value, key);
	}
	
	//Set String value for key
	void XmlLocalStorage::setStringForKey(std::string value, const char* key) {
		if (!key) return;

		FileIO::getInstance()->setValueForKey(value.c_str(), key);
	}


	//Delete value fo node
	void XmlLocalStorage::deleteValueForKey(const char* key) {

		XMLElement* rootNode;
		XMLDocument* doc;
		XMLElement* node;
		XMLPrinter printer;

		// check the params
		if (!key) {
			return;
		}

		// find the node
		node = FileIO::getInstance()->getXMLNodeForKey(key, &rootNode, &doc);

		// if node not exist, don't need to delete
		if (!node) {
			return;
		}

		if (doc){
			//Delete Node
			doc->DeleteNode(node);
			std::string path;
			path = FileIO::getInstance()->getWritablePath() + "Default.xml";

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
}