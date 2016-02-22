LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_CPP_FEATURES += exceptions
LOCAL_CPPFLAGS  := -I/usr/src/glm

LOCAL_MODULE := main

#Set Paths
SDL_PATH := ../SDL2
BOX2D_PATH := ../Box2D
DSDL_PATH := ../Dsdl

# Add includes here
LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include
LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include $(LOCAL_PATH)/../SDL2_image
LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include $(LOCAL_PATH)/../SDL2_ttf
LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include $(LOCAL_PATH)/../SDL2_mixer
LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(DSDL_PATH)/
LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(BOX2D_PATH)/

#Include all engine cpp files
ENGINE_FILE_LIST := $(wildcard $(LOCAL_PATH)/../../../dsdl-engine/*.cpp)

#Include all Example game cpp files
GAME_FILE_LIST := $(wildcard $(LOCAL_PATH)/../../../classes/Example/*.cpp)

#INclude Tinyxml
XML_FILE_LIST := $(wildcard $(LOCAL_PATH)/../../../dependencies/tinyxml/*.cpp)

# Add your application source files here...
LOCAL_SRC_FILES := $(SDL_PATH)/src/main/android/SDL_android_main.c\
	$(XML_FILE_LIST:$(LOCAL_PATH)/%=%)\
	$(ENGINE_FILE_LIST:$(LOCAL_PATH)/%=%)\
	$(GAME_FILE_LIST:$(LOCAL_PATH)/%=%)\
	../../../classes/main.cpp
	
LOCAL_SHARED_LIBRARIES :=  SDL2 SDL2_image SDL2_ttf SDL2_mixer box2d_static

LOCAL_LDLIBS := -lGLESv1_CM -llog -lEGL
#LOCAL_CPP_FEATURES += exceptions
#LOCAL_CFLAGS += -std=c++11

include $(BUILD_SHARED_LIBRARY)


