cmake_minimum_required(VERSION 3.13)
project(WoWHook)

set(CMAKE_CXX_STANDARD 17)

set(base_files
		src/Application.cpp
		src/Application.h
		src/WoWHook.cpp
		src/WoWHook.h
		src/WoWHook.def
		src/preCompiled.cpp
		src/preCompiled.h)

set(source_files
		${base_files})

# Set a group for Visual Studio
source_group("" FILES ${base_files})

add_library(WoWHook MODULE ${source_files})

# Make sure the output filename is dinput8.dll
set_target_properties(WoWHook PROPERTIES OUTPUT_NAME "dinput8")