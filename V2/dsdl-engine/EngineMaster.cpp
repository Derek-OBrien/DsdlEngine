#include "EngineMaster.h"

namespace DsdlEngine {

	//Create As Singleton
	static EngineMaster* Instance = nullptr;
	EngineMaster* EngineMaster::getInstance() {
		if (!Instance) {
			Instance = new (std::nothrow) EngineMaster();
		}
		return Instance;
	}

}