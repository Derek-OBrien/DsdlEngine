LOCAL_PATH := $(call my-dir)
MY_PATH := $(LOCAL_PATH)
LOCAL_PATH := $(MY_PATH)
###########################
#
# DsdlEngine shared library
#
###########################

include $(CLEAR_VARS)

LOCAL_MODULE := Dsdl

LOCAL_C_INCLUDES := $(LOCAL_PATH)
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)


LOCAL_SRC_FILES := \
	AudioManager.cpp\
	Button.cpp\
	DsdlEngine.cpp\
	EngineBaseNode.cpp\
	EngineError.cpp\
	EngineMath.cpp\
	Gui.cpp\
	IMainGame.cpp\
	InputManager.cpp\
	Label.cpp\
	Layer.cpp\
	ResourceTexture.cpp\
	SceneManager.cpp\
	Sprite.cpp\
	Timing.cpp\
	Window.cpp


include $(BUILD_SHARED_LIBRARY)

