cmake_minimum_required(VERSION 3.30)
project(Day5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(Day5 src/main.cpp)
target_include_directories(Day5 PRIVATE include/)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(Day5 PRIVATE -Wall -Wextra -pedantic -O3)
elseif(CMAKE_COMPILER_D STREQUAL "MSVC")
    target_compile_options(Day5 PRIVATE /W4 /permissive- /O2 /GR-)
endif()