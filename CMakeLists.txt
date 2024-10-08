﻿cmake_minimum_required(VERSION 3.16)
project(WoWHook)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

set(base_files
		src/Application.cpp
		src/Application.h
		src/WoWHook.cpp
		src/WoWHook.h
		src/WoWHook.def
		src/preCompiled.cpp
		src/preCompiled.h)

set(class_files
		src/Classes/Engine.cpp
		src/Classes/Engine.h
		src/Classes/ObjectMgr.cpp
		src/Classes/ObjectMgr.h
		src/Classes/ClientServices.cpp
		src/Classes/ClientServices.h)

set(d3d9_files
		src/FakeDirect3D9/fake_IDirect3D9.cpp
		src/FakeDirect3D9/fake_IDirect3D9.h
		src/FakeDirect3D9/fake_IDirect3DDevice9.cpp
		src/FakeDirect3D9/fake_IDirect3DDevice9.h)

set(wow_files
		src/WoW/MemoryAddresses.h
		src/WoW/CGxDeviceD3d.h
		src/WoW/CDataStore.cpp
		src/WoW/CDataStore.h
		src/WoW/CPlayer.h
		src/WoW/DataTypes.h)

set(source_files
		${base_files}
		${class_files}
		${d3d9_files}
		${wow_files})

# Set a group for Visual Studio
source_group("" FILES ${base_files})
source_group("Classes" FILES ${class_files})
source_group("FakeDirect3D9" FILES ${d3d9_files})
source_group("WoW" FILES ${wow_files})

add_library(WoWHook MODULE ${source_files})

# Make sure the output filename is dinput8.dll
set_target_properties(WoWHook PROPERTIES OUTPUT_NAME "dinput8")

target_link_libraries(WoWHook PRIVATE dwmapi.lib)

target_precompile_headers(WoWHook PUBLIC src/preCompiled.h)

install(TARGETS WoWHook LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX})
