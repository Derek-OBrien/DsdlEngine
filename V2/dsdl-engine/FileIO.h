#ifndef _FILEIO_
#define _FILEIO_
#include "EngineDefines.h"
//#include <filesystem>
#include <sys/stat.h>


namespace DsdlEngine{
	class FileIO
	{
	public:
		static FileIO* getInstance();


		bool fileExists2(const std::string& name);
		std::string getSuitableFOpen(const std::string& filenameUtf8) const;
		std::string getWritablePath() const;
		
	protected:

		FileIO(){};
		virtual ~FileIO(){};
	private:

	};
}

#endif