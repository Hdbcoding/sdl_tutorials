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
set(SDL2_PATH "C:\\SDL2\\SDL2-2.0.12")
set(SDL2_IMAGE_PATH "C:\\SDL2\\SDL2_image-2.0.5")

# to locate findsdl modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_IMAGE REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
include_directories(include)

set(project_list wu_lesson0 wu_lesson1 wu_lesson2 wu_lesson3)
foreach(proj IN LISTS project_list)
    add_subdirectory(${proj})
    if (WIN32)
        if(CMAKE_SIZEOF_VOID_P EQUAL 8)
            file(COPY "${SDL2_PATH}\\x86_64-w64-mingw32\\bin\\SDL2.dll" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}\\${proj}")
        else()
            file(COPY "${SDL2_PATH}\\i686-w64-mingw32\\bin\\SDL2.dll" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}\\${proj}")
        endif()
    endif()
endforeach(proj)