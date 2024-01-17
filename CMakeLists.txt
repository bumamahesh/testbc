# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(CameraCapture)

# Set the path to the Android NDK (replace with your actual NDK path)
set(ANDROID_NDK_PATH  /mnt/c/Users/Dator/AppData/Local/Android/Sdk/ndk/25.1.8937393/)

# Set the ABI you want to build for
#set(ANDROID_ABI arm64-v8a)  # adjust as needed
set(ANDROID_ABI "arm64-v8a")

set(CMAKE_C_COMPILER   ${ANDROID_NDK}/toolchains/llvm/prebuilt/windows-x86_64/bin/aarch64-linux-android29-clang)
set(CMAKE_CXX_COMPILER ${ANDROID_NDK}/toolchains/llvm/prebuilt/windows-x86_64/bin/aarch64-linux-android29-clang++)

# Set the path to the Android platform
set(ANDROID_PLATFORM android-25)  # adjust as needed

# Set the path to your Android toolchain file
set(ANDROID_TOOLCHAIN_FILE ${ANDROID_NDK_PATH}/build/cmake/android.toolchain.cmake)
set(CMAKE_TOOLCHAIN_FILE ${ANDROID_NDK_PATH}/build/cmake/android.toolchain.cmake)


# Specify the source files
set(SOURCE_FILES  jni/main.cpp)

# Set include directories
include_directories(
    ${ANDROID_NDK_PATH}/toolchains/llvm/prebuilt/windows-x86_64/sysroot/usr/include
    ${ANDROID_NDK_PATH}/toolchains/llvm/prebuilt/windows-x86_64/sysroot/usr/include/camera
    ${ANDROID_NDK_PATH}/toolchains/llvm/prebuilt/windows-x86_64/sysroot/usr/include/android
)

# Add the executable
add_executable(CameraCapture ${SOURCE_FILES})

# Include directories
target_include_directories(CameraCapture PRIVATE
    ${ANDROID_NDK_PATH}/sources/android/camera/include
    ${ANDROID_NDK_PATH}/sources/cxx-stl/llvm-libc++/include
    ${ANDROID_NDK_PATH}/sources/android/native_window/include
)


# Link libraries
target_link_libraries(CameraCapture PRIVATE
    native_app_glue
    android
    camera2ndk
    EGL
    m
    log
)

# Set the ABI for the target
set_target_properties(CameraCapture PROPERTIES
    COMPILE_FLAGS "-march=${ANDROID_ABI}"
    LINK_FLAGS "-march=${ANDROID_ABI}"
)

# Set the platform for the target
set_property(TARGET CameraCapture PROPERTY
    APP_PLATFORM ${ANDROID_PLATFORM}
)

# Specify the path to the Android toolchain file
set(CMAKE_TOOLCHAIN_FILE ${ANDROID_TOOLCHAIN_FILE})

# Specify the path to the Android NDK
set(ANDROID_NDK ${ANDROID_NDK_PATH})

# Specify the CMake cross-compiling mode for Android
set(CMAKE_ANDROID_NDK ${ANDROID_NDK})

# Specify the architecture for the target
set(CMAKE_ANDROID_ARCH_ABI ${ANDROID_ABI})

# Specify the minimum Android version for the target
set(CMAKE_ANDROID_API ${ANDROID_PLATFORM})
