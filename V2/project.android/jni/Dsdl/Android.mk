LOCAL_PATH := $(call my-dir)

###########################
#
# DsdlEngine shared library
#
###########################

include $(CLEAR_VARS)

LOCAL_MODULE := DsdlEngine

LOCAL_MODULE_FILENAME := libdsdl


LOCAL_SRC_FILES := \
	$(wildcard $(LOCAL_PATH)/*.cpp) 



LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/..

LOCAL_C_INCLUDES := $(LOCAL_PATH)/..

include $(BUILD_STATIC_LIBRARY)

