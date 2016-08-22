# Sets the minimum version of CMake required to build the native
# library. You should either keep the default value or only pass a
# value of 3.4.0 or lower.

cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
set(jniLibs C:/Users/Owner/AndroidStudioProjects/HelloCv/app/src/main/jniLibs)

set(OpenCV_DIR C:\\Users\\Owner\\OpenCV-3.1.0-android-sdk\\sdk\\native\\jni)
FIND_PACKAGE(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS} ${OpenCV_DIR}/include/opencv )
link_directories(${jniLibs}/${ANDROID_ABI})


add_library(lib_opencv_core STATIC IMPORTED)
add_library(lib_opencv_imgproc STATIC IMPORTED)
add_library(lib_opencv_features2d STATIC IMPORTED)
set_target_properties(lib_opencv_core PROPERTIES IMPORTED_LOCATION ${jniLibs}/${ANDROID_ABI}/libopencv_core.a)
set_target_properties(lib_opencv_features2d PROPERTIES IMPORTED_LOCATION ${jniLibs}/${ANDROID_ABI}/libopencv_features2d.a)
set_target_properties(lib_opencv_imgproc PROPERTIES IMPORTED_LOCATION ${jniLibs}/${ANDROID_ABI}/libopencv_imgproc.a)

add_library( native-lib SHARED src/main/cpp/native-lib.cpp )

TARGET_LINK_LIBRARIES(native-lib $\{OpenCV_LIBS} log lib_opencv_core lib_opencv_features2d lib_opencv_imgproc)
