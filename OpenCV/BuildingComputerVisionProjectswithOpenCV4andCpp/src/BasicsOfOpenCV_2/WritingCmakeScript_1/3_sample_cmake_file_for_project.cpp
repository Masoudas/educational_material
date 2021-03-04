/**
* So now, here's a pseudo code of how we should write the lists file for our project:
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
#	Specify the minimum required version of cmake
#	Define the project
#	Find the openCV packages residing in our system.
#	Add the path to openCV include to our project, so that the headers are recognizable. This is why the command
#	is called include_directories. It's interpreted as path to include directories you want for this project.
#	Introduce the path to the openCV binaries to Linker, to link at run-time, or possibly at compile time. This
#   command is perhaps more difficult to remember.
#	Create a target for the project (an executable)
#	Link the opencv library headers to this target.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
* 
* With all of these in mind, here's an actual CMakeLists.txt file for creating such a project.
* 
* Here's some food for thought? How come we're able to see the openCV variables once we've included the opencv
* lib in our own namespace? How are we able to pass child name space variables to parent namespace?
* 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cmake_minimum_required(VERSION="4.0.0")
project(sample_opencv_proj)
FIND_PACKAGE(OpenCV 4.0.0 REQUIRED core) # This is to just add the core modules.
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIB_DIR})

add_executable(app main.cpp)
target_link_libraries(app ${OpenCV_LIBS})
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/