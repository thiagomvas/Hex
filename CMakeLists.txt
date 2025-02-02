cmake_minimum_required(VERSION 3.30)
project(Hex)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Hide Warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -w")

# Include directories
include_directories(
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/lib
)

# Add source files
file(GLOB_RECURSE SOURCES
        ${CMAKE_SOURCE_DIR}/src/*.cpp
        ${CMAKE_SOURCE_DIR}/lib/**/*.cpp
)

# Create the library
add_library(Hex SHARED ${SOURCES})

# Platform-specific linking
if(WIN32)
    # Link Windows-specific libraries
    target_link_libraries(Hex
            ${CMAKE_SOURCE_DIR}/lib/libraylib.a
            opengl32
            gdi32
            winmm
    )
elseif(UNIX)
    # Link Unix-specific libraries (Linux)
    target_link_libraries(Hex
            ${CMAKE_SOURCE_DIR}/lib/libraylib.a
            OpenGL
            GL
            X11
    )
endif()

# Test executable
add_executable(TestHex ${CMAKE_SOURCE_DIR}/test/main.cpp)

# Link the test executable with the library
target_link_libraries(TestHex Hex)
