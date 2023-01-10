cmake_minimum_required(VERSION 3.18.1)

project("library")

set(OpenCV_DIR ${CMAKE_SOURCE_DIR}/opencv/sdk/native/jni)
find_package(OpenCV REQUIRED core imgproc)

set(ncnn_DIR ${CMAKE_SOURCE_DIR}/ncnn-vulkan/${ANDROID_ABI}/lib/cmake/ncnn)
find_package(ncnn REQUIRED)

add_library(
        library
        SHARED
        yolofacencnn.cpp yoloface.cpp ndkcamera.cpp)

find_library(
        log-lib
        log)

target_link_libraries(
        library
        ncnn
        ${OpenCV_LIBS}
        camera2ndk
        mediandk
        ${log-lib})