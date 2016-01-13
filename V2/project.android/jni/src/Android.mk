LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_CPP_FEATURES += exceptions
LOCAL_CPPFLAGS  := -I/usr/src/glm

LOCAL_MODULE := main

#Set Paths
SDL_PATH := ../SDL2
ENGINE_PATH := ../../../dsdl-engine
CLASSES_PATH := ../../../classes

# Add includes here
LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include
LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include $(LOCAL_PATH)/../SDL2_image
LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include $(LOCAL_PATH)/../SDL2_ttf
LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include $(LOCAL_PATH)/../SDL2_mixer
#LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(ENGINE_PATH)/ $(ENGINE_PATH)/../DsdlEngine

# Add your application source files here...
LOCAL_SRC_FILES := $(SDL_PATH)/src/main/android/SDL_android_main.c\
	../../../dsdl-engine/AudioManager.cpp\
	../../../dsdl-engine/DsdlEngine.cpp\
	../../../dsdl-engine/EngineError.cpp\
	../../../dsdl-engine/IMainGame.cpp\
	../../../dsdl-engine/InputManager.cpp\
	../../../dsdl-engine/ResourceTexture.cpp\
	../../../dsdl-engine/SceneManager.cpp\
	../../../dsdl-engine/Sprite.cpp\
	../../../dsdl-engine/Timing.cpp\
	../../../dsdl-engine/Window.cpp\
	../../../classes/main.cpp\
	../../../classes/mainGame.cpp

		#$(wildcard $(ENGINE_PATH)/*.cpp)\
	#$(wildcard $(CLASSES_PATH)/*.cpp) 

LOCAL_SHARED_LIBRARIES :=  SDL2 SDL2_image SDL2_ttf SDL2_mixer

LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -llog -landroid -lEGL
LOCAL_CPP_FEATURES += exceptions
LOCAL_CFLAGS += -std=c++11

include $(BUILD_SHARED_LIBRARY)
