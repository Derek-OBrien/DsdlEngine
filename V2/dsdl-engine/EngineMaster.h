#ifndef _ENGINEMASTER_
#define _ENGINEMASTER_

#include "EngineDefines.h"
#include "../dependencies/tinyxml/tinyxml2.h"

namespace DsdlEngine{

	class EngineMaster{
	public:

		/**
		*	Returns the singleton.
		*/
		static EngineMaster* getInstance();

		void setAssetsPath(std::string s){ rootAssetsPath = s; };
		std::string getAssetsPath(){ return rootAssetsPath;  };


		//void setWindowSize(int h, int w){ windowHeight = h; windowWidth = w; };

		//int returnWindowWidth(){ return windowWidth; }
		//int returnWindowHeight(){ return windowHeight; }

//		Size getWindowSize(){ return Size(windowWidth, windowHeight); };

		//For Read Wirte with xml

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

		//auto getValueForKey(const char* key);
		/**
		* delete any value by key,
		* @param key The key to delete value.
		* @js NA
		*/
		void deleteValueForKey(const char* key);

		/** All supported platforms other iOS & Android use xml file to save values. This function is return the file path of the xml path.
		* @js NA
		*/
		
		/** All supported platforms other iOS & Android and CC_PLATFORM_WINRT use xml file to save values. This function checks whether the xml file exists or not.
		* @return True if the xml file exists, false if not.
		* @js NA
		*/

	protected:
		EngineMaster(){};
		virtual ~EngineMaster(){};

	private:


		static bool isXMLFileExist();
		static bool createXMLFile();
		static void initXMLFilePath();
		static const std::string getXMLFilePath();

		tinyxml2::XMLElement* getXMLNodeForKey(const char*pKey, tinyxml2::XMLElement** rootNode, tinyxml2::XMLDocument** doc);
		void setValueForKey(const char* value, const char* key);

		
		static std::string _filePath;
		static bool _isFilePathInitialized;


		std::string rootAssetsPath;
		int windowHeight;
		int windowWidth;
	//	Size windowSize;
	};
}


#endif