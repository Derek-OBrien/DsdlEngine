#include "XmlLocalStorage.h"
#include "FileIO.h"

using namespace tinyxml2;
using namespace std;

namespace DsdlEngine {
	/*
	Create As Singleton
	*/
	static XmlLocalStorage* Instance = nullptr;
	XmlLocalStorage* XmlLocalStorage::getInstance() {
		if (!Instance) {
			Instance = new (std::nothrow) XmlLocalStorage();
		}
		return Instance;
	}




	int XmlLocalStorage::getIntegerForKey(const char* key) {

		const char* value = nullptr;
		XMLElement* rootNode;
		XMLDocument* doc;
		XMLElement* node;

		node = FileIO::getInstance()->getXMLNodeForKey(key, &rootNode, &doc);

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


	bool XmlLocalStorage::getBoolForKey(const char* key) {
		const char* value = nullptr;
		XMLElement* rootNode;
		XMLDocument* doc;
		XMLElement* node;

		node = FileIO::getInstance()->getXMLNodeForKey(key, &rootNode, &doc);

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


	double XmlLocalStorage::getDoubleForKey(const char* key) {
		const char* value = nullptr;
		XMLElement* rootNode;
		XMLDocument* doc;
		XMLElement* node;

		node = FileIO::getInstance()->getXMLNodeForKey(key, &rootNode, &doc);

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


	float XmlLocalStorage::getFloatForKey(const char* key) {
		float temp = (float)getDoubleForKey(key);
		return temp;
	};


	std::string XmlLocalStorage::getStringForKey(const char* key) {

		const char* value = nullptr;
		XMLElement* rootNode;
		XMLElement* node;
		XMLDocument* doc;

		node = FileIO::getInstance()->getXMLNodeForKey(key, &rootNode, &doc);

		if (node && node->FirstChild()) {
			value = (const char*)(node->FirstChild()->Value());
		}

		string temp = "No Value Found";

		if (value) {
			temp = string(value);
		}

		return temp;
	}


	void XmlLocalStorage::setIntegerForKey(int value, const char* key) {
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
		sprintf(tmp, "%d", value);
#endif

		FileIO::getInstance()->setValueForKey(tmp, key);

	}


	void XmlLocalStorage::setBoolForKey(bool value, const char* key) {
		if (value == true) {
			setStringForKey("true", key);
		}
		else {
			setStringForKey("false", key);
		}
	}


	void XmlLocalStorage::setDoubleForKey(double value, const char* key) {
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

		FileIO::getInstance()->setValueForKey(tmp, key);

	}

	void XmlLocalStorage::setFloatForKey(float value, const char* key) {
		setDoubleForKey(value, key);
	}
	void XmlLocalStorage::setStringForKey(std::string value, const char* key) {
		if (!key) return;

		FileIO::getInstance()->setValueForKey(value.c_str(), key);
	}



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

		// save file and free doc
		if (doc)
		{
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