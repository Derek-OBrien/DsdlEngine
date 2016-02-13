set(DSDL_SRC
	AudioManager.cpp
	Button.cpp
	DsdlEngine.cpp
	EngineBaseNode.cpp
	EngineError.cpp
	EngineMath.cpp
	Gui.cpp
	IMainGame.cpp
	InputManager.cpp
	Label.cpp
	Layer.cpp
	ResourceTexture.cpp
	SceneManager.cpp
	Sprite.cpp
	Timing.cpp
	Window.cpp
)

include_directories(
  ..
)

add_library(dsdl STATIC
  ${DSDL_SRC}
)

set_target_properties(dsdl
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
