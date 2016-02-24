
# Uncomment this if you're using STL in your project
# See CPLUSPLUS-SUPPORT.html in the NDK documentation for more information

#APP_STL := stlport_static 

NDK_TOOLCHAIN_VERSION := 4.9
APP_STL := gnustl_shared


#APP_STL := c++_shared
APP_CPPFLAGS += -std=c++11
