cmake_minimum_required(VERSION 3.16)
project(LibrarySystem)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Include header files
include_directories(include)

#All source files
file(GLOB_RECURSE SOURCES
    src/*.cpp
)

#Create executable
add_executable(LibrarySystem
    main.cpp
    ${SOURCES}
)