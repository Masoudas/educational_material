/**
* So now, here's a pseudo code of how we should write the lists file for our project:
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
#	Specify the minimum required version of cmake
#	Define the project
#	Find the openCV package
#	Add the opencv package folder, so that it's compiled using its CMAKE file
#	Introduce the path to the openCV libraries to Linker
#	Create a target for the project (an executable)
#	Link the opencv include path to this target.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
* 
* With all of these in mind, here's an actual CMakeLists.txt file for creating such a project.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cmake_minimum_required(VERSION="4.0.0")
project(sample_opencv_proj)
FIND_PACKAGE(OpenCV 4.0.0 REQUIRED core)
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIB_DIR})

add_executable(app main.cpp)
target_link_libraries(app ${OpenCV_LIBS})
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/