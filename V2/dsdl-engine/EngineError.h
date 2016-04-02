
#ifndef _ENGINEERROR_
#define _ENGINEERROR_

#include "EngineDefines.h"

namespace DsdlEngine{

	#define DEBUG_DSDL 1
	#if defined DEBUG_DSDL 
		#if (DEBUG_DSDL == 1)
			#define DEBUG_MSG(x) (std::cout << (x) <<std::endl)
		#else
			#define DEBUG_MSG(x)
		#endif
	#else 
	#define DEBUG_MSG(x)
	#endif

}


#endif