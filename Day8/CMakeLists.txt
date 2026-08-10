cmake_minimum_required(VERSION 3.30)
project(Day8 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# if(CMAKE_COMPILER_ID STREQUAL "MSVC")
#     string(REPLACE "/EHsc" "" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
# endif()

add_executable(Day8 src/main.cpp src/tgaimage.cpp)
target_include_directories(Day8 PRIVATE include/)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(Day8 PRIVATE -Wall -Wextra -pedantic -O3)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(Day8 PRIVATE /W4 /permissive- /O2)
    # target_compile_definitions(Day8 PRIVATE _HAS_EXCEPTIONS=0)
endif()