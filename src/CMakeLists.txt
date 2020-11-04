cmake_minimum_required(VERSION 3.18)
project(sdl_tutorial VERSION 1.0)

# setting up compiler flags
add_library(tutorial_compiler_flags INTERFACE)
# setting c++ 17
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_17)
# setting compiler flags for warning verbosity
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU>")
set(msvc_cxx "<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(tutorial_compiler_flags INTERFACE
    "$<{gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused;>>"
    "$<{msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

# setting the install location of sdl2 for findsdl
set(SDL2_PATH "C:\\SDL2\\SDL2-2.0.12\\i686-w64-mingw32")

# to locate findsdl modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
include_directories(include)

if(WIN32)
    # there should be a better way to do this... right?
    file(COPY "${SDL2_PATH}\\bin\\SDL2.dll" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}\\lesson0")
    file(COPY "${SDL2_PATH}\\bin\\SDL2.dll" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}\\lesson1")
endif()

add_subdirectory(lesson0)
add_subdirectory(lesson1)