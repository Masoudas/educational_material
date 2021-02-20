cmake_minimum_required(VERSION 3.0.0)
project(sample_opencv_proj)
FIND_PACKAGE(OpenCV 4.0.0 REQUIRED core)
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIB_DIR})

add_executable(app src/main.cpp)
target_link_libraries(app ${OpenCV_LIBS})