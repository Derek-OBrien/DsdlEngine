#ifndef XMLLOCALSTORAGE
#define XMLLOCALSTORAGE


#include "DsdlEngine.h"
#include "EngineDefines.h"
#include "../dependencies/tinyxml/tinyxml2.h"

namespace DsdlEngine {
	class XmlLocalStorage {
	public:

		static XmlLocalStorage* getInstance();

		/**
		* Set bool value by key.
		* @param key The key to set.
		* @param value A bool value to set to the key.
		* @js NA
		*/
		//void setValueForKey(const char* value, const char* key);
		void setIntegerForKey(int value, const char* key);
		void setBoolForKey(bool value, const char* key);
		void setDoubleForKey(double value, const char* key);
		void setFloatForKey(float value, const char* key);
		void setStringForKey(std::string value, const char* key);


		/**
		* Get bool value by key, if the key doesn't exist, will return false.
		* You can set the default value, or it is false.
		* @param key The key to get value.
		* @return Bool value by `key`.
		* @js NA
		*/
		int getIntegerForKey(const char* key);
		bool getBoolForKey(const char* key);
		double getDoubleForKey(const char* key);
		float getFloatForKey(const char* key);
		std::string getStringForKey(const char* key);


		void deleteValueForKey(const char* key);


	protected:

		XmlLocalStorage() {};
		virtual ~XmlLocalStorage() {};

	private:
	};
}
#endif // !XMLLOCALSTORAGE
