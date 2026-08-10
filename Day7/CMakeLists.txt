cmake_minimum_required(VERSION 3.30)
project(Day7 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_COMPILER_ID STREQUAL "MSVC")
    string(REPLACE "/EHsc" "" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
endif()

add_executable(Day7 src/main.cpp)
target_include_directories(Day7 PRIVATE include/)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(Day7 PRIVATE -Wall -Wextra -pedantic -O3 -fno-exceptions)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(Day7 PRIVATE /W4 /permissive- /O2 /EHs-c-)
    target_compile_definitions(Day7 PRIVATE _HAS_EXCEPTIONS=0)
endif()