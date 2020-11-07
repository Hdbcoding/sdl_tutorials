# Locate SDL2_image library
# This module defines
# SDL2_IMAGE_LIBRARY, the name of the library to link against
# SDL2_IMAGE_FOUND, if false, do not try to link to SDL2_image
# SDL2_IMAGE_INCLUDE_DIR, where to find SDL_image.h
#
# Additional Note: If you see an empty SDL2_IMAGE_LIBRARY_TEMP in your configuration
# and no SDL2_IMAGE_LIBRARY, it means CMake did not find your SDL2_Image library
# (SDL2_image.dll, libsdl2_image.so, SDL2_image.framework, etc).
# Set SDL2_IMAGE_LIBRARY_TEMP to point to your SDL2 library, and configure again.
# Similarly, if you see an empty SDL2MAIN_LIBRARY, you should set this value
# as appropriate. These values are used to generate the final SDL2_IMAGE_LIBRARY
# variable, but when these values are unset, SDL2_IMAGE_LIBRARY does not get created.
#
# $SDL2 is an environment variable that would
# correspond to the ./configure --prefix=$SDL2
# used in building SDL2.
# l.e.galup 9-20-02
#
# Modified by Eric Wing.
# Added code to assist with automated building by using environmental variables
# and providing a more controlled/consistent search behavior.
# Added new modifications to recognize OS X frameworks and
# additional Unix paths (FreeBSD, etc).
# Also corrected the header search path to follow "proper" SDL2 guidelines.
# Added a search for SDL2main which is needed by some platforms.
# Added a search for threads which is needed by some platforms.
# Added needed compile switches for MinGW.
#
# On OSX, this will prefer the Framework version (if found) over others.
# People will have to manually change the cache values of
# SDL2_IMAGE_LIBRARY to override this selection or set the CMake environment
# CMAKE_INCLUDE_PATH to modify the search paths.
#
# Note that the header path has changed from SDL2/SDL.h to just SDL.h
# This needed to change because "proper" SDL2 convention
# is #include "SDL.h", not <SDL2/SDL.h>. This is done for portability
# reasons because not all systems place things in SDL2/ (see FreeBSD).
#
# Ported by Johnny Patterson. This is a literal port for SDL2 of the FindSDL.cmake
# module with the minor edit of changing "SDL" to "SDL2" where necessary. This
# was not created for redistribution, and exists temporarily pending official
# SDL2 CMake modules.
# 
# Note that on windows this will only search for the 32bit libraries, to search
# for 64bit change x86/i686-w64 to x64/x86_64-w64

#=============================================================================
# Copyright 2003-2009 Kitware, Inc.
#
# CMake - Cross Platform Makefile Generator
# Copyright 2000-2014 Kitware, Inc.
# Copyright 2000-2011 Insight Software Consortium
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# * Redistributions of source code must retain the above copyright
# notice, this list of conditions and the following disclaimer.
#
# * Redistributions in binary form must reproduce the above copyright
# notice, this list of conditions and the following disclaimer in the
# documentation and/or other materials provided with the distribution.
#
# * Neither the names of Kitware, Inc., the Insight Software Consortium,
# nor the names of their contributors may be used to endorse or promote
# products derived from this software without specific prior written
# permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
# HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# This software is distributed WITHOUT ANY WARRANTY; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the License for more information.
#=============================================================================
# (To distribute this file outside of CMake, substitute the full
# License text for the above reference.)

SET(SDL2_IMAGE_SEARCH_PATHS
    ~/Library/Frameworks
    /Library/Frameworks
    /usr/local
    /usr
	/usr/local/include/SDL2
	/usr/include/SDL2
    /sw # Fink
    /opt/local # DarwinPorts
    /opt/csw # Blastwave
    /opt
    ${SDL2}
    ${SDL2_IMAGE}
    ${SDL2_PATH}
    ${SDL2_IMAGE_PATH}
    $ENV{SDL2}
	$ENV{SDL2_IMAGE}
)

message(STATUS "Finding SDL2_image")
message(STATUS "SDL2_IMAGE_SEARCH_PATHS: ${SDL2_IMAGE_SEARCH_PATHS}")

set(SDL2_IMAGE_INCLUDE_SUFFIXES include/SDL2 include)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    list(APPEND SDL2_IMAGE_INCLUDE_SUFFIXES x86_64-w64-mingw32/include/SDL2)
else()
    list(APPEND SDL2_IMAGE_INCLUDE_SUFFIXES i686-w64-mingw32/include/SDL2)
endif()

message(STATUS "SDL2_IMAGE_INCLUDE_SUFFIXES: ${SDL2_IMAGE_INCLUDE_SUFFIXES}")
FIND_PATH(SDL2_IMAGE_INCLUDE_DIR SDL_image.h
    HINTS $ENV{SDL2}
    PATH_SUFFIXES ${SDL2_IMAGE_INCLUDE_SUFFIXES}
    PATHS ${SDL2_IMAGE_SEARCH_PATHS}
)
message(STATUS "SDL2_IMAGE_INCLUDE_DIR: ${SDL2_IMAGE_INCLUDE_DIR}")

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(SDL2_IMAGE_LIBRARY_SUFFIXES 
        lib64 
        lib
        lib/x64
        x86_64-w64-mingw32/lib
    )
else()
    set(SDL2_IMAGE_LIBRARY_SUFFIXES 
        lib/x86 
        lib
        i686-w64-mingw32/lib
    )
endif()

message(STATUS "SDL2_IMAGE_LIBRARY_SUFFIXES: ${SDL2_IMAGE_LIBRARY_SUFFIXES}")
FIND_LIBRARY(SDL2_IMAGE_LIBRARY_TEMP
    NAMES SDL2_image
    HINTS $ENV{SDL2}
    PATH_SUFFIXES ${SDL2_IMAGE_LIBRARY_SUFFIXES}
    PATHS ${SDL2_IMAGE_SEARCH_PATHS}
)
message(STATUS "SDL2_IMAGE_LIBRARY_TEMP: ${SDL2_IMAGE_LIBRARY_TEMP}")


SET(SDL2_IMAGE_FOUND "NO")
IF(SDL2_IMAGE_LIBRARY_TEMP)
	# Set the final string here so the GUI reflects the final state.
	SET(SDL2_IMAGE_LIBRARY ${SDL2_IMAGE_LIBRARY_TEMP} CACHE STRING "Where the SDL2_image Library can be found")
	# Set the temp variable to INTERNAL so it is not seen in the CMake GUI
	SET(SDL2_IMAGE_LIBRARY_TEMP "${SDL2_IMAGE_LIBRARY_TEMP}" CACHE INTERNAL "")
	SET(SDL2_IMAGE_FOUND "YES")
ENDIF(SDL2_IMAGE_LIBRARY_TEMP)

INCLUDE(FindPackageHandleStandardArgs)

FIND_PACKAGE_HANDLE_STANDARD_ARGS(SDL2_IMAGE REQUIRED_VARS SDL2_IMAGE_LIBRARY SDL2_IMAGE_INCLUDE_DIR)