
#include "EngineError.h"

namespace DsdlEngine{

	void dsdl_error(std::string errorString){
		std::cout << errorString << std::endl;
		std::cout << "Enter any key to quit!!! \n\n" ;
		//SDL_Quit();
		//exit(69);
	}
}