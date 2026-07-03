cmake_minimum_required(VERSION 3.30)
project(DoublyList LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(libList src/list.cxx)
target_include_directories(libList PRIVATE ${CMAKE_SOURCE_DIR}/include)

add_executable(DoublyList src/main.cc)
target_include_directories(DoublyList PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(DoublyList PRIVATE libList)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(DoublyList PRIVATE -Wall -Wextra -pedantic -O3)
elseif(CMAKE_COMPILER_D STREQUAL "MSVC")
    target_compile_options(DoublyList PRIVATE /W4 /permissive- /O2)
endif()
