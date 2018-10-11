cmake_minimum_required(VERSION 3.2)

project(mingw-test)

set(CMAKE_SYSTEM_NAME Windows)

SET(CMAKE_C_COMPILER i686-w64-mingw32-gcc)
SET(CMAKE_CXX_COMPILER i686-w64-mingw32-g++)
SET(CMAKE_RC_COMPILER i686-w64-mingw32-windres)
set(CMAKE_RANLIB i686-w64-mingw32-ranlib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS)

include(FindPkgConfig)
find_package(PkgConfig REQUIRED)
pkg_check_modules(ZLIB "zlib")

include_directories(${ZLIB_INCLUDE_DIRS})

add_executable(exec-runtime exec-runtime.cpp)
target_link_libraries(exec-runtime ${ZLIB_LIBRARIES})

add_executable(exec-compile-time exec-compile-time.cpp shared_lib.h)
target_link_libraries(exec-compile-time ${ZLIB_LIBRARIES})
target_link_libraries(exec-compile-time shared_lib.dll)


add_library(shared_lib.dll SHARED shared_lib.cpp shared_lib.h)
set_target_properties(shared_lib.dll PROPERTIES
        PREFIX ""
        SUFFIX ""
        LINK_FLAGS "-Wl,--add-stdcall-alias"
        POSITION_INDEPENDENT_CODE 0 # this is to avoid MinGW warning; MinGW generates position-independent-code for DLL by default
        )
