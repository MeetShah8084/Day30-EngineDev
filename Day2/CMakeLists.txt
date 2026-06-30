cmake_minimum_required(VERSION 3.27)
project(Day2 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(librarySystem SHARED src/book.cpp)
target_include_directories(librarySystem PUBLIC ${CMAKE_SOURCE_DIR}/include/)

add_executable(Day2 src/main.cpp)
target_include_directories(Day2 PRIVATE ${CMAKE_SOURCE_DIR}/include/)
target_link_libraries(Day2 PRIVATE librarySystem)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(Day2 PRIVATE -Wall -Wextra -pedantic)

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(Day2 PRIVATE /W4 /permissive-)
endif()
