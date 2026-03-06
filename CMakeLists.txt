cmake_minimum_required(VERSION 3.16)
project(library_system)
set(CMAKE_CXX_STANDARD 17)

set(SOURCES
main.cpp
#anagram_checker.cpp
)

set(HEADERS
#includes/utilities.h
)

add_executable(library_system
${SOURCES}
${HEADERS})