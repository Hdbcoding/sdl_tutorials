cmake_minimum_required(VERSION 3.18)

project(lesson0 VERSION 1.0)

add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_17)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU>")
set(msvc_cxx "<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(tutorial_compiler_flags INTERFACE
    "$<{gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused;>>"
    "$<{msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

set(SDL2_PATH "C:\\SDL2\\SDL2-2.0.12\\i686-w64-mingw32")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../../findsdl/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(lesson0 lesson0.cxx)
target_link_libraries(lesson0 ${SDL2_LIBRARY})