#ifndef _XMLLOCALSTORAGE_
#define _XMLLOCALSTORAGE_

#include "DsdlEngine.h"
#include "EngineDefines.h"
#include "../dependencies/tinyxml/tinyxml2.h"

/**
*	@author Derek O Brien
*/
namespace DsdlEngine {

	/**
	*	XmlLocalStorage is a class for reading and setting values in XML
	*	It is able to read and set all the base value types.
	*/
	class XmlLocalStorage {
	public:

		/**
		*	getInstance gets a static instance for the XmlLocalStorage class.
		*	@return XmlLocalStorage instance
		*/
		static XmlLocalStorage* getInstance();

		/**
		*	Set a int value for a key in xml.
		*	@param key The key to set.
		*	@param value, int value to be saved
		*/
		void setIntegerForKey(int value, const char* key);

		/**
		*	Set a bool value for a key in xml.
		*	@param key The key to set.
		*	@param value, bool value to be saved
		*/
		void setBoolForKey(bool value, const char* key);

		/**
		*	Set a double value for a key in xml.
		*	@param key The key to set.
		*	@param value, double value to be saved
		*/
		void setDoubleForKey(double value, const char* key);

		/**
		*	Set a float value for a key in xml.
		*	@param key The key to set.
		*	@param value, float value to be saved
		*/
		void setFloatForKey(float value, const char* key);

		/**
		*	Set a string value for a key in xml.
		*	@param key The key to set.
		*	@param value, string value to be saved
		*/
		void setStringForKey(std::string value, const char* key);


		/**
		* Get int value by key, if the key doesn't exist, will return 0.
		* @param key The key to get value.
		* @return int value by `key`.
		*/
		int getIntegerForKey(const char* key);

		/**
		* Get bool value by key, if the key doesn't exist, will return false.
		* @param key The key to get value.
		* @return bool value by `key`.
		*/
		bool getBoolForKey(const char* key);

		/**
		* Get double value by key, if the key doesn't exist, will return 0.
		* @param key The key to get value.
		* @return double value by `key`.
		*/
		double getDoubleForKey(const char* key);

		/**
		* Get float value by key, if the key doesn't exist, will return 0.
		* @param key The key to get value.
		* @return float value by `key`.
		*/
		float getFloatForKey(const char* key);

		/**
		* Get string value by key, if the key doesn't exist, will return null.
		* @param key The key to get value.
		* @return string value by `key`.
		*/
		std::string getStringForKey(const char* key);

		/**
		*	Delete value for key.
		*	@parma key, key to delete value for
		*/
		void deleteValueForKey(const char* key);

	protected:

		/**
		*	Constructor
		*/
		XmlLocalStorage() {};

		/**
		*	Deconstructor
		*/
		virtual ~XmlLocalStorage() {};

	private:

	};
}
#endif // !_XMLLOCALSTORAGE_
