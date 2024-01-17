# Android.mk

# Define the path to your source files
LOCAL_PATH := $(call my-dir)
SRC_PATH := $(LOCAL_PATH)/../jni

# Set the minimum platform version
APP_PLATFORM := android-21

# Include the necessary module for your executable
include $(CLEAR_VARS)

# Specify the name of your executable
LOCAL_MODULE := my_native_app

# Add your C++ source files
LOCAL_SRC_FILES := $(SRC_PATH)/main.cpp

# Set the include directories if needed
LOCAL_C_INCLUDES += $(SRC_PATH) \
                    C:/Users/Dator/AppData/Local/Android/Sdk/ndk/25.1.8937393/toolchains/llvm/prebuilt/windows-x86_64/sysroot/usr/include/camera \
					C:\Users\Dator\AppData\Local\Android\Sdk\ndk\25.1.8937393\toolchains\llvm\prebuilt\windows-x86_64\sysroot\usr\include\android
# Add any necessary libraries (e.g., log library)
LOCAL_LDLIBS += -llog -landroid_camera2ndk

# Specify shared libraries dependency
LOCAL_SHARED_LIBRARIES := android_camera2ndk


include $(BUILD_SHARED_LIBRARY)

