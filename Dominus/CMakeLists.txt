# CMakeList.txt : CMake project for Dominus, include source and define
# project specific logic here.
#
CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

# Add source to this project's executable.
ADD_EXECUTABLE(Dominus "Dominus.c" "Dominus.h")

IF(WIN32)
	TARGET_INCLUDE_DIRECTORIES(Dominus PUBLIC "C:\\vcpkg\\installed\\x64-windows\\include\\")
	
	IF(CMAKE_BUILD_TYPE STREQUAL "Debug")
		TARGET_LINK_DIRECTORIES(Dominus PUBLIC "C:\\vcpkg\\installed\\x64-windows\\debug\\lib\\")
		TARGET_LINK_LIBRARIES(Dominus "allegro-debug")
	ELSEIF(CMAKE_BUILD_TYPE STREQUAL "MinSizeRel")
		MESSAGE(FATAL_ERROR "This build type is not supported yet.")
	ELSEIF(CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
		MESSAGE(FATAL_ERROR "This build type is not supported yet.")
	ELSEIF(CMAKE_BUILD_TYPE STREQUAL "Release")
		TARGET_LINK_DIRECTORIES(Dominus PUBLIC "C:\\vcpkg\\installed\\x64-windows\\lib\\")
		TARGET_LINK_LIBRARIES(Dominus "allegro")
	ELSE()
		MESSAGE(FATAL_ERROR "The current build type is not supported: ${CMAKE_BUILD_TYPE}")
	ENDIF()
ELSE()
	IF(CMAKE_BUILD_TYPE STREQUAL "Debug")
	ELSEIF(CMAKE_BUILD_TYPE STREQUAL "MinSizeRel")
	ELSEIF(CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
	ELSEIF(CMAKE_BUILD_TYPE STREQUAL "Release")
	ELSE()
		MESSAGE(FATAL_ERROR "The current build type is not supported: ${CMAKE_BUILD_TYPE}")
    ENDIF()
    
    TARGET_LINK_LIBRARIES(Dominus "-lallegro")
ENDIF()
