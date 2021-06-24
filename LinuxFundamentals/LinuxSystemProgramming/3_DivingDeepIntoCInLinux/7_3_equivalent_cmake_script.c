/**
 * The equivalent cmake script assuming we don't want to set the global C compilation flags is as follows:
 
cmake_minimum_required(VERSION 3.5.0 FATAL_ERROR)
project(pythonInterModule LANGUAGES C)

set(CMAKE_C_STANDARD 99)	# Note that we only use 99, and don't say c99!
set(CMAKE_C_STANDARD_REQUIRED True)	# Stops if this particular standard is not found
set(CMAKE_C_EXTENSIONS False)	# Don't use standard extensions (gnu in case of gcc)

add_executable(kernel main.c)

# Could have equivalently used set_source_file_properties instead.
set_target_properties(
	kernel
	PROPERTIES
	COMPILE_FLAGS "-Wall -Wpedantic -Wextra"
	# C_STANDARD c99
	# C_EXTENSIONS False
	# C_STANDARD_REQUIRED False
)

 */