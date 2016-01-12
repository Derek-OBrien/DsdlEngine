LOCAL_PATH := $(call my-dir)

###########################
#
# DsdlEngine shared library
#
###########################

include $(CLEAR_VARS)

LOCAL_MODULE := DsdlEngine

LOCAL_C_INCLUDES := $(LOCAL_PATH)/

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_C_INCLUDES)

LOCAL_SRC_FILES := \
	$(wildcard $(LOCAL_PATH)/*.cpp) 
	

# Optional compiler flags.
LOCAL_LDLIBS   = -lz -lm
LOCAL_CFLAGS   = -Wall -pedantic -std=c99 -g

include $(BUILD_STATIC_LIBRARY)

