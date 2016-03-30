#ifndef _XMLLOCALSTORAGE_
#define _XMLLOCALSTORAGE_

#include "DsdlEngine.h"
#include "EngineDefines.h"
#include "../dependencies/tinyxml/tinyxml2.h"

/*
	File: XmlLocalStorage
	Author: Derek O Brien
	Description: For loading and saving values to XML file
*/
namespace DsdlEngine {
	class XmlLocalStorage {
	public:

		//Static instance for singleton
		static XmlLocalStorage* getInstance();

		/**
		* Set value by key.
		* @param key The key to set.
		* @param value A bool/int/double/float/string value to set to the key.
		*/
		void setIntegerForKey(int value, const char* key);
		void setBoolForKey(bool value, const char* key);
		void setDoubleForKey(double value, const char* key);
		void setFloatForKey(float value, const char* key);
		void setStringForKey(std::string value, const char* key);


		/**
		* Get bool value by key, if the key doesn't exist, will return false.
		* @param key The key to get value.
		* @return bool/int/double/float/string value by `key`.
		*/
		int getIntegerForKey(const char* key);
		bool getBoolForKey(const char* key);
		double getDoubleForKey(const char* key);
		float getFloatForKey(const char* key);
		std::string getStringForKey(const char* key);


		//Delete Value for key
		void deleteValueForKey(const char* key);

	protected:

		XmlLocalStorage() {};
		virtual ~XmlLocalStorage() {};

	private:

	};
}
#endif // !_XMLLOCALSTORAGE_
