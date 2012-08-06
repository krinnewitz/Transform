cmake_minimum_required (VERSION 2.6)
project (TRANSFORM) 

set( CMAKE_CXX_FLAGS         "-O3 -g ")

FIND_PACKAGE( OpenCV REQUIRED )

add_executable (transform Main.cpp Transform.cpp Texture.cpp) 

TARGET_LINK_LIBRARIES( transform ${OpenCV_LIBS} )

