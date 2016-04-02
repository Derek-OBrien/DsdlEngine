#ifndef _ENGINEMASTER_
#define _ENGINEMASTER_

#include "EngineDefines.h"

/**
*	@author Derek O Brien
*/

namespace DsdlEngine{
	/**
	*	EngineMaster is a stactic singleton helper class 
	*/
	class EngineMaster{
	public:

		/**
		*	getInstace, create EngineMaster as a Static instance.
		*	@retutn static instance of EngineMaster
		*/
		static EngineMaster* getInstance();

	protected:
		/**
		*	Constructor
		*/
		EngineMaster(){};

		/**
		*	Deconstructor
		*/
		virtual ~EngineMaster(){};

	private:

	};
}


#endif // !_ENGINEMASTER_